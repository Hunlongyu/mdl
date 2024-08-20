#pragma once

#include "base.h"

class LuxStrategy : public DownloadStrategy
{
  public:
    LuxStrategy()
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

    ~LuxStrategy()
    {
    }
};