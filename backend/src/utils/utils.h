#pragma once

#include "../engine/downloader.h"

std::string getVideoInfo(const std::string &url)
{
    Downloader dl;
    dl.setStrategy(std::make_unique<YtdlStrategy>());
    const auto info = dl.fetchVideoInfo(url);
    return info;
}