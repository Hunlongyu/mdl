#include "json.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <shlobj_core.h> // For SHGetKnownFolderPath
#include <stdexcept>
#include <string>
#include <windows.h>

using json = nlohmann::json;

class Config
{
  public:
    static Config &getInstance(const std::string &configFilePath = getDefaultConfigFilePath())
    {
        static Config instance(configFilePath);
        static std::once_flag initFlag;
        std::call_once(initFlag, &Config::initialize, &instance);
        return instance;
    }

    Config(const Config &) = delete;
    Config &operator=(const Config &) = delete;

    // 读取配置项
    std::string get(const std::string &section, const std::string &key)
    {
        std::lock_guard<std::mutex> lock(mutex);
        try
        {
            return jsonConfig.at(section).at(key).get<std::string>();
        }
        catch (const std::exception &e)
        {
            // 可以在这里添加日志记录
            return "";
        }
    }

    // 设置配置项
    void set(const std::string &section, const std::string &key, const std::string &value)
    {
        std::lock_guard<std::mutex> lock(mutex);
        jsonConfig[section][key] = value;
    }

    // 保存配置到文件
    void saveConfig()
    {
        std::lock_guard<std::mutex> lock(mutex);
        try
        {
            std::ofstream file(configFilePath);
            if (file.is_open())
            {
                file << jsonConfig.dump(4);
                file.close();
            }
            else
            {
                throw std::runtime_error("无法打开配置文件进行写入");
            }
        }
        catch (const std::exception &e)
        {
            // 可以在这里添加日志记录
            std::cerr << "保存配置时出错: " << e.what() << std::endl;
        }
    }

  private:
    json jsonConfig;            // JSON 数据结构
    std::string configFilePath; // 配置文件路径
    std::mutex mutex;           // 互斥锁

    // 私有构造函数
    Config(const std::string &path) : configFilePath(path)
    {
        // 构造函数中不做复杂操作
    }

    // 初始化方法
    void initialize()
    {
        try
        {
            if (std::filesystem::exists(configFilePath))
            {
                // 如果配置文件存在，直接加载
                loadConfig();
            }
            else
            {
                // 如果配置文件不存在，先创建目录，然后创建默认配置文件
                std::filesystem::create_directories(std::filesystem::path(configFilePath).parent_path());
                createDefaultConfig();
                // 创建默认配置后保存
                saveConfig();
            }
        }
        catch (const std::exception &e)
        {
            // 可以在这里添加日志记录
            std::cerr << "初始化配置时出错: " << e.what() << std::endl;
        }
    }

    // 获取默认的配置文件路径
    static std::string getDefaultConfigFilePath()
    {
        return getAppDataPath() + "\\mdl\\conf.json";
    }

    // 获取 AppData 目录路径
    static std::string getAppDataPath()
    {
        PWSTR path = NULL;
        HRESULT hr = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
        if (SUCCEEDED(hr))
        {
            std::wstring ws(path);
            CoTaskMemFree(path);
            return wstringToString(ws);
        }
        throw std::runtime_error("获取 AppData 路径失败");
    }

    // 将 std::wstring 转换为 std::string
    static std::string wstringToString(const std::wstring &wstr)
    {
        if (wstr.empty())
        {
            return "";
        }
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
        std::string str(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
        return str;
    }

    // 加载配置文件
    void loadConfig()
    {
        std::lock_guard<std::mutex> lock(mutex);
        try
        {
            std::ifstream file(configFilePath);
            if (file.is_open())
            {
                file >> jsonConfig;
                file.close();
            }
            else
            {
                throw std::runtime_error("无法读取配置文件：" + configFilePath);
            }
        }
        catch (const std::exception &e)
        {
            // 可以在这里添加日志记录
            std::cerr << "加载配置时出错: " << e.what() << std::endl;
        }
    }

    // 创建默认配置文件
    void createDefaultConfig()
    {
        std::lock_guard<std::mutex> lock(mutex);
        jsonConfig["system"]["os"] = "windows";
        jsonConfig["system"]["arch"] = "x64";
    }
};
