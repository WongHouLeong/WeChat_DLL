#pragma once
#include <Windows.h>
#include <iostream>
class Console
{
public:
	static void DbgPrintf(const char* cStr, ...);
};
class UtilityLib
{
public:
	bool ReadProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
	bool WriteProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPCVOID lpBuffer, SIZE_T nSize);
	bool InlineHook(HANDLE hProcess, DWORD dwHookAddress, LPCVOID pFuncAddress);
};
