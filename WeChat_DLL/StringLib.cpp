#include "UtilityLib.h"
void Console::DbgPrintf(const char* pszFormat, ...)
{
	char szBuf[4096];
	va_list argList(0); //va_list 用于保存参数
	va_start(argList, pszFormat);//遍历参数列表，并保存至argList
	vsprintf_s(szBuf, pszFormat, argList);//将字符串及参数进行格式化打印至szBuf
	va_end(argList);//检索所有参数后，va_end 将指针重置为 NULL，与va_start成对出现
	strcat_s(szBuf, "\n");
	OutputDebugStringA(szBuf);//输出结果
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