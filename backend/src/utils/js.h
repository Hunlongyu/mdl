#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "utils.h"
#include "webui.hpp"

// 获取视频信息
inline void jsFetchVideoInfo(webui::window::event *e)
{
    const auto url = e->get_string(0);
    const auto info = getVideoInfo(url);
    e->return_string(info);
}

// 获取剪贴板中的文本
inline void jsGetClipboardText(webui::window::event *e)
{
    if (!OpenClipboard(nullptr))
    {
        return;
    }

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
    {
        CloseClipboard();
        return;
    }

    char *pszText = static_cast<char *>(GlobalLock(hData));
    if (pszText == nullptr)
    {
        CloseClipboard();
        return;
    }
    std::string text(pszText);

    GlobalUnlock(hData);
    CloseClipboard();

    e->return_string(text);
}

inline void initWebUI(webui::window win)
{
    win.bind("jsFetchVideoInfo", jsFetchVideoInfo);
    win.bind("jsGetClipboardText", jsGetClipboardText);
}
