#pragma once
#include <Windows.h>
#include <iostream>
class MemoryLib
{
public:
	static bool ReadProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
	static bool WriteProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPCVOID lpBuffer, SIZE_T nSize);
};
class StringLib
{
public:
	static char* HexArr2Str(const unsigned char pszFormat[], unsigned int uSize);
	static void DbgPrintf(const char* cStr, ...);
};
class HookLib
{
public:
	bool Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress);
	bool Uninstall();
	bool Continue();
	bool Pause();
	bool IsInstalled();
};

