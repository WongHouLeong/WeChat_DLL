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
	memset(g_ucResumeCode, 0x90, 100);//�������ڴ���nop
	if (dwHookSize < 9)
	{
		StringLib::DbgPrintf("Hook��ַλ��������Ҫ9λ���ȣ�");
		return false;
	}
	if (dwHookSize > 100)
	{
		StringLib::DbgPrintf("Hook�ֽڳ��Ȳ��ܳ���100��");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(hProcess, dwHookAddress, &g_ucResumeCode, dwHookSize)) //��ȡ�ڴ�		
	{
		char* tmp = StringLib::HexArr2Str(g_ucResumeCode, dwHookSize);
		StringLib::DbgPrintf("Hook��ַ��%x��Hookԭ���ݣ�%s", dwHookAddress, tmp);
		delete tmp;//��ɾ�������ڴ�й©
	}
	else
	{
		StringLib::DbgPrintf("��ȡHookλ������ʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	
	unsigned char ucHookCode[100] = { 0x60,0x9C,0xB8,0x00,0x00,0x00,0x00,0xFF,0xE0 };//��ֵHook ���� > pushad - pushfd - mov eax,0x00000000 - jmp eax
	memcpy_s(&ucHookCode[3], sizeof(DWORD), &pFuncAddress, sizeof(DWORD));//�޸�HOOK�������,����תĿ��ĳɵ��Լ��ӳ����ַ->jmp &MyFunc
	memset(ucHookCode + 9, 0x90, dwHookSize - 9);//ʣ�೤����0x90(nop)����
	if(MemoryLib::WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize)) //д���ڴ�
		return true;
	else
	{
		StringLib::DbgPrintf("д��Hookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	return false;
}

bool HookLib::InlineResume()
{
	return MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucResumeCode, g_dwHookSize); //д���ڴ�
}
