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
private:
	HANDLE g_hProcess{ 0 };
	DWORD g_dwHookAddress{ 0 };
	DWORD g_dwHookSize{ 0 };
	LPCVOID g_pFuncAddress{ 0 };

	unsigned char g_ucRecoverCode[100]{ 0 };
	DWORD g_pRecoverCodeAddr{ 0 }; //”√”⁄ASM
	DWORD g_dwHookFrameworkAddr{ 0 };
	DWORD g_dwUserCodeAddr{ 0 };
	bool g_bIsInstalled = false;
	bool g_bIsPause = false;
public:
	bool Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress);
	bool Uninstall();
	bool Continue();
	bool Pause();
	bool IsInstalled();
};

