#pragma once

#include "subprocess.h"
#include <functional>
#include <string>

struct VideoInfo
{
    std::string title;         // 视频标题
    std::string ext;           // 视频格式
    std::string thumbnail_url; // 缩略图地址
    int size;                  // 视频大小
    int duration;              // 时长
    int resolution;            // 分辨率
};

struct Progress
{
    float percent;         // 下载进度
    float downloaded_size; // 已下载大小
    float total_size;      // 总大小
    float speed;           // 下载速度
    std::string eta;       // 剩余时间
};

class DownloadStrategy
{
  public:
    virtual std::string fetchVideoInfo(const std::string &url) const = 0;
    virtual void download(const std::string &url) const = 0;
    virtual void download(const std::string &url, std::function<void(const Progress &)>) const = 0;
    virtual ~DownloadStrategy() = default;
};

inline std::vector<const char*> splitCommand(const std::string &cmd) {
    std::istringstream iss(cmd);
    std::vector<std::string> tokens;
    std::string token;

    // 使用字符串流来拆分命令字符串
    while (iss >> std::quoted(token)) {
        tokens.push_back(token);
    }

    // 将 std::string 转换为 const char* 数组
    std::vector<const char*> args;
    for (const auto& t : tokens) {
        args.push_back(t.c_str());
    }
    args.push_back(nullptr); // 以 nullptr 结尾

    return args;
}

inline std::string executeCommand(const std::string &cmd)
{
     auto args = splitCommand(cmd);

    //const char *args[] = {"E:/Hunlongyu/mdl/backend/bin/yt-dlp/yt-dlp.exe", "-j",
    //                      "https://www.bilibili.com/video/BV1iE421F7rs/?spm_id_from=333.1007.tianma.1-1-1.click", nullptr};
    subprocess_s process;
    int result = subprocess_create(args.data(), subprocess_option_combined_stdout_stderr | subprocess_option_inherit_environment, &process);

    if (result != 0)
    {
        throw std::runtime_error("Failed to create subprocess.");
    }

    // 读取命令的输出
    char buffer[8192];
    std::string output;

    for (;;)
    {
        size_t bytes_read = subprocess_read_stdout(&process, buffer, sizeof(buffer));
        if (bytes_read == 0)
        {
            break;
        }
        output.append(buffer, bytes_read);
    }

    // 等待子进程结束并获取退出码
    int proc_rc{-1};
    int exit_code = subprocess_join(&process, &proc_rc);
    subprocess_destroy(&process);

    if (exit_code != 0)
    {
        throw std::runtime_error("Process exited with non-zero status: " + std::to_string(exit_code));
    }
    std::cout << "output length: " << output.length() << std::endl;
    std::cout << "output: " << output << std::endl;
    return output;
}