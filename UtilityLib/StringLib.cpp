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
		sprintf_s(cTmpBuf, "0x%02x", pszFormat[i]); //%02x 表示以16进制的格式输出整bai数类型的数值，输出域宽为2，右对齐，不足的用字符0替代。
		strcat_s(szBuf, uArrSize, cTmpBuf);
	}
	strcat_s(szBuf, uArrSize, "}");
	return szBuf;
}
void Console::DbgPrintf(const char* pszFormat, ...)
{
	char szBuf[4096] = {};
	va_list argList(0); //va_list 用于保存参数
	va_start(argList, pszFormat);//遍历参数列表，并保存至argList
	vsprintf_s(szBuf, pszFormat, argList);//将字符串及参数进行格式化打印至szBuf
	va_end(argList);//检索所有参数后，va_end 将指针重置为 NULL，与va_start成对出现
	strcat_s(szBuf, "\n");
	OutputDebugStringA(szBuf);//输出结果
}