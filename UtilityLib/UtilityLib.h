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
	DWORD g_dwResumeAddress{ 0 };
	bool InlineHook(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress);
	bool InlineResume();
};

