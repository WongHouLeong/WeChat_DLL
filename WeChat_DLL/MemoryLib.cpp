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
bool UtilityLib::InlineHook(HANDLE hProcess, DWORD dwHookAddress, LPCVOID pFuncAddress)
{
	unsigned char ucHookCode[9] = { 0x60,0x9C,0xB8,0x00,0x00,0x00,0x00,0xFF,0xE0 }; //������������Hook ���� > pushad - pushfd - mov eax,0x00000000 - jmp eax������д����̵��ֽ�
	memcpy_s(&ucHookCode[3], sizeof(DWORD), &pFuncAddress, sizeof(DWORD));//�޸�HOOK�������,����תĿ��ĳɵ��Լ��ӳ����ַ->jmp &MyFunc
	return WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, sizeof(ucHookCode)); //д���ڴ�
}
