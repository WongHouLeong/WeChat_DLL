#include "UtilityLib.h"


bool HookLib::Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	if (g_bIsInstalled == true)
	{
		StringLib::DbgPrintf("Hook�Ѱ�װ�������Uninstallж��ԭ��Hook������ʵ����");
		return false;
	}
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_pFuncAddress = pFuncAddress;
	memset(g_ucRecoverCode, 0x90, 100); //g_ucRecoverCode���ڴ�ű�HOOK����ԭ�ֽڣ��Ƚ�����������nop���Ժ��ٸ�ֵ
	if (g_dwHookSize < 6)
	{
		StringLib::DbgPrintf("Hook������Ҫ6λ�ֽڳ��ȣ�");
		return false;
	}
	if (g_dwHookSize > 50)
	{
		StringLib::DbgPrintf("Hook���Ȳ��ܳ���50��");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(g_hProcess, g_dwHookAddress, &g_ucRecoverCode, g_dwHookSize)) //��ȡHOOKλ���ڴ棬����ԭ�ֽڵ�g_ucRecoverCode
	{
		char szResult[4096]{ 0 };
		StringLib::HexArr2Str(g_ucRecoverCode, g_dwHookSize, szResult, sizeof(szResult)); //��ӡ�鿴�ֽ�����
		StringLib::DbgPrintf("Hook��ַ��0x%08X��ԭ���ݣ�%s", g_dwHookAddress, szResult);
	}
	else
	{
		StringLib::DbgPrintf("��ȡHookλ���ڴ�ʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
#pragma region Hook����
	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//���� FF 25 ������ת -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFuncAddr = (DWORD)g_pFuncAddress; //����ȫ�ֱ��������ַ�����⺯���˳������٣�ȡHOOK���CALL�ĵ�ַ
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFuncAddr;//����[0x000000]���൱���������ޣ�����д���ڴ�ȥ���ò���ȫ������ν
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//�޸�HOOK�������ת����,�ڵڶ�λ��ʼ,����Ϊ4,�����������
	memset(ucHookCode + 6, 0x90, g_dwHookSize - 6);//ʣ�೤����0x90(nop)����
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &ucHookCode, g_dwHookSize)) //д��HOOK���
	{
		StringLib::DbgPrintf("д��Hookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
#pragma endregion
	dwRecoverAddr = (DWORD)&g_ucRecoverCode; //����ȫ�ֱ���������ASM��ת���ָ���
#pragma region �ָ�����
	unsigned char ucJmpUserCode[6] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//���� FF 25 ������ת -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwUserCodeAddr = g_dwHookAddress + g_dwHookSize; //ȫ�ֱ��������ַ�����⺯���˳������٣������û�Hook�Ĵ��볤�ȣ���������뷵��λ��
	DWORD pUserCodeAddr = (DWORD)&g_dwUserCodeAddr;//����[0x000000]���൱���������ޣ�����д���ڴ�ȥ���ò���ȫ������ν
	memcpy_s(&ucJmpUserCode[2], sizeof(DWORD), &pUserCodeAddr, sizeof(DWORD));//�޸�HOOK�������ת����,�ڵڶ�λ��ʼ,����Ϊ4,�����������
	memcpy_s(&g_ucRecoverCode[g_dwHookSize], sizeof(ucJmpUserCode), &ucJmpUserCode, sizeof(ucJmpUserCode));//������õ���ת����ŵ��ָ���
#pragma endregion
	g_bIsInstalled = true;
	return true;
}
bool HookLib::Continue()
{
	if (!g_bIsInstalled)
	{
		StringLib::DbgPrintf("�޷����������Ȱ�װHook����");
		return false;
	}
	if (!g_bIsPause)
	{
		StringLib::DbgPrintf("Hook�ѻָ���");
		return true;
	}
	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//���� FF 25 ������ת -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFuncAddr = (DWORD)g_pFuncAddress; //����ȫ�ֱ��������⺯���˳������٣�ȡHOOK���CALL�ĵ�ַ
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFuncAddr;//����[0x000000]���൱����������
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//�޸�HOOK�������ת����,�ڵڶ�λ��ʼ,����Ϊ4,�����������
	memset(ucHookCode + 6, 0x90, g_dwHookSize - 6);//ʣ�೤����0x90(nop)����
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &ucHookCode, g_dwHookSize)) //д��HOOK���
	{
		StringLib::DbgPrintf("д��Hookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	StringLib::DbgPrintf("Hook�ѻָ���");
	g_bIsPause = false;
	return true;
}
bool HookLib::Pause()
{
	if (!g_bIsInstalled)
	{
		StringLib::DbgPrintf("�޷���ͣ�����Ȱ�װHook��");
		return false;
	}
	if (g_bIsPause)
	{
		StringLib::DbgPrintf("Hook����ͣ��");
		return true;
	}
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucRecoverCode, g_dwHookSize))//д���ڴ�
	{
		StringLib::DbgPrintf("��ͣHookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	g_bIsPause = true;
	StringLib::DbgPrintf("Hook����ͣ��");
	return true;
}
bool HookLib::Uninstall()
{
	if (!g_bIsInstalled)
	{
		StringLib::DbgPrintf("Hookδ��װ������ж�أ�");
		return true;
	}
	if (!MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucRecoverCode, g_dwHookSize))//д���ڴ�
	{
		StringLib::DbgPrintf("ж��Hookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	StringLib::DbgPrintf("Hook��ж�أ�");
	g_bIsInstalled = false;
	g_bIsPause = false;
	return true;
}
bool HookLib::IsInstalled()
{
	return g_bIsInstalled;
}
