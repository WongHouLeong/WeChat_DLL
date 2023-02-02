#include "..\UtilityLib\UtilityLib.h"
#include "resource.h"

#define hookAddr 0x401019;
DWORD dwProcessId(0);
HANDLE hProcess(0);
DWORD dwBaseAddress(0);
HookLib Hook;

void __declspec(naked)MyFunc()
{
#pragma region 执行自己的代码
	MessageBoxA(0, "hOOK！", "提示", 0);
	MessageBoxA(0, "hOOKB！", "提示", 0);
	Hook.InlineResume();
#pragma endregion
	__asm//还原现场
	{
		popfd
		popad
	}
	__asm //运行被hook掉的字节码
	{
		push 0x80000301
		push 0x0
	}
	__asm //EIP修复
	{
		jmp Hook.g_dwResumeAddress;
	}
}


INT_PTR CALLBACK DialogFunc(HWND hModule, UINT uType, WPARAM wParam, LPARAM lParam)
{
	switch (uType) {
	case WM_INITDIALOG://对话框初始化事件
	{
		dwProcessId = GetCurrentProcessId(); //获取进程ID
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId); //以全部权限，打开进程，得到进程句柄
		SetDlgItemTextA(hModule, IDC_STATIC1, "Hello World!");
		break;
	}
	case WM_COMMAND: { //触发的组件ID
		switch (wParam)
		{
		case IDOK: { //确认
			if (hProcess != NULL)
				StringLib::DbgPrintf("进程句柄：%X", hProcess);
			dwBaseAddress = hookAddr; //指定HOOK地址
			Hook.InlineHook(hProcess, dwBaseAddress, 12, &MyFunc);
			break;
		}
		case IDCANCEL: {  //取消
			EndDialog(hModule, 0);
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: { //对话框关闭事件
		EndDialog(hModule, 0);
		break;
	}
	default://默认不做任何处理
		break;
	}
	return false;
}
extern "C" _declspec(dllexport) void Test()
{
	//MessageBoxA(0, "Test！", "提示", 0);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DialogBoxParamA(hModule, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &DialogFunc, 0);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

