#include "UtilityLib.h"
#include "resource.h"


#define hookAddr 0x401000;
DWORD dwProcessId(0);
HANDLE hProcess(0);
DWORD dwBaseAddress(0);
UtilityLib Lib;
void __declspec(naked)MyFunc()
{
	MessageBoxA(0, "hOOK！", "提示", 0);
	dwBaseAddress = dwBaseAddress + 9;
	__asm//还原现场
	{
		popfd
		popad
	}
	__asm//还原现场
	{
		popfd
		popad
	}
	__asm //EIP修复
	{
		jmp dwBaseAddress  // jmp或ret 退出返回
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

			if (hProcess == NULL)
			{
				MessageBoxA(hModule, "打开进程失败！", "提示", 0);
				break;
			}
			dwBaseAddress = hookAddr; //指定地址
			unsigned char ucReadCode[9] = {};//定义缓冲区，用于保存原字节
			bool bResult = Lib.ReadProcessMemory(hProcess, dwBaseAddress, &ucReadCode, sizeof(ucReadCode)); //读取内存
			if (bResult == false)
			{
				MessageBoxA(hModule, "内存读取失败！", "提示", 0);
				break;
			}

			//Console::WriteLine("AAA,%d", 1, 2, 3);
			Console::DbgPrintf("AAA,%d,%d,%d", 1, 2, 3);

			bResult = Lib.InlineHook(hProcess, dwBaseAddress, &MyFunc); //读取内存
			if (bResult == false)
			{
				MessageBoxA(hModule, "hook失败！", "提示", 0);
				break;
			}
			MessageBoxA(hModule, "okok！", "提示", 0);
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
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

