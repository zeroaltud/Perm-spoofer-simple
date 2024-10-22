#include "include.hpp"

bool IsProcessRunning(const std::wstring& processName) {
	LPCWSTR name = processName.c_str();

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		std::cerr << "Failed to create process snapshot. Error: " << GetLastError() << std::endl;
		return false;
	}

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &entry)) {
		do {
			if (_wcsicmp(entry.szExeFile, name) == 0) {
				CloseHandle(hSnapshot);
				return true;
			}
		} while (Process32Next(hSnapshot, &entry));
	}

	CloseHandle(hSnapshot);
	return false;
}

void killdbg()
{
	system(skCrypt("taskkill /f /im KsDumperClient.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im KsDumper.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im ProcessHacker.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im idaq.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im idaq64.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Wireshark.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Fiddler.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Xenos64.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Xenos.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Xenos32.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im de4dot.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Cheat Engine.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im cheatengine-x86_64-SSE4-AVX2.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im MugenJinFuu-x86_64-SSE4-AVX2.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im MugenJinFuu-i386.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im cheatengine-i386.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im KsDumper.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im OllyDbg.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im x64dbg.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im x32dbg.exe >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
	system(skCrypt("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Ida64.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im OllyDbg.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Dbg64.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Dbg32.exe >nul 2>&1"));
	system(skCrypt("taskkill /f /im Taskmgr.exe >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
	system(skCrypt("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1"));
}

bool IsAnyProcessRunning(const std::vector<std::wstring>& processNames) {
	for (const auto& processName : processNames) {
		if (IsProcessRunning(processName)) {
			return true;
		}
	}
	return false;
}

int antic() {
	std::vector<std::wstring> processesToTerminate = { L"perfmon.exe" };
	while (true) {
		if (IsAnyProcessRunning(processesToTerminate)) {
			exit(-1); //close our program since you cant end some other processes
		}
		killdbg();
		LPCWSTR windowName = L"x64dbg, OllyDbg, IDA Pro, x64dbg-unsigned, Visual Studio Debugger, LLDB Debugger";
		if (FindWindow(NULL, windowName)) {
			//std::cout << "Debugger detected." << std::endl;
			exit(-1);
		}
		if (IsDebuggerPresent()) {
			//std::cout << "Debugger detected." << std::endl;
			exit(-1);
		}
		SetLastError(0);
		OutputDebugStringA("Hello, debugger");
		if (GetLastError() != 0) {
			//std::cout << "Debugger detected." << std::endl;
			exit(-1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}