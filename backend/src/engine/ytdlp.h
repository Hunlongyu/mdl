#pragma once

#include <array>
#include <cstdio>
#include <memory>
#include <stdexcept>

#include "base.h"
#include "json.hpp"
#include "spdlog/spdlog.h"

using json = nlohmann::json;

class YtdlStrategy : public DownloadStrategy
{
  public:
    YtdlStrategy()
    {
    }

    std::string fetchVideoInfo(const std::string &url) const override
    {
        // std::string cmd = "E:/Hunlongyu/mdl/backend/bin/yt-dlp/yt-dlp.exe -j " + url;
        std::string cmd = "E:/Hunlongyu/mdl/backend/bin/yt-dlp/yt-dlp.exe -j "
                          "https://www.bilibili.com/video/BV1Mz421B7r1/?spm_id_from=333.1007.tianma.5-4-18.click";

        std::string result = executeCommand(cmd);
        json video_array = json::array();
        json audio_array = json::array();
        json subtitle_array = json::array();

        // 解析 JSON 数据
        try
        {
            auto json_data = json::parse(result);
            for (const auto &format : json_data["formats"])
            {
                if (format.contains("video_ext") && format["video_ext"] != "none")
                {
                    int filesize{0};
                    if (format.contains("filesize"))
                    {
                        filesize = !format["filesize"].is_null() ? format["filesize"].get<int>() : 0;
                    }
                    video_array.push_back({{"format_id", format.value("format_id", "")},
                                           {"ext", format.value("ext", "")},
                                           {"resolution", format.value("resolution", "")},
                                           {"filesize", filesize}});
                }

                if (format.contains("audio_ext") && format["audio_ext"] != "none")
                {
                    int filesize{0};
                    if (format.contains("filesize"))
                    {
                        filesize = !format["filesize"].is_null() ? format["filesize"].get<int>() : 0;
                    }
                    audio_array.push_back({{"format_id", format.value("format_id", "")},
                                           {"ext", format.value("ext", "")},
                                           {"filesize", filesize}});
                }
            }
            if (json_data.contains("subtitles"))
            {
                for (const auto &[language, subtitles] : json_data["subtitles"].items())
                {
                    for (const auto &subtitle : subtitles)
                    {
                        subtitle_array.push_back({{"language", language}, {"ext", subtitle.value("ext", "")}});
                    }
                }
            }
            json info = {{"title", json_data.value("title", "")},
                         {"videos", video_array},
                         {"audios", audio_array},
                         {"subtitles", subtitle_array}};
            return info.dump();
        }
        catch (json::parse_error &e)
        {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
        }

        return "";
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