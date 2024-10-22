#include "include.hpp"

void setconsole() {
	while (true)
	{
		SetConsoleTitle(E(L"Zerogravity perm spoofer"));
		Sleep(1000);
		SetConsoleTitle(E(L"made by zerogravity____ with love"));
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}