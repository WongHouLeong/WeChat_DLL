#include "UtilityLib.h"


bool HookLib::Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	if (g_bIsInstalled == true)
	{
		StringLib::DbgPrintf("Hook已安装，请调用Uninstall卸载原有Hook或建立新实例！");
		return false;
	}
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_pFuncAddress = pFuncAddress;
	memset(g_ucRecoverCode, 0x90, 100); //g_ucRecoverCode用于存放被HOOK掉的原字节，先将所有内容置nop，以后再赋值
	if (g_dwHookSize < 6)
	{
		StringLib::DbgPrintf("Hook至少需要6位字节长度！");
		return false;
	}
	if (g_dwHookSize > 50)
	{
		StringLib::DbgPrintf("Hook长度不能超出50！");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(g_hProcess, g_dwHookAddress, &g_ucRecoverCode, g_dwHookSize)) //读取HOOK位置内存，保存原字节到g_ucRecoverCode
	{
		char szResult[4096]{ 0 };
		StringLib::HexArr2Str(g_ucRecoverCode, g_dwHookSize, szResult, sizeof(szResult)); //打印查看字节内容
		StringLib::DbgPrintf("Hook地址：0x%08X，原内容：%s", g_dwHookAddress, szResult);
	}
	else
	{
		StringLib::DbgPrintf("读取Hook位置内存失败，请检查句柄权限！");
		return false;
	}
#pragma region Hook操作
	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//构造 FF 25 绝对跳转 -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFuncAddr = (DWORD)g_pFuncAddress; //定义全局变量保存地址，避免函数退出被销毁，取HOOK框架CALL的地址
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFuncAddr;//构造[0x000000]，相当于套两层娃，这里写到内存去，用不用全局无所谓
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//修改HOOK代码的跳转参数,在第二位开始,长度为4,构造完整语句
	memset(ucHookCode + 6, 0x90, g_dwHookSize - 6);//剩余长度以0x90(nop)补充
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &ucHookCode, g_dwHookSize)) //写入HOOK语句
	{
		StringLib::DbgPrintf("写入Hook失败，请检查句柄权限！");
		return false;
	}
#pragma endregion
	dwRecoverAddr = (DWORD)&g_ucRecoverCode; //定义全局变量，用于ASM跳转到恢复区
#pragma region 恢复操作
	unsigned char ucJmpUserCode[6] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//构造 FF 25 绝对跳转 -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwUserCodeAddr = g_dwHookAddress + g_dwHookSize; //全局变量保存地址，避免函数退出被销毁，计算用户Hook的代码长度，推算出代码返回位置
	DWORD pUserCodeAddr = (DWORD)&g_dwUserCodeAddr;//构造[0x000000]，相当于套两层娃，这里写到内存去，用不用全局无所谓
	memcpy_s(&ucJmpUserCode[2], sizeof(DWORD), &pUserCodeAddr, sizeof(DWORD));//修改HOOK代码的跳转参数,在第二位开始,长度为4,构造完整语句
	memcpy_s(&g_ucRecoverCode[g_dwHookSize], sizeof(ucJmpUserCode), &ucJmpUserCode, sizeof(ucJmpUserCode));//将构造好的跳转代码放到恢复区
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
	g_dwHookFuncAddr = (DWORD)g_pFuncAddress; //定义全局变量，避免函数退出被销毁，取HOOK框架CALL的地址
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFuncAddr;//构造[0x000000]，相当于套两层娃
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
		return true;
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
