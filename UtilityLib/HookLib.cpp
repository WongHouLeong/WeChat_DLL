#include "UtilityLib.h"

HANDLE g_hProcess{ 0 };
DWORD g_dwHookAddress{ 0 };
DWORD g_dwHookSize{ 0 };
LPCVOID g_pFuncAddress{ 0 };

unsigned char g_ucRecoverCode[100]{ 0 };
DWORD g_pRecoverCodeAddr{ 0 }; //����ASM
DWORD g_dwHookFrameworkAddr{ 0 };
DWORD g_dwUserCodeAddr{ 0 };
bool g_bIsInstalled = false;
bool g_bIsPause = false;

void __declspec(naked)HookFramework()
{
	__asm//�����ֳ�
	{
		pushad
		pushfd
	}
	__asm
	{
		call g_pFuncAddress;
	}
	__asm//�޸�����λ��
	{
		popfd
		popad
		jmp g_pRecoverCodeAddr; //�����ָ���
	}
}


bool HookLib::Install(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	if (g_bIsInstalled == true)
	{
		StringLib::DbgPrintf("Hook�Ѱ�װ�������Uninstallж��ԭ��Hook��");
		return false;
	}
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_pFuncAddress = pFuncAddress;
	memset(g_ucRecoverCode, 0x90, 100); //���ڴ�ű�HOOK����ԭ�ֽڣ��Ƚ�����������nop
	if (dwHookSize < 6)
	{
		StringLib::DbgPrintf("Hook������Ҫ6λ�ֽڳ��ȣ�");
		return false;
	}
	if (dwHookSize > 50)
	{
		StringLib::DbgPrintf("Hook���Ȳ��ܳ���50��");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(hProcess, dwHookAddress, &g_ucRecoverCode, dwHookSize)) //��ȡHOOKλ���ڴ棬����ԭ�ֽڵ�g_ucRecoverCode
	{
		char* tmp = StringLib::HexArr2Str(g_ucRecoverCode, dwHookSize); //��ӡ�鿴�ֽ�����
		StringLib::DbgPrintf("Hook��ַ��0x%08X��ԭ���ݣ�%s", dwHookAddress, tmp);
		delete tmp;//��ɾ�������ڴ�й©
	}
	else
	{
		StringLib::DbgPrintf("��ȡHookλ���ڴ�ʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
#pragma region Hook����
	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//���� FF 25 ������ת -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFrameworkAddr = (DWORD)&HookFramework; //����ȫ�ֱ��������⺯���˳������٣�ȡHOOK���CALL�ĵ�ַ
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//����[0x000000]���൱����������
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//�޸�HOOK�������ת����,�ڵڶ�λ��ʼ,����Ϊ4,�����������
	memset(ucHookCode + 6, 0x90, dwHookSize - 6);//ʣ�೤����0x90(nop)����
	if (!MemoryLib::WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize)) //д��HOOK���
	{
		StringLib::DbgPrintf("д��Hookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
#pragma endregion
	g_pRecoverCodeAddr = (DWORD)&g_ucRecoverCode; //����ȫ�ֱ���������ASM��ת���ָ���
#pragma region �ָ�����
	unsigned char ucJmpUserCode[6] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//���� FF 25 ������ת -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwUserCodeAddr = dwHookAddress + dwHookSize; //�����û�Hook�Ĵ��볤�ȣ���������뷵��λ��
	DWORD pUserCodeAddr = (DWORD)&g_dwUserCodeAddr;//����[0x000000]���൱����������
	memcpy_s(&ucJmpUserCode[2], sizeof(DWORD), &pUserCodeAddr, sizeof(DWORD));//�޸�HOOK�������ת����,�ڵڶ�λ��ʼ,����Ϊ4,�����������
	memcpy_s(&g_ucRecoverCode[dwHookSize], sizeof(ucJmpUserCode), &ucJmpUserCode, sizeof(ucJmpUserCode));//������õ���ת����ŵ��ָ���
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
	g_dwHookFrameworkAddr = (DWORD)&HookFramework; //����ȫ�ֱ��������⺯���˳������٣�ȡHOOK���CALL�ĵ�ַ
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//����[0x000000]���൱����������
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
		return false;
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
