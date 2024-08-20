#pragma once

#include "base.h"
#include "lux.h"
#include "nm3u8dl.h"
#include "ytdlp.h"

class Downloader
{
  private:
    std::unique_ptr<DownloadStrategy> strategy;

  public:
    void setStrategy(std::unique_ptr<DownloadStrategy> strategy)
    {
        this->strategy = std::move(strategy);
    }

    void download(const std::string &url) const
    {
        if (strategy)
        {
            strategy->download(url);
        }
    }

    void download(const std::string &url, std::function<void(const Progress &)> progressFn) const
    {
        if (strategy)
        {
            strategy->download(url, progressFn);
        }
    }

    std::string fetchVideoInfo(const std::string &url) const
    {
        if (strategy)
        {
            return strategy->fetchVideoInfo(url);
        }
        else
        {
            return {};
        }
    }
};