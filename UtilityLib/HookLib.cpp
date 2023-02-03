#include "UtilityLib.h"
HANDLE g_hProcess{ 0 };
DWORD g_dwHookAddress{ 0 };
DWORD g_dwHookSize{ 0 };
LPCVOID g_pFuncAddress{ 0 };

unsigned char g_ucResumeCode[120]{ 0 };
DWORD g_dwResumeCodeAddr{ 0 };
DWORD g_dwHookFrameworkAddr{ 0 };
void __declspec(naked)HookFramework()
{
	__asm//保存现场
	{
		pushad
		pushfd
	}
	__asm
	{
		call g_pFuncAddress;
	}
	__asm//修复返回位置
	{
		popfd
		popad
		jmp g_dwResumeCodeAddr;
	}
}


bool HookLib::InlineHook(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_pFuncAddress = pFuncAddress;
	memset(g_ucResumeCode, 0x90, 100); //用于存放被HOOK掉的原字节，先将所有内容置ret
	if (dwHookSize < 6)
	{
		StringLib::DbgPrintf("Hook的位置至少需要6位长度！");
		return false;
	}
	if (dwHookSize > 100)
	{
		StringLib::DbgPrintf("Hook字节长度不能超出100！");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(hProcess, dwHookAddress, &g_ucResumeCode, dwHookSize)) //读取内存，保存原字节
	{
		char* tmp = StringLib::HexArr2Str(g_ucResumeCode, dwHookSize); //打印查看字节内容
		StringLib::DbgPrintf("Hook地址：0x%08x，Hook原内容：%s", dwHookAddress, tmp);
		delete tmp;//不删除会有内存泄漏
	}
	else
	{
		StringLib::DbgPrintf("读取Hook位置内容失败，请检查句柄权限！");
		return false;
	}
	//unsigned char g_ucResumeAddr[6] = { 0xFF,0x15,0x00,0x00,0x00,0x00 };
	//memcpy_s(&g_ucResumeAddr[2], sizeof(DWORD), &g_dwResumeCodeAddr, sizeof(DWORD));//修改HOOK代码参数,将跳转目标改成的自己子程序地址->jmp &MyFunc
	//memcpy(&g_ucResumeCode[dwHookSize + 1], g_ucResumeAddr,sizeof(g_ucResumeAddr));

	g_dwResumeCodeAddr = (DWORD)&g_ucResumeCode; //定义全局变量，避免函数退出被销毁，取框架CALL地址
	//DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//构造[0x000000]，相当于套两层娃


	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//构造 FF 25 绝对跳转 -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFrameworkAddr = (DWORD)&HookFramework; //定义全局变量，避免函数退出被销毁，取框架CALL地址
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//构造[0x000000]，相当于套两层娃
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//修改HOOK代码参数,构造完整语句
	memset(ucHookCode + 6, 0x90, dwHookSize - 6);//剩余长度以0x90(nop)补充
	if (MemoryLib::WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize)) //写入内存
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
