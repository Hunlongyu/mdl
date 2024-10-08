﻿#define WIN32_LEAN_AND_MEAN
#include "./config/config.cpp"
#include "./utils/js.h"
#include "./utils/sysinfo.hpp"
#include "./utils/utils.h"
#include "spdlog/spdlog.h"
#include "webui.hpp"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    spdlog::info("welcome to mdl");

    SysInfo sys = getSysInfo();
    std::cout << sys.os << std::endl;
    std::cout << sys.arch << std::endl;

    Config &config = Config::getInstance();
    std::string os = config.get("system", "os");
    std::cout << os << std::endl;

    webui::window m_win;
    m_win.set_size(1080, 720);
    if (m_win.set_root_folder("resources") && m_win.show("index.html"))
    {
        initWebUI(m_win);
        webui::wait();
    }
    webui::clean();
    return 0;
}

#ifdef _WIN32
// Release build
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
                    _In_ int nShowCmd)
{
    return main();
}
#endif