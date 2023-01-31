#include "UtilityLib.h"
void Console::DbgPrintf(const char* pszFormat, ...)
{
	char szBuf[4096];
	va_list argList; //va_list ���ڱ������
	va_start(argList, pszFormat);//���������б���������argList
	vsprintf_s(szBuf, pszFormat, argList);//���ַ������������и�ʽ����ӡ��szBuf
	va_end(argList);//�������в�����va_end ��ָ������Ϊ NULL����va_start�ɶԳ���
	OutputDebugStringA(szBuf);//������
}