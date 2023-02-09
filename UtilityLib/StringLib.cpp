#include "UtilityLib.h"
void StringLib::HexArr2Str(const unsigned char arrHex[], unsigned int unArrSize, char* szBuf, unsigned int unBufSize)
{
	memset(szBuf, 0, unBufSize);
	strcat_s(szBuf, unBufSize, "{");
	for (unsigned int i = 0; i < unArrSize; i++)
	{
		if (i != 0)
			strcat_s(szBuf, unBufSize, ",");
		char cTmpBuf[5];
		sprintf_s(cTmpBuf, "0x%02X", arrHex[i]); //%02x ��ʾ��16���Ƶĸ�ʽ�����bai�����͵���ֵ��������Ϊ2���Ҷ��룬��������ַ�0�����
		strcat_s(szBuf, unBufSize, cTmpBuf);
	}
	strcat_s(szBuf, unBufSize, "}");
}
void StringLib::DbgPrintf(const char* pszFormat, ...)
{
	char szBuf[4096] = "[WeChat] ";
	char szTmp[4096]{ 0 };
	va_list argList(0); //va_list ���ڱ������
	va_start(argList, pszFormat);//���������б���������argList
	vsprintf_s(szTmp, pszFormat, argList);//���ַ������������и�ʽ����ӡ��szBuf
	va_end(argList);//�������в�����va_end ��ָ������Ϊ NULL����va_start�ɶԳ���
	strcat_s(szBuf, szTmp);
	strcat_s(szBuf, "\n");
	OutputDebugStringA(szBuf);//������
}
void StringLib::GetPrintf(const char* pszFormat, char* szBuf, unsigned int unBufSize, ...)
{
	memset(szBuf, 0x0, unBufSize);
	va_list argList(0); //va_list ���ڱ������
	va_start(argList, pszFormat);//���������б���������argList
	vsprintf_s(szBuf, unBufSize, pszFormat, argList);//���ַ������������и�ʽ����ӡ��szBuf
	va_end(argList);//�������в�����va_end ��ָ������Ϊ NULL����va_start�ɶԳ���
	strcat_s(szBuf, unBufSize, "\n");
}
void StringLib::GetFileName(const char* lpFilePath, char* szBuf, unsigned int unBufSize)
{
	memset(szBuf, 0x0, unBufSize);
	char szExtension[_MAX_EXT];
	_splitpath_s(lpFilePath, NULL, 0, NULL, 0, szBuf, unBufSize, szExtension, _MAX_EXT);
	strcat_s(szBuf, unBufSize, szExtension);
}