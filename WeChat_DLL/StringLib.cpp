#include "UtilityLib.h"
void Console::DbgPrintf(const char* pszFormat, ...)
{
	char szBuf[4096];
	va_list argList(0); //va_list ���ڱ������
	va_start(argList, pszFormat);//���������б���������argList
	vsprintf_s(szBuf, pszFormat, argList);//���ַ������������и�ʽ����ӡ��szBuf
	va_end(argList);//�������в�����va_end ��ָ������Ϊ NULL����va_start�ɶԳ���
	strcat_s(szBuf, "\n");
	OutputDebugStringA(szBuf);//������
}

char* Console::GetHexArry(const unsigned char* pszFormat, unsigned int uSize)
{
	char szBuf[4096] = { '{' };
	for (int i = 0; i < uSize; i++)
	{
		if (i != 0)
			strcat_s(szBuf, ",");
		char cTmpBuf[5];
		sprintf_s(cTmpBuf, "0x%X", pszFormat[i]);
		strcat_s(szBuf, cTmpBuf);
	}
	strcat_s(szBuf, "}");
	strcat_s(szBuf, "\n");
	return szBuf;
}