#include "UtilityLib.h"

HANDLE g_hProcess{ 0 };
DWORD g_dwHookAddress{ 0 };
DWORD g_dwHookSize{ 0 };
unsigned char g_ucResumeCode[100]{ 0 };



bool HookLib::InlineHook(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_dwResumeAddress = dwHookAddress + dwHookSize;
	memset(g_ucResumeCode, 0x90, 100);//将补丁内存置nop
	if (dwHookSize < 9)
	{
		StringLib::DbgPrintf("Hook地址位置至少需要9位长度！");
		return false;
	}
	if (dwHookSize > 100)
	{
		StringLib::DbgPrintf("Hook字节长度不能超出100！");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(hProcess, dwHookAddress, &g_ucResumeCode, dwHookSize)) //读取内存		
	{
		char* tmp = StringLib::HexArr2Str(g_ucResumeCode, dwHookSize);
		StringLib::DbgPrintf("Hook地址：%x，Hook原内容：%s", dwHookAddress, tmp);
		delete tmp;//不删除会有内存泄漏
	}
	else
	{
		StringLib::DbgPrintf("读取Hook位置内容失败，请检查句柄权限！");
		return false;
	}
	
	unsigned char ucHookCode[100] = { 0x60,0x9C,0xB8,0x00,0x00,0x00,0x00,0xFF,0xE0 };//赋值Hook 代码 > pushad - pushfd - mov eax,0x00000000 - jmp eax
	memcpy_s(&ucHookCode[3], sizeof(DWORD), &pFuncAddress, sizeof(DWORD));//修改HOOK代码参数,将跳转目标改成的自己子程序地址->jmp &MyFunc
	memset(ucHookCode + 9, 0x90, dwHookSize - 9);//剩余长度以0x90(nop)补充
	if(MemoryLib::WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize)) //写入内存
		return true;
	else
	{
		StringLib::DbgPrintf("写入Hook失败，请检查句柄权限！");
		return false;
	}
	return false;
}

bool HookLib::InlineResume()
{
	return MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucResumeCode, g_dwHookSize); //写入内存
}
