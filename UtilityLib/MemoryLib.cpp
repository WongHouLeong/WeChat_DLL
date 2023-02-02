#include "UtilityLib.h"
bool MemoryLib::ReadProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPVOID lpBuffer, SIZE_T nSize)
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
bool MemoryLib::WriteProcessMemory(HANDLE hProcess, DWORD dwBaseAddress, LPCVOID lpBuffer, SIZE_T nSize)
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
