#include <array>
// #include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "base.h"
#include "json.hpp"

using json = nlohmann::json;

class YtdlStrategy : public DownloadStrategy
{
  public:
    YtdlStrategy()
    {
    }

    VideoInfo fetchVideoInfo(const std::string &url) const override
    {
        VideoInfo info;
        std::string cmd = "E:/Hunlongyu/mdl/backend/bin/yt-dlp/yt-dlp.exe -j" + url;
        std::array<char, 8192> buffer;
        std::string result;

        // 使用 popen 执行命令并获取输出
        /*std::shared_ptr<FILE> pipe(_popen(cmd.c_str(), "r"), _pclose);
        if (!pipe)
        {
            throw std::runtime_error("popen() failed!");
        }*/

        // 读取整个输出
        /*while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        {
            result += buffer.data();
        }*/

        // 解析 JSON 数据
        try
        {
            // auto json_data = json::parse(result);

            //// 填充 VideoInfo 结构体
            // info.title = json_data.value("title", "");
            // info.duration = json_data.value("duration_string", "");
            // info.format = json_data.value("format", "");
            // info.resolution = json_data.value("resolution", "");
            // info.size = json_data.value("filesize", 0);
            // info.thumbnail_url = json_data.value("thumbnail", "");
        }
        catch (json::parse_error &e)
        {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
        }

        return info;
    }

    void download(const std::string &url) const override
    {
    }

    void download(const std::string &url, std::function<void(const Progress &)>) const override
    {
    }

    ~YtdlStrategy()
    {
    }
};