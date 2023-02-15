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
	static void HexArr2Str(const unsigned char arrHex[], unsigned int unArrSize, char* szBuf, unsigned int uBufSize);
	static void DbgPrintf(const char* cStr, ...);
	static void GetPrintf(const char* pszFormat, char* szBuf, unsigned int uSize, ...);
	static void GetFileName(const char* lpFilePath, char* szBuf, unsigned int uSize);
	static void DbgOutPut_W(const wchar_t* szTitle, const wchar_t* szData);
};
class HookLib
{
private:
	HANDLE g_hProcess{ 0 };
	DWORD g_dwHookAddress{ 0 };
	DWORD g_dwHookSize{ 0 };
	LPCVOID g_pFuncAddress{ 0 };
	DWORD g_dwHookFuncAddr{ 0 };
	DWORD g_dwUserCodeAddr{ 0 };
	unsigned char g_ucRecoverCode[100]{ 0 };
	bool g_bIsInstalled = false;
	bool g_bIsPause = false;
public:
	bool Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress);
	bool Uninstall();
	bool Continue();
	bool Pause();
	bool IsInstalled();
	DWORD dwRecoverAddr{ 0 }; //用于ASM跳转到类内函数
};
class EnCodeLib
{
public:
	static void UTF8_to_ANSI(char* szU8, char* szBuf, unsigned int unBufSize);
};
