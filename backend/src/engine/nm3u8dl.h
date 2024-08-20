#pragma once

#include "base.h"

class NM3u8DLStrategy : public DownloadStrategy
{
  public:
    NM3u8DLStrategy()
    {
    }

    std::string fetchVideoInfo(const std::string &url) const override
    {
    }

    void download(const std::string &url) const override
    {
    }

    void download(const std::string &url, std::function<void(const Progress &)>) const override
    {
    }

    ~NM3u8DLStrategy()
    {
    }
};