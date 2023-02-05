#include "..\UtilityLib\UtilityLib.h"
#include "resource.h"

#define hookAddr 0x40101E;
HANDLE hProcess(0);
HookLib Hook;

void __declspec(naked)HookFramework()
{
	__asm//保存现场
	{
		pushad
		pushfd
	}
	MessageBoxA(0, "Hook！", "提示", 0);
	__asm//恢复现场+跳转修复
	{
		popfd
		popad
		jmp Hook.dwRecoverAddr; //跳到恢复区
	}
}


INT_PTR CALLBACK DialogFunc(HWND hModule, UINT uType, WPARAM wParam, LPARAM lParam)
{
	switch (uType) {
	case WM_INITDIALOG://对话框初始化事件
	{
		DWORD dwProcessId = GetCurrentProcessId(); //获取进程ID
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId); //以全部权限，打开进程，得到进程句柄
		if (hProcess != NULL)
			StringLib::DbgPrintf("进程句柄：%d", hProcess);
		SetDlgItemTextA(hModule, IDC_STATIC1, "Hello World!");
		break;
	}
	case WM_COMMAND: { //触发的组件ID
		switch (wParam)
		{
		case IDOK: { //确认
			DWORD dwBaseAddress = hookAddr; //指定HOOK地址
			Hook.Install(hProcess, dwBaseAddress, 7, &HookFramework);
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

