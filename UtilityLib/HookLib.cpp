#include "UtilityLib.h"
HANDLE g_hProcess{ 0 };
DWORD g_dwHookAddress{ 0 };
DWORD g_dwHookSize{ 0 };
LPCVOID g_pFuncAddress{ 0 };

unsigned char g_ucResumeCode[120]{ 0 };
DWORD g_dwResumeCodeAddr{ 0 };
DWORD g_dwHookFrameworkAddr{ 0 };
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
		jmp g_dwResumeCodeAddr;
	}
}


bool HookLib::InlineHook(HANDLE hProcess, DWORD dwHookAddress, DWORD dwHookSize, LPCVOID pFuncAddress)
{
	g_hProcess = hProcess;
	g_dwHookAddress = dwHookAddress;
	g_dwHookSize = dwHookSize;
	g_pFuncAddress = pFuncAddress;
	memset(g_ucResumeCode, 0x90, 100); //���ڴ�ű�HOOK����ԭ�ֽڣ��Ƚ�����������ret
	if (dwHookSize < 6)
	{
		StringLib::DbgPrintf("Hook��λ��������Ҫ6λ���ȣ�");
		return false;
	}
	if (dwHookSize > 100)
	{
		StringLib::DbgPrintf("Hook�ֽڳ��Ȳ��ܳ���100��");
		return false;
	}
	if (MemoryLib::ReadProcessMemory(hProcess, dwHookAddress, &g_ucResumeCode, dwHookSize)) //��ȡ�ڴ棬����ԭ�ֽ�
	{
		char* tmp = StringLib::HexArr2Str(g_ucResumeCode, dwHookSize); //��ӡ�鿴�ֽ�����
		StringLib::DbgPrintf("Hook��ַ��0x%08x��Hookԭ���ݣ�%s", dwHookAddress, tmp);
		delete tmp;//��ɾ�������ڴ�й©
	}
	else
	{
		StringLib::DbgPrintf("��ȡHookλ������ʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	//unsigned char g_ucResumeAddr[6] = { 0xFF,0x15,0x00,0x00,0x00,0x00 };
	//memcpy_s(&g_ucResumeAddr[2], sizeof(DWORD), &g_dwResumeCodeAddr, sizeof(DWORD));//�޸�HOOK�������,����תĿ��ĳɵ��Լ��ӳ����ַ->jmp &MyFunc
	//memcpy(&g_ucResumeCode[dwHookSize + 1], g_ucResumeAddr,sizeof(g_ucResumeAddr));

	g_dwResumeCodeAddr = (DWORD)&g_ucResumeCode; //����ȫ�ֱ��������⺯���˳������٣�ȡ���CALL��ַ
	//DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//����[0x000000]���൱����������


	unsigned char ucHookCode[100] = { 0xFF,0x25,0x00,0x00,0x00,0x00 };//���� FF 25 ������ת -> FF 25 00 00 00 00 -> jmp [0x00000000]
	g_dwHookFrameworkAddr = (DWORD)&HookFramework; //����ȫ�ֱ��������⺯���˳������٣�ȡ���CALL��ַ
	DWORD pHookFrameworkAddr = (DWORD)&g_dwHookFrameworkAddr;//����[0x000000]���൱����������
	memcpy_s(&ucHookCode[2], sizeof(DWORD), &pHookFrameworkAddr, sizeof(DWORD));//�޸�HOOK�������,�����������
	memset(ucHookCode + 6, 0x90, dwHookSize - 6);//ʣ�೤����0x90(nop)����
	if (MemoryLib::WriteProcessMemory(hProcess, dwHookAddress, &ucHookCode, dwHookSize)) //д���ڴ�
		return true;
	else
	{
		StringLib::DbgPrintf("д��Hookʧ�ܣ�������Ȩ�ޣ�");
		return false;
	}
	return false;
}

bool HookLib::InlineResume()
{
	return MemoryLib::WriteProcessMemory(g_hProcess, g_dwHookAddress, &g_ucResumeCode, g_dwHookSize); //д���ڴ�
}
