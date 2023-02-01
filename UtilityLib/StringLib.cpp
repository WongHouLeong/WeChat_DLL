#include "UtilityLib.h"
char* Console::HexArr2Str(const unsigned char pszFormat[], unsigned int uSize)
{
	unsigned int uArrSize = 4096;
	char* szBuf = new char[uArrSize];
	memset(szBuf, 0, uArrSize);
	strcat_s(szBuf, uArrSize, "{");
	for (int i = 0; i < uSize; i++)
	{
		if (i != 0)
			strcat_s(szBuf, uArrSize, ",");
		char cTmpBuf[5];
		sprintf_s(cTmpBuf, "0x%02x", pszFormat[i]); //%02x ��ʾ��16���Ƶĸ�ʽ�����bai�����͵���ֵ��������Ϊ2���Ҷ��룬��������ַ�0�����
		strcat_s(szBuf, uArrSize, cTmpBuf);
	}
	strcat_s(szBuf, uArrSize, "}");
	return szBuf;
}
void Console::DbgPrintf(const char* pszFormat, ...)
{
	char szBuf[4096] = {};
	va_list argList(0); //va_list ���ڱ������
	va_start(argList, pszFormat);//���������б���������argList
	vsprintf_s(szBuf, pszFormat, argList);//���ַ������������и�ʽ����ӡ��szBuf
	va_end(argList);//�������в�����va_end ��ָ������Ϊ NULL����va_start�ɶԳ���
	strcat_s(szBuf, "\n");
	OutputDebugStringA(szBuf);//������
}