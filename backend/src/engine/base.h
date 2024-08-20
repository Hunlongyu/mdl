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
    virtual VideoInfo fetchVideoInfo(const std::string &url) const = 0;
    virtual void download(const std::string &url) const = 0;
    virtual void download(const std::string &url, std::function<void(const Progress &)>) const = 0;
    virtual ~DownloadStrategy() = default;
};