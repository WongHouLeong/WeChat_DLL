#include "UtilityLib.h"

HANDLE g_hProcess{ 0 };
DWORD g_dwHookAddress{ 0 };
DWORD g_dwHookSize{ 0 };
LPCVOID g_pFuncAddress{ 0 };

unsigned char g_ucRecoverCode[100]{ 0 };
DWORD g_pRecoverCodeAddr{ 0 }; //用于ASM
DWORD g_dwHookFrameworkAddr{ 0 };
DWORD g_dwUserCodeAddr{ 0 };
bool g_bIsInstalled = false;
bool g_bIsPause = false;

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
		jmp g_pRecoverCodeAddr; //跳到恢复区
	}
}


bool HookLib::Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	if (g_bIsInstalled == true)
	{
		StringLib::DbgPrintf("Hook已安装，请调用Uninstall卸载原有Hook！");
		return false;
	}
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_pFuncAddress = pFuncAddress;
	memset(g_ucRecoverCode, 0x90, 100); //用于存放被HOOK掉的原字节，先将所有内容置nop
	if (dwHookSize < 6)
	{
		StringLib::DbgPrintf("Hook至少需要6位字节长度！");
		return false;
	}
	if (dwHookSize > 50)
	{
		StringLib::DbgPrintf("Hook长度不能超出50！");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(hProcess, dwHookAddress, &g_ucRecoverCode, dwHookSize)) //读取HOOK位置内存，保存原字节到g_ucRecoverCode
	{
		char* tmp = StringLib::HexArr2Str(g_ucRecoverCode, dwHookSize); //打印查看字节内容
		StringLib::DbgPrintf("Hook地址：0x%08X，原内容：%s", dwHookAddress, tmp);
		delete tmp;//不删除会有内存泄漏
	}
	else
	{
		StringLib::DbgPrintf("读取Hook位置内存失败，请检查句柄权限！");
		return false;
	}
#pragma region Hook操作
	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//构造 FF 25 绝对跳转 -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFrameworkAddr = (DWORD)&HookFramework; //定义全局变量，避免函数退出被销毁，取HOOK框架CALL的地址
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//构造[0x000000]，相当于套两层娃
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//修改HOOK代码的跳转参数,在第二位开始,长度为4,构造完整语句
	memset(ucHookCode + 6, 0x90, dwHookSize - 6);//剩余长度以0x90(nop)补充
	if (!MemoryLib::WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize)) //写入HOOK语句
	{
		StringLib::DbgPrintf("写入Hook失败，请检查句柄权限！");
		return false;
	}
#pragma endregion
	g_pRecoverCodeAddr = (DWORD)&g_ucRecoverCode; //定义全局变量，用于ASM跳转到恢复区
#pragma region 恢复操作
	unsigned char ucJmpUserCode[6] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//构造 FF 25 绝对跳转 -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwUserCodeAddr = dwHookAddress + dwHookSize; //计算用户Hook的代码长度，推算出代码返回位置
	DWORD pUserCodeAddr = (DWORD)&g_dwUserCodeAddr;//构造[0x000000]，相当于套两层娃
	memcpy_s(&ucJmpUserCode[2], sizeof(DWORD), &pUserCodeAddr, sizeof(DWORD));//修改HOOK代码的跳转参数,在第二位开始,长度为4,构造完整语句
	memcpy_s(&g_ucRecoverCode[dwHookSize], sizeof(ucJmpUserCode), &ucJmpUserCode, sizeof(ucJmpUserCode));//将构造好的跳转代码放到恢复区
#pragma endregion
	g_bIsInstalled = true;
	return true;
}

bool HookLib::Continue()
{
	if (!g_bIsInstalled)
	{
		StringLib::DbgPrintf("无法继续，请先安装Hook！！");
		return false;
	}
	if (!g_bIsPause)
	{
		StringLib::DbgPrintf("Hook已恢复！");
		return true;
	}
	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//构造 FF 25 绝对跳转 -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFrameworkAddr = (DWORD)&HookFramework; //定义全局变量，避免函数退出被销毁，取HOOK框架CALL的地址
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//构造[0x000000]，相当于套两层娃
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//修改HOOK代码的跳转参数,在第二位开始,长度为4,构造完整语句
	memset(ucHookCode + 6, 0x90, g_dwHookSize - 6);//剩余长度以0x90(nop)补充
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &ucHookCode, g_dwHookSize)) //写入HOOK语句
	{
		StringLib::DbgPrintf("写入Hook失败，请检查句柄权限！");
		return false;
	}
	StringLib::DbgPrintf("Hook已恢复！");
	g_bIsPause = false;
	return true;
}

bool HookLib::Pause()
{
	if (!g_bIsInstalled)
	{
		StringLib::DbgPrintf("无法暂停，请先安装Hook！");
		return false;
	}
	if (g_bIsPause)
	{
		StringLib::DbgPrintf("Hook已暂停！");
		return true;
	}
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucRecoverCode, g_dwHookSize))//写入内存
	{
		StringLib::DbgPrintf("暂停Hook失败，请检查句柄权限！");
		return false;
	}
	g_bIsPause = true;
	StringLib::DbgPrintf("Hook已暂停！");
	return true;
}



bool HookLib::Uninstall()
{
	if (!g_bIsInstalled)
	{
		StringLib::DbgPrintf("Hook未安装，无需卸载！");
		return false;
	}
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucRecoverCode, g_dwHookSize))//写入内存
	{
		StringLib::DbgPrintf("卸载Hook失败，请检查句柄权限！");
		return false;
	}
	StringLib::DbgPrintf("Hook已卸载！");
	g_bIsInstalled = false;
	g_bIsPause = false;
	return true;
}

bool HookLib::IsInstalled()
{
	return g_bIsInstalled;
}
