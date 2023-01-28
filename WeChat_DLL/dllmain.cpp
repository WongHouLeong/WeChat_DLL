#include <Windows.h>
#include "resource.h"

#define hookAddr 0x401000;
DWORD dwProcessId(0);
HANDLE hProcess(0);
DWORD dwBaseAddress(0);
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
			DWORD dwNumberOfBytesRead(0);//用于获取成功读取字节的数量
			DWORD dwOldProtect(0);//用于保存修改前的内存属性
			VirtualProtect((LPVOID)dwBaseAddress, sizeof(ucReadCode), PAGE_EXECUTE_READWRITE, &dwOldProtect);//修改内存属性，避免内存保护出现读写问题
			bool bResult = ReadProcessMemory(hProcess, (LPCVOID)dwBaseAddress, &ucReadCode, sizeof(ucReadCode), &dwNumberOfBytesRead); //读取内存
			if (bResult == false || dwNumberOfBytesRead != sizeof(ucReadCode))
			{
				MessageBoxA(hModule, "内存读取失败！", "提示", 0);
				break;
			}
			OutputDebugStringA("内存读取ok");	//保存了原字节,开始写hook
			unsigned char ucHookCode[9] = { 0x60,0x9C,0xB8,0x00,0x00,0x00,0x00,0xFF,0xE0 }; //缓冲区，定义Hook 代码 > pushad - pushfd - mov eax,0x00000000 - jmp eax，即将写入进程的字节
			DWORD dwMyFunc = (DWORD)&MyFunc; //取要跳转去的子程序地址
			memcpy_s(&ucHookCode[3], sizeof(DWORD), &dwMyFunc, sizeof(dwMyFunc));//修改HOOK代码参数,将跳转目标改成的自己子程序地址->jmp &MyFunc
			DWORD dwNumberOfBytesWritten(0);//用于获取成功写入字节的数量
			bResult = WriteProcessMemory(hProcess, (LPVOID)dwBaseAddress, &ucHookCode, sizeof(ucHookCode), &dwNumberOfBytesWritten); //写入内存
			VirtualProtect((LPVOID)dwBaseAddress, sizeof(ucHookCode), dwOldProtect, &dwOldProtect);//恢复旧内存属性
			if (bResult == false || dwNumberOfBytesWritten != sizeof(ucHookCode))
			{
				MessageBoxA(hModule, "内存写入失败！", "提示", 0);
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

