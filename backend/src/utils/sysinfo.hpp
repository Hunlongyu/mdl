#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>  // For std::unique_ptr
#include <array>   // For std::array

#if defined(_WIN32) || defined(__MINGW32__) || defined(__CYGWIN__)
#include <windows.h>
#include <intrin.h>
#endif

struct SysInfo {
	std::string os;
	std::string arch;
};

// Helper function to execute system commands and retrieve output
std::string execCommand(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;

	// Handle popen and pclose differences across platforms
#if defined(_WIN32) || defined(__MINGW32__) || defined(__CYGWIN__)
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
#else
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
#endif

	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}

	// Read the output into the result string
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}

	// Remove trailing newline and spaces
	result.erase(result.find_last_not_of(" \n\r\t") + 1);

	return result;
}

SysInfo getSysInfo() {
	SysInfo sys;

#if defined(_WIN32) || defined(__MINGW32__) || defined(__CYGWIN__)
	sys.os = "Windows";
	SYSTEM_INFO sysInfo;
	GetNativeSystemInfo(&sysInfo);

	// Determine architecture
	switch (sysInfo.wProcessorArchitecture) {
	case PROCESSOR_ARCHITECTURE_AMD64:
		sys.arch = "x64 (64-bit)";
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		sys.arch = "x86 (32-bit)";
		break;
	case PROCESSOR_ARCHITECTURE_ARM64:
		sys.arch = "ARM64";
		break;
	default:
		sys.arch = "Unknown Architecture";
		break;
	}

#elif defined(__linux__)
	sys.os = "Linux";
	try {
		sys.arch = execCommand("uname -m");
	}
	catch (const std::runtime_error& e) {
		sys.arch = "Unknown Architecture";
	}

#elif defined(__APPLE__)
	sys.os = "Apple";
	try {
		sys.arch = execCommand("uname -m");
	}
	catch (const std::runtime_error& e) {
		sys.arch = "Unknown Architecture";
	}

#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
	sys.os = "BSD";
	try {
		sys.arch = execCommand("uname -m");
	}
	catch (const std::runtime_error& e) {
		sys.arch = "Unknown Architecture";
	}

#else
	sys.os = "Unknown OS";
	sys.arch = "Unknown Architecture";

#endif

	return sys;
}
