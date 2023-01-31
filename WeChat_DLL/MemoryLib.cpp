#include "UtilityLib.h"


bool UtilityLib::ReadProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPVOID lpBuffer, SIZE_T nSize)
{
	DWORD dwOldProtect(0); //用于备份原有的内存属性
	SIZE_T dwNumberOfBytesRead(0); //用于获取成功读取字节的数量
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);//修改内存属性，避免内存保护出现读写问题
	bool bResult = ::ReadProcessMemory(hProcess, (LPCVOID)dwBaseAddress, lpBuffer, nSize, &dwNumberOfBytesRead); //读取内存
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, dwOldProtect, &dwOldProtect);//恢复旧内存属性
	if (bResult == false || dwNumberOfBytesRead != nSize)//检查返回值，检查读取长度是否一致
		return false;
	return true;
}
bool UtilityLib::WriteProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPCVOID lpBuffer, SIZE_T nSize)
{
	DWORD dwOldProtect(0); //用于备份原有的内存属性
	SIZE_T dwNumberOfBytesWritten(0); //用于获取成功写入字节的数量
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);//修改内存属性，避免内存保护出现读写问题
	bool bResult = ::WriteProcessMemory(hProcess, (LPVOID)dwBaseAddress, lpBuffer, nSize, &dwNumberOfBytesWritten); //读取内存
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, dwOldProtect, &dwOldProtect);//恢复旧内存属性
	if (bResult == false || dwNumberOfBytesWritten != nSize)//检查返回值，检查读取长度是否一致
		return false;
	return true;
}
bool UtilityLib::InlineHook(HANDLE hProcess, DWORD dwHookAddress, LPCVOID pFuncAddress)
{
	unsigned char ucHookCode[9] = { 0x60,0x9C,0xB8,0x00,0x00,0x00,0x00,0xFF,0xE0 }; //缓冲区，定义Hook 代码 > pushad - pushfd - mov eax,0x00000000 - jmp eax，即将写入进程的字节
	memcpy_s(&ucHookCode[3], sizeof(DWORD), &pFuncAddress, sizeof(DWORD));//修改HOOK代码参数,将跳转目标改成的自己子程序地址->jmp &MyFunc
	return WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, sizeof(ucHookCode)); //写入内存
}
