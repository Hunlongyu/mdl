﻿#include "webui.hpp"
#include "./utils/sysinfo.hpp"
#include "./config/config.cpp"
#include <iostream>

int main()
{
	SysInfo sys = getSysInfo();
	std::cout << sys.os << std::endl;
	std::cout << sys.arch << std::endl;

	Config& config = Config::getInstance();
	std::string os = config.get("system", "os");
	std::cout << os << std::endl;

	webui::window m_win;
	m_win.set_size(1080, 720);
	if (m_win.show("resources/index.html"))
	{
		webui::wait();
	}
	return 0;
}

#ifdef _WIN32
// Release build
int WINAPI
wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd) {
	return main();
}
#endif