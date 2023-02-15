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


void StringLib::DbgOutPut_W(const wchar_t* szTitle,const wchar_t* szData)
{
	wchar_t szHead[] = L"[WeChat] ";
	//wchar_t szEnd[] = L"";
	unsigned int uStrLen = wcslen(szData);
	//unsigned int uBufLen = uStrLen + wcslen(szHead) + wcslen(szTitle) + wcslen(szEnd) +1;//+1��Ϊ�˽�β��\0
	unsigned int uBufLen = uStrLen + wcslen(szHead) + wcslen(szTitle) + 1;//+1��Ϊ�˽�β��\0
	wchar_t* szBuf = new wchar_t[uBufLen];
	memset(szBuf, 0x0, uBufLen* sizeof(wchar_t));
	wcscat_s(szBuf, uBufLen, szHead);
	wcscat_s(szBuf, uBufLen, szTitle);
	memcpy_s(&szBuf[wcslen(szHead)+ wcslen(szTitle)], uBufLen * sizeof(wchar_t), szData, uStrLen* sizeof(wchar_t)+2);//+2��Ϊ�˰�\0Ҳ������
	//wcscat_s(szBuf, uBufLen , szEnd);
	OutputDebugStringW(szBuf);
	delete[] szBuf;
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