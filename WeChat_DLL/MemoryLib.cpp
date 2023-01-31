#include "UtilityLib.h"


bool UtilityLib::ReadProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPVOID lpBuffer, SIZE_T nSize)
{
	DWORD dwOldProtect(0); //���ڱ���ԭ�е��ڴ�����
	SIZE_T dwNumberOfBytesRead(0); //���ڻ�ȡ�ɹ���ȡ�ֽڵ�����
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);//�޸��ڴ����ԣ������ڴ汣�����ֶ�д����
	bool bResult = ::ReadProcessMemory(hProcess, (LPCVOID)dwBaseAddress, lpBuffer, nSize, &dwNumberOfBytesRead); //��ȡ�ڴ�
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, dwOldProtect, &dwOldProtect);//�ָ����ڴ�����
	if (bResult == false || dwNumberOfBytesRead != nSize)//��鷵��ֵ������ȡ�����Ƿ�һ��
		return false;
	return true;
}
bool UtilityLib::WriteProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPCVOID lpBuffer, SIZE_T nSize)
{
	DWORD dwOldProtect(0); //���ڱ���ԭ�е��ڴ�����
	SIZE_T dwNumberOfBytesWritten(0); //���ڻ�ȡ�ɹ�д���ֽڵ�����
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);//�޸��ڴ����ԣ������ڴ汣�����ֶ�д����
	bool bResult = ::WriteProcessMemory(hProcess, (LPVOID)dwBaseAddress, lpBuffer, nSize, &dwNumberOfBytesWritten); //��ȡ�ڴ�
	VirtualProtectEx(hProcess, (LPVOID)dwBaseAddress, nSize, dwOldProtect, &dwOldProtect);//�ָ����ڴ�����
	if (bResult == false || dwNumberOfBytesWritten != nSize)//��鷵��ֵ������ȡ�����Ƿ�һ��
		return false;
	return true;
}
bool UtilityLib::InlineHook(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	if (dwHookSize <= 9) dwHookSize = 9;//hook����������Ҫ9λ����
	if (dwHookSize >= 1024) dwHookSize = 1024;//�ռ�Ԥ����һ��hook����50����
	unsigned char ucHookCode[1024] = { 0x60,0x9C,0xB8,0x00,0x00,0x00,0x00,0xFF,0xE0 };//��ֵHook ���� > pushad - pushfd - mov eax,0x00000000 - jmp eax
	memcpy_s(&ucHookCode[3], sizeof(DWORD), &pFuncAddress, sizeof(DWORD));//�޸�HOOK�������,����תĿ��ĳɵ��Լ��ӳ����ַ->jmp &MyFunc
	memset(ucHookCode + 9, 0x90, dwHookSize - 9);//ʣ�೤����0x90(nop)����
	return WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize); //д���ڴ�
}
