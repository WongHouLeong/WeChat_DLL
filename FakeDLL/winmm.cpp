#include "..\UtilityLib\UtilityLib.h"
HMODULE g_hRealModule(NULL);
#pragma region MyRegion
#pragma comment(linker, "/EXPORT:Noname2=_AheadLib_Unnamed2,@2,NONAME")
#pragma comment(linker, "/EXPORT:mciExecute=_AheadLib_mciExecute,@3")
#pragma comment(linker, "/EXPORT:CloseDriver=_AheadLib_CloseDriver,@4")
#pragma comment(linker, "/EXPORT:DefDriverProc=_AheadLib_DefDriverProc,@5")
#pragma comment(linker, "/EXPORT:DriverCallback=_AheadLib_DriverCallback,@6")
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=_AheadLib_DrvGetModuleHandle,@7")
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=_AheadLib_GetDriverModuleHandle,@8")
#pragma comment(linker, "/EXPORT:NotifyCallbackData=_AheadLib_NotifyCallbackData,@9")
#pragma comment(linker, "/EXPORT:OpenDriver=_AheadLib_OpenDriver,@10")
#pragma comment(linker, "/EXPORT:PlaySound=_AheadLib_PlaySound,@11")
#pragma comment(linker, "/EXPORT:PlaySoundA=_AheadLib_PlaySoundA,@12")
#pragma comment(linker, "/EXPORT:PlaySoundW=_AheadLib_PlaySoundW,@13")
#pragma comment(linker, "/EXPORT:SendDriverMessage=_AheadLib_SendDriverMessage,@14")
#pragma comment(linker, "/EXPORT:WOW32DriverCallback=_AheadLib_WOW32DriverCallback,@15")
#pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=_AheadLib_WOW32ResolveMultiMediaHandle,@16")
#pragma comment(linker, "/EXPORT:WOWAppExit=_AheadLib_WOWAppExit,@17")
#pragma comment(linker, "/EXPORT:aux32Message=_AheadLib_aux32Message,@18")
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=_AheadLib_auxGetDevCapsA,@19")
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=_AheadLib_auxGetDevCapsW,@20")
#pragma comment(linker, "/EXPORT:auxGetNumDevs=_AheadLib_auxGetNumDevs,@21")
#pragma comment(linker, "/EXPORT:auxGetVolume=_AheadLib_auxGetVolume,@22")
#pragma comment(linker, "/EXPORT:auxOutMessage=_AheadLib_auxOutMessage,@23")
#pragma comment(linker, "/EXPORT:auxSetVolume=_AheadLib_auxSetVolume,@24")
#pragma comment(linker, "/EXPORT:joy32Message=_AheadLib_joy32Message,@25")
#pragma comment(linker, "/EXPORT:joyConfigChanged=_AheadLib_joyConfigChanged,@26")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=_AheadLib_joyGetDevCapsA,@27")
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=_AheadLib_joyGetDevCapsW,@28")
#pragma comment(linker, "/EXPORT:joyGetNumDevs=_AheadLib_joyGetNumDevs,@29")
#pragma comment(linker, "/EXPORT:joyGetPos=_AheadLib_joyGetPos,@30")
#pragma comment(linker, "/EXPORT:joyGetPosEx=_AheadLib_joyGetPosEx,@31")
#pragma comment(linker, "/EXPORT:joyGetThreshold=_AheadLib_joyGetThreshold,@32")
#pragma comment(linker, "/EXPORT:joyReleaseCapture=_AheadLib_joyReleaseCapture,@33")
#pragma comment(linker, "/EXPORT:joySetCapture=_AheadLib_joySetCapture,@34")
#pragma comment(linker, "/EXPORT:joySetThreshold=_AheadLib_joySetThreshold,@35")
#pragma comment(linker, "/EXPORT:mci32Message=_AheadLib_mci32Message,@36")
#pragma comment(linker, "/EXPORT:mciDriverNotify=_AheadLib_mciDriverNotify,@37")
#pragma comment(linker, "/EXPORT:mciDriverYield=_AheadLib_mciDriverYield,@38")
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=_AheadLib_mciFreeCommandResource,@39")
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=_AheadLib_mciGetCreatorTask,@40")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=_AheadLib_mciGetDeviceIDA,@41")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=_AheadLib_mciGetDeviceIDFromElementIDA,@42")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=_AheadLib_mciGetDeviceIDFromElementIDW,@43")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=_AheadLib_mciGetDeviceIDW,@44")
#pragma comment(linker, "/EXPORT:mciGetDriverData=_AheadLib_mciGetDriverData,@45")
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=_AheadLib_mciGetErrorStringA,@46")
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=_AheadLib_mciGetErrorStringW,@47")
#pragma comment(linker, "/EXPORT:mciGetYieldProc=_AheadLib_mciGetYieldProc,@48")
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=_AheadLib_mciLoadCommandResource,@49")
#pragma comment(linker, "/EXPORT:mciSendCommandA=_AheadLib_mciSendCommandA,@50")
#pragma comment(linker, "/EXPORT:mciSendCommandW=_AheadLib_mciSendCommandW,@51")
#pragma comment(linker, "/EXPORT:mciSendStringA=_AheadLib_mciSendStringA,@52")
#pragma comment(linker, "/EXPORT:mciSendStringW=_AheadLib_mciSendStringW,@53")
#pragma comment(linker, "/EXPORT:mciSetDriverData=_AheadLib_mciSetDriverData,@54")
#pragma comment(linker, "/EXPORT:mciSetYieldProc=_AheadLib_mciSetYieldProc,@55")
#pragma comment(linker, "/EXPORT:mid32Message=_AheadLib_mid32Message,@56")
#pragma comment(linker, "/EXPORT:midiConnect=_AheadLib_midiConnect,@57")
#pragma comment(linker, "/EXPORT:midiDisconnect=_AheadLib_midiDisconnect,@58")
#pragma comment(linker, "/EXPORT:midiInAddBuffer=_AheadLib_midiInAddBuffer,@59")
#pragma comment(linker, "/EXPORT:midiInClose=_AheadLib_midiInClose,@60")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=_AheadLib_midiInGetDevCapsA,@61")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=_AheadLib_midiInGetDevCapsW,@62")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=_AheadLib_midiInGetErrorTextA,@63")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=_AheadLib_midiInGetErrorTextW,@64")
#pragma comment(linker, "/EXPORT:midiInGetID=_AheadLib_midiInGetID,@65")
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=_AheadLib_midiInGetNumDevs,@66")
#pragma comment(linker, "/EXPORT:midiInMessage=_AheadLib_midiInMessage,@67")
#pragma comment(linker, "/EXPORT:midiInOpen=_AheadLib_midiInOpen,@68")
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=_AheadLib_midiInPrepareHeader,@69")
#pragma comment(linker, "/EXPORT:midiInReset=_AheadLib_midiInReset,@70")
#pragma comment(linker, "/EXPORT:midiInStart=_AheadLib_midiInStart,@71")
#pragma comment(linker, "/EXPORT:midiInStop=_AheadLib_midiInStop,@72")
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=_AheadLib_midiInUnprepareHeader,@73")
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=_AheadLib_midiOutCacheDrumPatches,@74")
#pragma comment(linker, "/EXPORT:midiOutCachePatches=_AheadLib_midiOutCachePatches,@75")
#pragma comment(linker, "/EXPORT:midiOutClose=_AheadLib_midiOutClose,@76")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_AheadLib_midiOutGetDevCapsA,@77")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=_AheadLib_midiOutGetDevCapsW,@78")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=_AheadLib_midiOutGetErrorTextA,@79")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=_AheadLib_midiOutGetErrorTextW,@80")
#pragma comment(linker, "/EXPORT:midiOutGetID=_AheadLib_midiOutGetID,@81")
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_AheadLib_midiOutGetNumDevs,@82")
#pragma comment(linker, "/EXPORT:midiOutGetVolume=_AheadLib_midiOutGetVolume,@83")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=_AheadLib_midiOutLongMsg,@84")
#pragma comment(linker, "/EXPORT:midiOutMessage=_AheadLib_midiOutMessage,@85")
#pragma comment(linker, "/EXPORT:midiOutOpen=_AheadLib_midiOutOpen,@86")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_AheadLib_midiOutPrepareHeader,@87")
#pragma comment(linker, "/EXPORT:midiOutReset=_AheadLib_midiOutReset,@88")
#pragma comment(linker, "/EXPORT:midiOutSetVolume=_AheadLib_midiOutSetVolume,@89")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=_AheadLib_midiOutShortMsg,@90")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_AheadLib_midiOutUnprepareHeader,@91")
#pragma comment(linker, "/EXPORT:midiStreamClose=_AheadLib_midiStreamClose,@92")
#pragma comment(linker, "/EXPORT:midiStreamOpen=_AheadLib_midiStreamOpen,@93")
#pragma comment(linker, "/EXPORT:midiStreamOut=_AheadLib_midiStreamOut,@94")
#pragma comment(linker, "/EXPORT:midiStreamPause=_AheadLib_midiStreamPause,@95")
#pragma comment(linker, "/EXPORT:midiStreamPosition=_AheadLib_midiStreamPosition,@96")
#pragma comment(linker, "/EXPORT:midiStreamProperty=_AheadLib_midiStreamProperty,@97")
#pragma comment(linker, "/EXPORT:midiStreamRestart=_AheadLib_midiStreamRestart,@98")
#pragma comment(linker, "/EXPORT:midiStreamStop=_AheadLib_midiStreamStop,@99")
#pragma comment(linker, "/EXPORT:mixerClose=_AheadLib_mixerClose,@100")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=_AheadLib_mixerGetControlDetailsA,@101")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=_AheadLib_mixerGetControlDetailsW,@102")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=_AheadLib_mixerGetDevCapsA,@103")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=_AheadLib_mixerGetDevCapsW,@104")
#pragma comment(linker, "/EXPORT:mixerGetID=_AheadLib_mixerGetID,@105")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=_AheadLib_mixerGetLineControlsA,@106")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=_AheadLib_mixerGetLineControlsW,@107")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=_AheadLib_mixerGetLineInfoA,@108")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=_AheadLib_mixerGetLineInfoW,@109")
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=_AheadLib_mixerGetNumDevs,@110")
#pragma comment(linker, "/EXPORT:mixerMessage=_AheadLib_mixerMessage,@111")
#pragma comment(linker, "/EXPORT:mixerOpen=_AheadLib_mixerOpen,@112")
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=_AheadLib_mixerSetControlDetails,@113")
#pragma comment(linker, "/EXPORT:mmDrvInstall=_AheadLib_mmDrvInstall,@114")
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=_AheadLib_mmGetCurrentTask,@115")
#pragma comment(linker, "/EXPORT:mmTaskBlock=_AheadLib_mmTaskBlock,@116")
#pragma comment(linker, "/EXPORT:mmTaskCreate=_AheadLib_mmTaskCreate,@117")
#pragma comment(linker, "/EXPORT:mmTaskSignal=_AheadLib_mmTaskSignal,@118")
#pragma comment(linker, "/EXPORT:mmTaskYield=_AheadLib_mmTaskYield,@119")
#pragma comment(linker, "/EXPORT:mmioAdvance=_AheadLib_mmioAdvance,@120")
#pragma comment(linker, "/EXPORT:mmioAscend=_AheadLib_mmioAscend,@121")
#pragma comment(linker, "/EXPORT:mmioClose=_AheadLib_mmioClose,@122")
#pragma comment(linker, "/EXPORT:mmioCreateChunk=_AheadLib_mmioCreateChunk,@123")
#pragma comment(linker, "/EXPORT:mmioDescend=_AheadLib_mmioDescend,@124")
#pragma comment(linker, "/EXPORT:mmioFlush=_AheadLib_mmioFlush,@125")
#pragma comment(linker, "/EXPORT:mmioGetInfo=_AheadLib_mmioGetInfo,@126")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=_AheadLib_mmioInstallIOProcA,@127")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=_AheadLib_mmioInstallIOProcW,@128")
#pragma comment(linker, "/EXPORT:mmioOpenA=_AheadLib_mmioOpenA,@129")
#pragma comment(linker, "/EXPORT:mmioOpenW=_AheadLib_mmioOpenW,@130")
#pragma comment(linker, "/EXPORT:mmioRead=_AheadLib_mmioRead,@131")
#pragma comment(linker, "/EXPORT:mmioRenameA=_AheadLib_mmioRenameA,@132")
#pragma comment(linker, "/EXPORT:mmioRenameW=_AheadLib_mmioRenameW,@133")
#pragma comment(linker, "/EXPORT:mmioSeek=_AheadLib_mmioSeek,@134")
#pragma comment(linker, "/EXPORT:mmioSendMessage=_AheadLib_mmioSendMessage,@135")
#pragma comment(linker, "/EXPORT:mmioSetBuffer=_AheadLib_mmioSetBuffer,@136")
#pragma comment(linker, "/EXPORT:mmioSetInfo=_AheadLib_mmioSetInfo,@137")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=_AheadLib_mmioStringToFOURCCA,@138")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=_AheadLib_mmioStringToFOURCCW,@139")
#pragma comment(linker, "/EXPORT:mmioWrite=_AheadLib_mmioWrite,@140")
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=_AheadLib_mmsystemGetVersion,@141")
#pragma comment(linker, "/EXPORT:mod32Message=_AheadLib_mod32Message,@142")
#pragma comment(linker, "/EXPORT:mxd32Message=_AheadLib_mxd32Message,@143")
#pragma comment(linker, "/EXPORT:sndPlaySoundA=_AheadLib_sndPlaySoundA,@144")
#pragma comment(linker, "/EXPORT:sndPlaySoundW=_AheadLib_sndPlaySoundW,@145")
#pragma comment(linker, "/EXPORT:tid32Message=_AheadLib_tid32Message,@146")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=_AheadLib_timeBeginPeriod,@147")
#pragma comment(linker, "/EXPORT:timeEndPeriod=_AheadLib_timeEndPeriod,@148")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=_AheadLib_timeGetDevCaps,@149")
#pragma comment(linker, "/EXPORT:timeGetSystemTime=_AheadLib_timeGetSystemTime,@150")
#pragma comment(linker, "/EXPORT:timeGetTime=_AheadLib_timeGetTime,@151")
#pragma comment(linker, "/EXPORT:timeKillEvent=_AheadLib_timeKillEvent,@152")
#pragma comment(linker, "/EXPORT:timeSetEvent=_AheadLib_timeSetEvent,@153")
#pragma comment(linker, "/EXPORT:waveInAddBuffer=_AheadLib_waveInAddBuffer,@154")
#pragma comment(linker, "/EXPORT:waveInClose=_AheadLib_waveInClose,@155")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=_AheadLib_waveInGetDevCapsA,@156")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=_AheadLib_waveInGetDevCapsW,@157")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=_AheadLib_waveInGetErrorTextA,@158")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=_AheadLib_waveInGetErrorTextW,@159")
#pragma comment(linker, "/EXPORT:waveInGetID=_AheadLib_waveInGetID,@160")
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=_AheadLib_waveInGetNumDevs,@161")
#pragma comment(linker, "/EXPORT:waveInGetPosition=_AheadLib_waveInGetPosition,@162")
#pragma comment(linker, "/EXPORT:waveInMessage=_AheadLib_waveInMessage,@163")
#pragma comment(linker, "/EXPORT:waveInOpen=_AheadLib_waveInOpen,@164")
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=_AheadLib_waveInPrepareHeader,@165")
#pragma comment(linker, "/EXPORT:waveInReset=_AheadLib_waveInReset,@166")
#pragma comment(linker, "/EXPORT:waveInStart=_AheadLib_waveInStart,@167")
#pragma comment(linker, "/EXPORT:waveInStop=_AheadLib_waveInStop,@168")
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=_AheadLib_waveInUnprepareHeader,@169")
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=_AheadLib_waveOutBreakLoop,@170")
#pragma comment(linker, "/EXPORT:waveOutClose=_AheadLib_waveOutClose,@171")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=_AheadLib_waveOutGetDevCapsA,@172")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=_AheadLib_waveOutGetDevCapsW,@173")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=_AheadLib_waveOutGetErrorTextA,@174")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=_AheadLib_waveOutGetErrorTextW,@175")
#pragma comment(linker, "/EXPORT:waveOutGetID=_AheadLib_waveOutGetID,@176")
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=_AheadLib_waveOutGetNumDevs,@177")
#pragma comment(linker, "/EXPORT:waveOutGetPitch=_AheadLib_waveOutGetPitch,@178")
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=_AheadLib_waveOutGetPlaybackRate,@179")
#pragma comment(linker, "/EXPORT:waveOutGetPosition=_AheadLib_waveOutGetPosition,@180")
#pragma comment(linker, "/EXPORT:waveOutGetVolume=_AheadLib_waveOutGetVolume,@181")
#pragma comment(linker, "/EXPORT:waveOutMessage=_AheadLib_waveOutMessage,@182")
#pragma comment(linker, "/EXPORT:waveOutOpen=_AheadLib_waveOutOpen,@183")
#pragma comment(linker, "/EXPORT:waveOutPause=_AheadLib_waveOutPause,@184")
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=_AheadLib_waveOutPrepareHeader,@185")
#pragma comment(linker, "/EXPORT:waveOutReset=_AheadLib_waveOutReset,@186")
#pragma comment(linker, "/EXPORT:waveOutRestart=_AheadLib_waveOutRestart,@187")
#pragma comment(linker, "/EXPORT:waveOutSetPitch=_AheadLib_waveOutSetPitch,@188")
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=_AheadLib_waveOutSetPlaybackRate,@189")
#pragma comment(linker, "/EXPORT:waveOutSetVolume=_AheadLib_waveOutSetVolume,@190")
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=_AheadLib_waveOutUnprepareHeader,@191")
#pragma comment(linker, "/EXPORT:waveOutWrite=_AheadLib_waveOutWrite,@192")
#pragma comment(linker, "/EXPORT:wid32Message=_AheadLib_wid32Message,@193")
#pragma comment(linker, "/EXPORT:wod32Message=_AheadLib_wod32Message,@194")
PVOID pfnAheadLib_Unnamed2;
PVOID pfnAheadLib_mciExecute;
PVOID pfnAheadLib_CloseDriver;
PVOID pfnAheadLib_DefDriverProc;
PVOID pfnAheadLib_DriverCallback;
PVOID pfnAheadLib_DrvGetModuleHandle;
PVOID pfnAheadLib_GetDriverModuleHandle;
PVOID pfnAheadLib_NotifyCallbackData;
PVOID pfnAheadLib_OpenDriver;
PVOID pfnAheadLib_PlaySound;
PVOID pfnAheadLib_PlaySoundA;
PVOID pfnAheadLib_PlaySoundW;
PVOID pfnAheadLib_SendDriverMessage;
PVOID pfnAheadLib_WOW32DriverCallback;
PVOID pfnAheadLib_WOW32ResolveMultiMediaHandle;
PVOID pfnAheadLib_WOWAppExit;
PVOID pfnAheadLib_aux32Message;
PVOID pfnAheadLib_auxGetDevCapsA;
PVOID pfnAheadLib_auxGetDevCapsW;
PVOID pfnAheadLib_auxGetNumDevs;
PVOID pfnAheadLib_auxGetVolume;
PVOID pfnAheadLib_auxOutMessage;
PVOID pfnAheadLib_auxSetVolume;
PVOID pfnAheadLib_joy32Message;
PVOID pfnAheadLib_joyConfigChanged;
PVOID pfnAheadLib_joyGetDevCapsA;
PVOID pfnAheadLib_joyGetDevCapsW;
PVOID pfnAheadLib_joyGetNumDevs;
PVOID pfnAheadLib_joyGetPos;
PVOID pfnAheadLib_joyGetPosEx;
PVOID pfnAheadLib_joyGetThreshold;
PVOID pfnAheadLib_joyReleaseCapture;
PVOID pfnAheadLib_joySetCapture;
PVOID pfnAheadLib_joySetThreshold;
PVOID pfnAheadLib_mci32Message;
PVOID pfnAheadLib_mciDriverNotify;
PVOID pfnAheadLib_mciDriverYield;
PVOID pfnAheadLib_mciFreeCommandResource;
PVOID pfnAheadLib_mciGetCreatorTask;
PVOID pfnAheadLib_mciGetDeviceIDA;
PVOID pfnAheadLib_mciGetDeviceIDFromElementIDA;
PVOID pfnAheadLib_mciGetDeviceIDFromElementIDW;
PVOID pfnAheadLib_mciGetDeviceIDW;
PVOID pfnAheadLib_mciGetDriverData;
PVOID pfnAheadLib_mciGetErrorStringA;
PVOID pfnAheadLib_mciGetErrorStringW;
PVOID pfnAheadLib_mciGetYieldProc;
PVOID pfnAheadLib_mciLoadCommandResource;
PVOID pfnAheadLib_mciSendCommandA;
PVOID pfnAheadLib_mciSendCommandW;
PVOID pfnAheadLib_mciSendStringA;
PVOID pfnAheadLib_mciSendStringW;
PVOID pfnAheadLib_mciSetDriverData;
PVOID pfnAheadLib_mciSetYieldProc;
PVOID pfnAheadLib_mid32Message;
PVOID pfnAheadLib_midiConnect;
PVOID pfnAheadLib_midiDisconnect;
PVOID pfnAheadLib_midiInAddBuffer;
PVOID pfnAheadLib_midiInClose;
PVOID pfnAheadLib_midiInGetDevCapsA;
PVOID pfnAheadLib_midiInGetDevCapsW;
PVOID pfnAheadLib_midiInGetErrorTextA;
PVOID pfnAheadLib_midiInGetErrorTextW;
PVOID pfnAheadLib_midiInGetID;
PVOID pfnAheadLib_midiInGetNumDevs;
PVOID pfnAheadLib_midiInMessage;
PVOID pfnAheadLib_midiInOpen;
PVOID pfnAheadLib_midiInPrepareHeader;
PVOID pfnAheadLib_midiInReset;
PVOID pfnAheadLib_midiInStart;
PVOID pfnAheadLib_midiInStop;
PVOID pfnAheadLib_midiInUnprepareHeader;
PVOID pfnAheadLib_midiOutCacheDrumPatches;
PVOID pfnAheadLib_midiOutCachePatches;
PVOID pfnAheadLib_midiOutClose;
PVOID pfnAheadLib_midiOutGetDevCapsA;
PVOID pfnAheadLib_midiOutGetDevCapsW;
PVOID pfnAheadLib_midiOutGetErrorTextA;
PVOID pfnAheadLib_midiOutGetErrorTextW;
PVOID pfnAheadLib_midiOutGetID;
PVOID pfnAheadLib_midiOutGetNumDevs;
PVOID pfnAheadLib_midiOutGetVolume;
PVOID pfnAheadLib_midiOutLongMsg;
PVOID pfnAheadLib_midiOutMessage;
PVOID pfnAheadLib_midiOutOpen;
PVOID pfnAheadLib_midiOutPrepareHeader;
PVOID pfnAheadLib_midiOutReset;
PVOID pfnAheadLib_midiOutSetVolume;
PVOID pfnAheadLib_midiOutShortMsg;
PVOID pfnAheadLib_midiOutUnprepareHeader;
PVOID pfnAheadLib_midiStreamClose;
PVOID pfnAheadLib_midiStreamOpen;
PVOID pfnAheadLib_midiStreamOut;
PVOID pfnAheadLib_midiStreamPause;
PVOID pfnAheadLib_midiStreamPosition;
PVOID pfnAheadLib_midiStreamProperty;
PVOID pfnAheadLib_midiStreamRestart;
PVOID pfnAheadLib_midiStreamStop;
PVOID pfnAheadLib_mixerClose;
PVOID pfnAheadLib_mixerGetControlDetailsA;
PVOID pfnAheadLib_mixerGetControlDetailsW;
PVOID pfnAheadLib_mixerGetDevCapsA;
PVOID pfnAheadLib_mixerGetDevCapsW;
PVOID pfnAheadLib_mixerGetID;
PVOID pfnAheadLib_mixerGetLineControlsA;
PVOID pfnAheadLib_mixerGetLineControlsW;
PVOID pfnAheadLib_mixerGetLineInfoA;
PVOID pfnAheadLib_mixerGetLineInfoW;
PVOID pfnAheadLib_mixerGetNumDevs;
PVOID pfnAheadLib_mixerMessage;
PVOID pfnAheadLib_mixerOpen;
PVOID pfnAheadLib_mixerSetControlDetails;
PVOID pfnAheadLib_mmDrvInstall;
PVOID pfnAheadLib_mmGetCurrentTask;
PVOID pfnAheadLib_mmTaskBlock;
PVOID pfnAheadLib_mmTaskCreate;
PVOID pfnAheadLib_mmTaskSignal;
PVOID pfnAheadLib_mmTaskYield;
PVOID pfnAheadLib_mmioAdvance;
PVOID pfnAheadLib_mmioAscend;
PVOID pfnAheadLib_mmioClose;
PVOID pfnAheadLib_mmioCreateChunk;
PVOID pfnAheadLib_mmioDescend;
PVOID pfnAheadLib_mmioFlush;
PVOID pfnAheadLib_mmioGetInfo;
PVOID pfnAheadLib_mmioInstallIOProcA;
PVOID pfnAheadLib_mmioInstallIOProcW;
PVOID pfnAheadLib_mmioOpenA;
PVOID pfnAheadLib_mmioOpenW;
PVOID pfnAheadLib_mmioRead;
PVOID pfnAheadLib_mmioRenameA;
PVOID pfnAheadLib_mmioRenameW;
PVOID pfnAheadLib_mmioSeek;
PVOID pfnAheadLib_mmioSendMessage;
PVOID pfnAheadLib_mmioSetBuffer;
PVOID pfnAheadLib_mmioSetInfo;
PVOID pfnAheadLib_mmioStringToFOURCCA;
PVOID pfnAheadLib_mmioStringToFOURCCW;
PVOID pfnAheadLib_mmioWrite;
PVOID pfnAheadLib_mmsystemGetVersion;
PVOID pfnAheadLib_mod32Message;
PVOID pfnAheadLib_mxd32Message;
PVOID pfnAheadLib_sndPlaySoundA;
PVOID pfnAheadLib_sndPlaySoundW;
PVOID pfnAheadLib_tid32Message;
PVOID pfnAheadLib_timeBeginPeriod;
PVOID pfnAheadLib_timeEndPeriod;
PVOID pfnAheadLib_timeGetDevCaps;
PVOID pfnAheadLib_timeGetSystemTime;
PVOID pfnAheadLib_timeGetTime;
PVOID pfnAheadLib_timeKillEvent;
PVOID pfnAheadLib_timeSetEvent;
PVOID pfnAheadLib_waveInAddBuffer;
PVOID pfnAheadLib_waveInClose;
PVOID pfnAheadLib_waveInGetDevCapsA;
PVOID pfnAheadLib_waveInGetDevCapsW;
PVOID pfnAheadLib_waveInGetErrorTextA;
PVOID pfnAheadLib_waveInGetErrorTextW;
PVOID pfnAheadLib_waveInGetID;
PVOID pfnAheadLib_waveInGetNumDevs;
PVOID pfnAheadLib_waveInGetPosition;
PVOID pfnAheadLib_waveInMessage;
PVOID pfnAheadLib_waveInOpen;
PVOID pfnAheadLib_waveInPrepareHeader;
PVOID pfnAheadLib_waveInReset;
PVOID pfnAheadLib_waveInStart;
PVOID pfnAheadLib_waveInStop;
PVOID pfnAheadLib_waveInUnprepareHeader;
PVOID pfnAheadLib_waveOutBreakLoop;
PVOID pfnAheadLib_waveOutClose;
PVOID pfnAheadLib_waveOutGetDevCapsA;
PVOID pfnAheadLib_waveOutGetDevCapsW;
PVOID pfnAheadLib_waveOutGetErrorTextA;
PVOID pfnAheadLib_waveOutGetErrorTextW;
PVOID pfnAheadLib_waveOutGetID;
PVOID pfnAheadLib_waveOutGetNumDevs;
PVOID pfnAheadLib_waveOutGetPitch;
PVOID pfnAheadLib_waveOutGetPlaybackRate;
PVOID pfnAheadLib_waveOutGetPosition;
PVOID pfnAheadLib_waveOutGetVolume;
PVOID pfnAheadLib_waveOutMessage;
PVOID pfnAheadLib_waveOutOpen;
PVOID pfnAheadLib_waveOutPause;
PVOID pfnAheadLib_waveOutPrepareHeader;
PVOID pfnAheadLib_waveOutReset;
PVOID pfnAheadLib_waveOutRestart;
PVOID pfnAheadLib_waveOutSetPitch;
PVOID pfnAheadLib_waveOutSetPlaybackRate;
PVOID pfnAheadLib_waveOutSetVolume;
PVOID pfnAheadLib_waveOutUnprepareHeader;
PVOID pfnAheadLib_waveOutWrite;
PVOID pfnAheadLib_wid32Message;
PVOID pfnAheadLib_wod32Message;

extern "C" __declspec(naked) void  AheadLib_Unnamed2(void)
{
	__asm jmp pfnAheadLib_Unnamed2;
}

extern "C" __declspec(naked) void  AheadLib_mciExecute(void)
{
	__asm jmp pfnAheadLib_mciExecute;
}

extern "C" __declspec(naked) void  AheadLib_CloseDriver(void)
{
	__asm jmp pfnAheadLib_CloseDriver;
}

extern "C" __declspec(naked) void  AheadLib_DefDriverProc(void)
{
	__asm jmp pfnAheadLib_DefDriverProc;
}

extern "C" __declspec(naked) void  AheadLib_DriverCallback(void)
{
	__asm jmp pfnAheadLib_DriverCallback;
}

extern "C" __declspec(naked) void  AheadLib_DrvGetModuleHandle(void)
{
	__asm jmp pfnAheadLib_DrvGetModuleHandle;
}

extern "C" __declspec(naked) void  AheadLib_GetDriverModuleHandle(void)
{
	__asm jmp pfnAheadLib_GetDriverModuleHandle;
}

extern "C" __declspec(naked) void  AheadLib_NotifyCallbackData(void)
{
	__asm jmp pfnAheadLib_NotifyCallbackData;
}

extern "C" __declspec(naked) void  AheadLib_OpenDriver(void)
{
	__asm jmp pfnAheadLib_OpenDriver;
}

extern "C" __declspec(naked) void  AheadLib_PlaySound(void)
{
	__asm jmp pfnAheadLib_PlaySound;
}

extern "C" __declspec(naked) void  AheadLib_PlaySoundA(void)
{
	__asm jmp pfnAheadLib_PlaySoundA;
}

extern "C" __declspec(naked) void  AheadLib_PlaySoundW(void)
{
	__asm jmp pfnAheadLib_PlaySoundW;
}

extern "C" __declspec(naked) void  AheadLib_SendDriverMessage(void)
{
	__asm jmp pfnAheadLib_SendDriverMessage;
}

extern "C" __declspec(naked) void  AheadLib_WOW32DriverCallback(void)
{
	__asm jmp pfnAheadLib_WOW32DriverCallback;
}

extern "C" __declspec(naked) void  AheadLib_WOW32ResolveMultiMediaHandle(void)
{
	__asm jmp pfnAheadLib_WOW32ResolveMultiMediaHandle;
}

extern "C" __declspec(naked) void  AheadLib_WOWAppExit(void)
{
	__asm jmp pfnAheadLib_WOWAppExit;
}

extern "C" __declspec(naked) void  AheadLib_aux32Message(void)
{
	__asm jmp pfnAheadLib_aux32Message;
}

extern "C" __declspec(naked) void  AheadLib_auxGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_auxGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_auxGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_auxGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_auxGetNumDevs(void)
{
	__asm jmp pfnAheadLib_auxGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_auxGetVolume(void)
{
	__asm jmp pfnAheadLib_auxGetVolume;
}

extern "C" __declspec(naked) void  AheadLib_auxOutMessage(void)
{
	__asm jmp pfnAheadLib_auxOutMessage;
}

extern "C" __declspec(naked) void  AheadLib_auxSetVolume(void)
{
	__asm jmp pfnAheadLib_auxSetVolume;
}

extern "C" __declspec(naked) void  AheadLib_joy32Message(void)
{
	__asm jmp pfnAheadLib_joy32Message;
}

extern "C" __declspec(naked) void  AheadLib_joyConfigChanged(void)
{
	__asm jmp pfnAheadLib_joyConfigChanged;
}

extern "C" __declspec(naked) void  AheadLib_joyGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_joyGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_joyGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_joyGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_joyGetNumDevs(void)
{
	__asm jmp pfnAheadLib_joyGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_joyGetPos(void)
{
	__asm jmp pfnAheadLib_joyGetPos;
}

extern "C" __declspec(naked) void  AheadLib_joyGetPosEx(void)
{
	__asm jmp pfnAheadLib_joyGetPosEx;
}

extern "C" __declspec(naked) void  AheadLib_joyGetThreshold(void)
{
	__asm jmp pfnAheadLib_joyGetThreshold;
}

extern "C" __declspec(naked) void  AheadLib_joyReleaseCapture(void)
{
	__asm jmp pfnAheadLib_joyReleaseCapture;
}

extern "C" __declspec(naked) void  AheadLib_joySetCapture(void)
{
	__asm jmp pfnAheadLib_joySetCapture;
}

extern "C" __declspec(naked) void  AheadLib_joySetThreshold(void)
{
	__asm jmp pfnAheadLib_joySetThreshold;
}

extern "C" __declspec(naked) void  AheadLib_mci32Message(void)
{
	__asm jmp pfnAheadLib_mci32Message;
}

extern "C" __declspec(naked) void  AheadLib_mciDriverNotify(void)
{
	__asm jmp pfnAheadLib_mciDriverNotify;
}

extern "C" __declspec(naked) void  AheadLib_mciDriverYield(void)
{
	__asm jmp pfnAheadLib_mciDriverYield;
}

extern "C" __declspec(naked) void  AheadLib_mciFreeCommandResource(void)
{
	__asm jmp pfnAheadLib_mciFreeCommandResource;
}

extern "C" __declspec(naked) void  AheadLib_mciGetCreatorTask(void)
{
	__asm jmp pfnAheadLib_mciGetCreatorTask;
}

extern "C" __declspec(naked) void  AheadLib_mciGetDeviceIDA(void)
{
	__asm jmp pfnAheadLib_mciGetDeviceIDA;
}

extern "C" __declspec(naked) void  AheadLib_mciGetDeviceIDFromElementIDA(void)
{
	__asm jmp pfnAheadLib_mciGetDeviceIDFromElementIDA;
}

extern "C" __declspec(naked) void  AheadLib_mciGetDeviceIDFromElementIDW(void)
{
	__asm jmp pfnAheadLib_mciGetDeviceIDFromElementIDW;
}

extern "C" __declspec(naked) void  AheadLib_mciGetDeviceIDW(void)
{
	__asm jmp pfnAheadLib_mciGetDeviceIDW;
}

extern "C" __declspec(naked) void  AheadLib_mciGetDriverData(void)
{
	__asm jmp pfnAheadLib_mciGetDriverData;
}

extern "C" __declspec(naked) void  AheadLib_mciGetErrorStringA(void)
{
	__asm jmp pfnAheadLib_mciGetErrorStringA;
}

extern "C" __declspec(naked) void  AheadLib_mciGetErrorStringW(void)
{
	__asm jmp pfnAheadLib_mciGetErrorStringW;
}

extern "C" __declspec(naked) void  AheadLib_mciGetYieldProc(void)
{
	__asm jmp pfnAheadLib_mciGetYieldProc;
}

extern "C" __declspec(naked) void  AheadLib_mciLoadCommandResource(void)
{
	__asm jmp pfnAheadLib_mciLoadCommandResource;
}

extern "C" __declspec(naked) void  AheadLib_mciSendCommandA(void)
{
	__asm jmp pfnAheadLib_mciSendCommandA;
}

extern "C" __declspec(naked) void  AheadLib_mciSendCommandW(void)
{
	__asm jmp pfnAheadLib_mciSendCommandW;
}

extern "C" __declspec(naked) void  AheadLib_mciSendStringA(void)
{
	__asm jmp pfnAheadLib_mciSendStringA;
}

extern "C" __declspec(naked) void  AheadLib_mciSendStringW(void)
{
	__asm jmp pfnAheadLib_mciSendStringW;
}

extern "C" __declspec(naked) void  AheadLib_mciSetDriverData(void)
{
	__asm jmp pfnAheadLib_mciSetDriverData;
}

extern "C" __declspec(naked) void  AheadLib_mciSetYieldProc(void)
{
	__asm jmp pfnAheadLib_mciSetYieldProc;
}

extern "C" __declspec(naked) void  AheadLib_mid32Message(void)
{
	__asm jmp pfnAheadLib_mid32Message;
}

extern "C" __declspec(naked) void  AheadLib_midiConnect(void)
{
	__asm jmp pfnAheadLib_midiConnect;
}

extern "C" __declspec(naked) void  AheadLib_midiDisconnect(void)
{
	__asm jmp pfnAheadLib_midiDisconnect;
}

extern "C" __declspec(naked) void  AheadLib_midiInAddBuffer(void)
{
	__asm jmp pfnAheadLib_midiInAddBuffer;
}

extern "C" __declspec(naked) void  AheadLib_midiInClose(void)
{
	__asm jmp pfnAheadLib_midiInClose;
}

extern "C" __declspec(naked) void  AheadLib_midiInGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_midiInGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_midiInGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_midiInGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_midiInGetErrorTextA(void)
{
	__asm jmp pfnAheadLib_midiInGetErrorTextA;
}

extern "C" __declspec(naked) void  AheadLib_midiInGetErrorTextW(void)
{
	__asm jmp pfnAheadLib_midiInGetErrorTextW;
}

extern "C" __declspec(naked) void  AheadLib_midiInGetID(void)
{
	__asm jmp pfnAheadLib_midiInGetID;
}

extern "C" __declspec(naked) void  AheadLib_midiInGetNumDevs(void)
{
	__asm jmp pfnAheadLib_midiInGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_midiInMessage(void)
{
	__asm jmp pfnAheadLib_midiInMessage;
}

extern "C" __declspec(naked) void  AheadLib_midiInOpen(void)
{
	__asm jmp pfnAheadLib_midiInOpen;
}

extern "C" __declspec(naked) void  AheadLib_midiInPrepareHeader(void)
{
	__asm jmp pfnAheadLib_midiInPrepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_midiInReset(void)
{
	__asm jmp pfnAheadLib_midiInReset;
}

extern "C" __declspec(naked) void  AheadLib_midiInStart(void)
{
	__asm jmp pfnAheadLib_midiInStart;
}

extern "C" __declspec(naked) void  AheadLib_midiInStop(void)
{
	__asm jmp pfnAheadLib_midiInStop;
}

extern "C" __declspec(naked) void  AheadLib_midiInUnprepareHeader(void)
{
	__asm jmp pfnAheadLib_midiInUnprepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_midiOutCacheDrumPatches(void)
{
	__asm jmp pfnAheadLib_midiOutCacheDrumPatches;
}

extern "C" __declspec(naked) void  AheadLib_midiOutCachePatches(void)
{
	__asm jmp pfnAheadLib_midiOutCachePatches;
}

extern "C" __declspec(naked) void  AheadLib_midiOutClose(void)
{
	__asm jmp pfnAheadLib_midiOutClose;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_midiOutGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_midiOutGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetErrorTextA(void)
{
	__asm jmp pfnAheadLib_midiOutGetErrorTextA;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetErrorTextW(void)
{
	__asm jmp pfnAheadLib_midiOutGetErrorTextW;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetID(void)
{
	__asm jmp pfnAheadLib_midiOutGetID;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetNumDevs(void)
{
	__asm jmp pfnAheadLib_midiOutGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_midiOutGetVolume(void)
{
	__asm jmp pfnAheadLib_midiOutGetVolume;
}

extern "C" __declspec(naked) void  AheadLib_midiOutLongMsg(void)
{
	__asm jmp pfnAheadLib_midiOutLongMsg;
}

extern "C" __declspec(naked) void  AheadLib_midiOutMessage(void)
{
	__asm jmp pfnAheadLib_midiOutMessage;
}

extern "C" __declspec(naked) void  AheadLib_midiOutOpen(void)
{
	__asm jmp pfnAheadLib_midiOutOpen;
}

extern "C" __declspec(naked) void  AheadLib_midiOutPrepareHeader(void)
{
	__asm jmp pfnAheadLib_midiOutPrepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_midiOutReset(void)
{
	__asm jmp pfnAheadLib_midiOutReset;
}

extern "C" __declspec(naked) void  AheadLib_midiOutSetVolume(void)
{
	__asm jmp pfnAheadLib_midiOutSetVolume;
}

extern "C" __declspec(naked) void  AheadLib_midiOutShortMsg(void)
{
	__asm jmp pfnAheadLib_midiOutShortMsg;
}

extern "C" __declspec(naked) void  AheadLib_midiOutUnprepareHeader(void)
{
	__asm jmp pfnAheadLib_midiOutUnprepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamClose(void)
{
	__asm jmp pfnAheadLib_midiStreamClose;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamOpen(void)
{
	__asm jmp pfnAheadLib_midiStreamOpen;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamOut(void)
{
	__asm jmp pfnAheadLib_midiStreamOut;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamPause(void)
{
	__asm jmp pfnAheadLib_midiStreamPause;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamPosition(void)
{
	__asm jmp pfnAheadLib_midiStreamPosition;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamProperty(void)
{
	__asm jmp pfnAheadLib_midiStreamProperty;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamRestart(void)
{
	__asm jmp pfnAheadLib_midiStreamRestart;
}

extern "C" __declspec(naked) void  AheadLib_midiStreamStop(void)
{
	__asm jmp pfnAheadLib_midiStreamStop;
}

extern "C" __declspec(naked) void  AheadLib_mixerClose(void)
{
	__asm jmp pfnAheadLib_mixerClose;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetControlDetailsA(void)
{
	__asm jmp pfnAheadLib_mixerGetControlDetailsA;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetControlDetailsW(void)
{
	__asm jmp pfnAheadLib_mixerGetControlDetailsW;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_mixerGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_mixerGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetID(void)
{
	__asm jmp pfnAheadLib_mixerGetID;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetLineControlsA(void)
{
	__asm jmp pfnAheadLib_mixerGetLineControlsA;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetLineControlsW(void)
{
	__asm jmp pfnAheadLib_mixerGetLineControlsW;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetLineInfoA(void)
{
	__asm jmp pfnAheadLib_mixerGetLineInfoA;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetLineInfoW(void)
{
	__asm jmp pfnAheadLib_mixerGetLineInfoW;
}

extern "C" __declspec(naked) void  AheadLib_mixerGetNumDevs(void)
{
	__asm jmp pfnAheadLib_mixerGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_mixerMessage(void)
{
	__asm jmp pfnAheadLib_mixerMessage;
}

extern "C" __declspec(naked) void  AheadLib_mixerOpen(void)
{
	__asm jmp pfnAheadLib_mixerOpen;
}

extern "C" __declspec(naked) void  AheadLib_mixerSetControlDetails(void)
{
	__asm jmp pfnAheadLib_mixerSetControlDetails;
}

extern "C" __declspec(naked) void  AheadLib_mmDrvInstall(void)
{
	__asm jmp pfnAheadLib_mmDrvInstall;
}

extern "C" __declspec(naked) void  AheadLib_mmGetCurrentTask(void)
{
	__asm jmp pfnAheadLib_mmGetCurrentTask;
}

extern "C" __declspec(naked) void  AheadLib_mmTaskBlock(void)
{
	__asm jmp pfnAheadLib_mmTaskBlock;
}

extern "C" __declspec(naked) void  AheadLib_mmTaskCreate(void)
{
	__asm jmp pfnAheadLib_mmTaskCreate;
}

extern "C" __declspec(naked) void  AheadLib_mmTaskSignal(void)
{
	__asm jmp pfnAheadLib_mmTaskSignal;
}

extern "C" __declspec(naked) void  AheadLib_mmTaskYield(void)
{
	__asm jmp pfnAheadLib_mmTaskYield;
}

extern "C" __declspec(naked) void  AheadLib_mmioAdvance(void)
{
	__asm jmp pfnAheadLib_mmioAdvance;
}

extern "C" __declspec(naked) void  AheadLib_mmioAscend(void)
{
	__asm jmp pfnAheadLib_mmioAscend;
}

extern "C" __declspec(naked) void  AheadLib_mmioClose(void)
{
	__asm jmp pfnAheadLib_mmioClose;
}

extern "C" __declspec(naked) void  AheadLib_mmioCreateChunk(void)
{
	__asm jmp pfnAheadLib_mmioCreateChunk;
}

extern "C" __declspec(naked) void  AheadLib_mmioDescend(void)
{
	__asm jmp pfnAheadLib_mmioDescend;
}

extern "C" __declspec(naked) void  AheadLib_mmioFlush(void)
{
	__asm jmp pfnAheadLib_mmioFlush;
}

extern "C" __declspec(naked) void  AheadLib_mmioGetInfo(void)
{
	__asm jmp pfnAheadLib_mmioGetInfo;
}

extern "C" __declspec(naked) void  AheadLib_mmioInstallIOProcA(void)
{
	__asm jmp pfnAheadLib_mmioInstallIOProcA;
}

extern "C" __declspec(naked) void  AheadLib_mmioInstallIOProcW(void)
{
	__asm jmp pfnAheadLib_mmioInstallIOProcW;
}

extern "C" __declspec(naked) void  AheadLib_mmioOpenA(void)
{
	__asm jmp pfnAheadLib_mmioOpenA;
}

extern "C" __declspec(naked) void  AheadLib_mmioOpenW(void)
{
	__asm jmp pfnAheadLib_mmioOpenW;
}

extern "C" __declspec(naked) void  AheadLib_mmioRead(void)
{
	__asm jmp pfnAheadLib_mmioRead;
}

extern "C" __declspec(naked) void  AheadLib_mmioRenameA(void)
{
	__asm jmp pfnAheadLib_mmioRenameA;
}

extern "C" __declspec(naked) void  AheadLib_mmioRenameW(void)
{
	__asm jmp pfnAheadLib_mmioRenameW;
}

extern "C" __declspec(naked) void  AheadLib_mmioSeek(void)
{
	__asm jmp pfnAheadLib_mmioSeek;
}

extern "C" __declspec(naked) void  AheadLib_mmioSendMessage(void)
{
	__asm jmp pfnAheadLib_mmioSendMessage;
}

extern "C" __declspec(naked) void  AheadLib_mmioSetBuffer(void)
{
	__asm jmp pfnAheadLib_mmioSetBuffer;
}

extern "C" __declspec(naked) void  AheadLib_mmioSetInfo(void)
{
	__asm jmp pfnAheadLib_mmioSetInfo;
}

extern "C" __declspec(naked) void  AheadLib_mmioStringToFOURCCA(void)
{
	__asm jmp pfnAheadLib_mmioStringToFOURCCA;
}

extern "C" __declspec(naked) void  AheadLib_mmioStringToFOURCCW(void)
{
	__asm jmp pfnAheadLib_mmioStringToFOURCCW;
}

extern "C" __declspec(naked) void  AheadLib_mmioWrite(void)
{
	__asm jmp pfnAheadLib_mmioWrite;
}

extern "C" __declspec(naked) void  AheadLib_mmsystemGetVersion(void)
{
	__asm jmp pfnAheadLib_mmsystemGetVersion;
}

extern "C" __declspec(naked) void  AheadLib_mod32Message(void)
{
	__asm jmp pfnAheadLib_mod32Message;
}

extern "C" __declspec(naked) void  AheadLib_mxd32Message(void)
{
	__asm jmp pfnAheadLib_mxd32Message;
}

extern "C" __declspec(naked) void  AheadLib_sndPlaySoundA(void)
{
	__asm jmp pfnAheadLib_sndPlaySoundA;
}

extern "C" __declspec(naked) void  AheadLib_sndPlaySoundW(void)
{
	__asm jmp pfnAheadLib_sndPlaySoundW;
}

extern "C" __declspec(naked) void  AheadLib_tid32Message(void)
{
	__asm jmp pfnAheadLib_tid32Message;
}

extern "C" __declspec(naked) void  AheadLib_timeBeginPeriod(void)
{
	__asm jmp pfnAheadLib_timeBeginPeriod;
}

extern "C" __declspec(naked) void  AheadLib_timeEndPeriod(void)
{
	__asm jmp pfnAheadLib_timeEndPeriod;
}

extern "C" __declspec(naked) void  AheadLib_timeGetDevCaps(void)
{
	__asm jmp pfnAheadLib_timeGetDevCaps;
}

extern "C" __declspec(naked) void  AheadLib_timeGetSystemTime(void)
{
	__asm jmp pfnAheadLib_timeGetSystemTime;
}

extern "C" __declspec(naked) void  AheadLib_timeGetTime(void)
{
	__asm jmp pfnAheadLib_timeGetTime;
}

extern "C" __declspec(naked) void  AheadLib_timeKillEvent(void)
{
	__asm jmp pfnAheadLib_timeKillEvent;
}

extern "C" __declspec(naked) void  AheadLib_timeSetEvent(void)
{
	__asm jmp pfnAheadLib_timeSetEvent;
}

extern "C" __declspec(naked) void  AheadLib_waveInAddBuffer(void)
{
	__asm jmp pfnAheadLib_waveInAddBuffer;
}

extern "C" __declspec(naked) void  AheadLib_waveInClose(void)
{
	__asm jmp pfnAheadLib_waveInClose;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_waveInGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_waveInGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetErrorTextA(void)
{
	__asm jmp pfnAheadLib_waveInGetErrorTextA;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetErrorTextW(void)
{
	__asm jmp pfnAheadLib_waveInGetErrorTextW;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetID(void)
{
	__asm jmp pfnAheadLib_waveInGetID;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetNumDevs(void)
{
	__asm jmp pfnAheadLib_waveInGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_waveInGetPosition(void)
{
	__asm jmp pfnAheadLib_waveInGetPosition;
}

extern "C" __declspec(naked) void  AheadLib_waveInMessage(void)
{
	__asm jmp pfnAheadLib_waveInMessage;
}

extern "C" __declspec(naked) void  AheadLib_waveInOpen(void)
{
	__asm jmp pfnAheadLib_waveInOpen;
}

extern "C" __declspec(naked) void  AheadLib_waveInPrepareHeader(void)
{
	__asm jmp pfnAheadLib_waveInPrepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_waveInReset(void)
{
	__asm jmp pfnAheadLib_waveInReset;
}

extern "C" __declspec(naked) void  AheadLib_waveInStart(void)
{
	__asm jmp pfnAheadLib_waveInStart;
}

extern "C" __declspec(naked) void  AheadLib_waveInStop(void)
{
	__asm jmp pfnAheadLib_waveInStop;
}

extern "C" __declspec(naked) void  AheadLib_waveInUnprepareHeader(void)
{
	__asm jmp pfnAheadLib_waveInUnprepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_waveOutBreakLoop(void)
{
	__asm jmp pfnAheadLib_waveOutBreakLoop;
}

extern "C" __declspec(naked) void  AheadLib_waveOutClose(void)
{
	__asm jmp pfnAheadLib_waveOutClose;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetDevCapsA(void)
{
	__asm jmp pfnAheadLib_waveOutGetDevCapsA;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetDevCapsW(void)
{
	__asm jmp pfnAheadLib_waveOutGetDevCapsW;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetErrorTextA(void)
{
	__asm jmp pfnAheadLib_waveOutGetErrorTextA;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetErrorTextW(void)
{
	__asm jmp pfnAheadLib_waveOutGetErrorTextW;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetID(void)
{
	__asm jmp pfnAheadLib_waveOutGetID;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetNumDevs(void)
{
	__asm jmp pfnAheadLib_waveOutGetNumDevs;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetPitch(void)
{
	__asm jmp pfnAheadLib_waveOutGetPitch;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetPlaybackRate(void)
{
	__asm jmp pfnAheadLib_waveOutGetPlaybackRate;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetPosition(void)
{
	__asm jmp pfnAheadLib_waveOutGetPosition;
}

extern "C" __declspec(naked) void  AheadLib_waveOutGetVolume(void)
{
	__asm jmp pfnAheadLib_waveOutGetVolume;
}

extern "C" __declspec(naked) void  AheadLib_waveOutMessage(void)
{
	__asm jmp pfnAheadLib_waveOutMessage;
}

extern "C" __declspec(naked) void  AheadLib_waveOutOpen(void)
{
	__asm jmp pfnAheadLib_waveOutOpen;
}

extern "C" __declspec(naked) void  AheadLib_waveOutPause(void)
{
	__asm jmp pfnAheadLib_waveOutPause;
}

extern "C" __declspec(naked) void  AheadLib_waveOutPrepareHeader(void)
{
	__asm jmp pfnAheadLib_waveOutPrepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_waveOutReset(void)
{
	__asm jmp pfnAheadLib_waveOutReset;
}

extern "C" __declspec(naked) void  AheadLib_waveOutRestart(void)
{
	__asm jmp pfnAheadLib_waveOutRestart;
}

extern "C" __declspec(naked) void  AheadLib_waveOutSetPitch(void)
{
	__asm jmp pfnAheadLib_waveOutSetPitch;
}

extern "C" __declspec(naked) void  AheadLib_waveOutSetPlaybackRate(void)
{
	__asm jmp pfnAheadLib_waveOutSetPlaybackRate;
}

extern "C" __declspec(naked) void  AheadLib_waveOutSetVolume(void)
{
	__asm jmp pfnAheadLib_waveOutSetVolume;
}

extern "C" __declspec(naked) void  AheadLib_waveOutUnprepareHeader(void)
{
	__asm jmp pfnAheadLib_waveOutUnprepareHeader;
}

extern "C" __declspec(naked) void  AheadLib_waveOutWrite(void)
{
	__asm jmp pfnAheadLib_waveOutWrite;
}

extern "C" __declspec(naked) void  AheadLib_wid32Message(void)
{
	__asm jmp pfnAheadLib_wid32Message;
}

extern "C" __declspec(naked) void  AheadLib_wod32Message(void)
{
	__asm jmp pfnAheadLib_wod32Message;
}
FARPROC GetRealApiAddress(LPCSTR lpProcName)
{
	FARPROC fpAddress = GetProcAddress(g_hRealModule, lpProcName);
	if (fpAddress == NULL)
	{
		char szResult[MAX_PATH];
		StringLib::GetPrintf("函数异常：%s", szResult, MAX_PATH, lpProcName);
		MessageBoxA(NULL, szResult, "AheadLib", MB_ICONSTOP);
		ExitProcess(0);
	}
	return fpAddress;
}
bool Init()
{
	g_hRealModule = LoadLibraryA("C:\\Windows\\SysWOW64\\winmm.dll");
	if (g_hRealModule == NULL)
	{
		MessageBoxA(NULL, "无法找到模块：winmm.dll", "AheadLib", MB_ICONSTOP);
		return false;
	}
	pfnAheadLib_Unnamed2 = GetRealApiAddress(MAKEINTRESOURCEA(2));
	pfnAheadLib_mciExecute = GetRealApiAddress("mciExecute");
	pfnAheadLib_CloseDriver = GetRealApiAddress("CloseDriver");
	pfnAheadLib_DefDriverProc = GetRealApiAddress("DefDriverProc");
	pfnAheadLib_DriverCallback = GetRealApiAddress("DriverCallback");
	pfnAheadLib_DrvGetModuleHandle = GetRealApiAddress("DrvGetModuleHandle");
	pfnAheadLib_GetDriverModuleHandle = GetRealApiAddress("GetDriverModuleHandle");
	pfnAheadLib_NotifyCallbackData = GetRealApiAddress("NotifyCallbackData");
	pfnAheadLib_OpenDriver = GetRealApiAddress("OpenDriver");
	pfnAheadLib_PlaySound = GetRealApiAddress("PlaySound");
	pfnAheadLib_PlaySoundA = GetRealApiAddress("PlaySoundA");
	pfnAheadLib_PlaySoundW = GetRealApiAddress("PlaySoundW");
	pfnAheadLib_SendDriverMessage = GetRealApiAddress("SendDriverMessage");
	pfnAheadLib_WOW32DriverCallback = GetRealApiAddress("WOW32DriverCallback");
	pfnAheadLib_WOW32ResolveMultiMediaHandle = GetRealApiAddress("WOW32ResolveMultiMediaHandle");
	pfnAheadLib_WOWAppExit = GetRealApiAddress("WOWAppExit");
	pfnAheadLib_aux32Message = GetRealApiAddress("aux32Message");
	pfnAheadLib_auxGetDevCapsA = GetRealApiAddress("auxGetDevCapsA");
	pfnAheadLib_auxGetDevCapsW = GetRealApiAddress("auxGetDevCapsW");
	pfnAheadLib_auxGetNumDevs = GetRealApiAddress("auxGetNumDevs");
	pfnAheadLib_auxGetVolume = GetRealApiAddress("auxGetVolume");
	pfnAheadLib_auxOutMessage = GetRealApiAddress("auxOutMessage");
	pfnAheadLib_auxSetVolume = GetRealApiAddress("auxSetVolume");
	pfnAheadLib_joy32Message = GetRealApiAddress("joy32Message");
	pfnAheadLib_joyConfigChanged = GetRealApiAddress("joyConfigChanged");
	pfnAheadLib_joyGetDevCapsA = GetRealApiAddress("joyGetDevCapsA");
	pfnAheadLib_joyGetDevCapsW = GetRealApiAddress("joyGetDevCapsW");
	pfnAheadLib_joyGetNumDevs = GetRealApiAddress("joyGetNumDevs");
	pfnAheadLib_joyGetPos = GetRealApiAddress("joyGetPos");
	pfnAheadLib_joyGetPosEx = GetRealApiAddress("joyGetPosEx");
	pfnAheadLib_joyGetThreshold = GetRealApiAddress("joyGetThreshold");
	pfnAheadLib_joyReleaseCapture = GetRealApiAddress("joyReleaseCapture");
	pfnAheadLib_joySetCapture = GetRealApiAddress("joySetCapture");
	pfnAheadLib_joySetThreshold = GetRealApiAddress("joySetThreshold");
	pfnAheadLib_mci32Message = GetRealApiAddress("mci32Message");
	pfnAheadLib_mciDriverNotify = GetRealApiAddress("mciDriverNotify");
	pfnAheadLib_mciDriverYield = GetRealApiAddress("mciDriverYield");
	pfnAheadLib_mciFreeCommandResource = GetRealApiAddress("mciFreeCommandResource");
	pfnAheadLib_mciGetCreatorTask = GetRealApiAddress("mciGetCreatorTask");
	pfnAheadLib_mciGetDeviceIDA = GetRealApiAddress("mciGetDeviceIDA");
	pfnAheadLib_mciGetDeviceIDFromElementIDA = GetRealApiAddress("mciGetDeviceIDFromElementIDA");
	pfnAheadLib_mciGetDeviceIDFromElementIDW = GetRealApiAddress("mciGetDeviceIDFromElementIDW");
	pfnAheadLib_mciGetDeviceIDW = GetRealApiAddress("mciGetDeviceIDW");
	pfnAheadLib_mciGetDriverData = GetRealApiAddress("mciGetDriverData");
	pfnAheadLib_mciGetErrorStringA = GetRealApiAddress("mciGetErrorStringA");
	pfnAheadLib_mciGetErrorStringW = GetRealApiAddress("mciGetErrorStringW");
	pfnAheadLib_mciGetYieldProc = GetRealApiAddress("mciGetYieldProc");
	pfnAheadLib_mciLoadCommandResource = GetRealApiAddress("mciLoadCommandResource");
	pfnAheadLib_mciSendCommandA = GetRealApiAddress("mciSendCommandA");
	pfnAheadLib_mciSendCommandW = GetRealApiAddress("mciSendCommandW");
	pfnAheadLib_mciSendStringA = GetRealApiAddress("mciSendStringA");
	pfnAheadLib_mciSendStringW = GetRealApiAddress("mciSendStringW");
	pfnAheadLib_mciSetDriverData = GetRealApiAddress("mciSetDriverData");
	pfnAheadLib_mciSetYieldProc = GetRealApiAddress("mciSetYieldProc");
	pfnAheadLib_mid32Message = GetRealApiAddress("mid32Message");
	pfnAheadLib_midiConnect = GetRealApiAddress("midiConnect");
	pfnAheadLib_midiDisconnect = GetRealApiAddress("midiDisconnect");
	pfnAheadLib_midiInAddBuffer = GetRealApiAddress("midiInAddBuffer");
	pfnAheadLib_midiInClose = GetRealApiAddress("midiInClose");
	pfnAheadLib_midiInGetDevCapsA = GetRealApiAddress("midiInGetDevCapsA");
	pfnAheadLib_midiInGetDevCapsW = GetRealApiAddress("midiInGetDevCapsW");
	pfnAheadLib_midiInGetErrorTextA = GetRealApiAddress("midiInGetErrorTextA");
	pfnAheadLib_midiInGetErrorTextW = GetRealApiAddress("midiInGetErrorTextW");
	pfnAheadLib_midiInGetID = GetRealApiAddress("midiInGetID");
	pfnAheadLib_midiInGetNumDevs = GetRealApiAddress("midiInGetNumDevs");
	pfnAheadLib_midiInMessage = GetRealApiAddress("midiInMessage");
	pfnAheadLib_midiInOpen = GetRealApiAddress("midiInOpen");
	pfnAheadLib_midiInPrepareHeader = GetRealApiAddress("midiInPrepareHeader");
	pfnAheadLib_midiInReset = GetRealApiAddress("midiInReset");
	pfnAheadLib_midiInStart = GetRealApiAddress("midiInStart");
	pfnAheadLib_midiInStop = GetRealApiAddress("midiInStop");
	pfnAheadLib_midiInUnprepareHeader = GetRealApiAddress("midiInUnprepareHeader");
	pfnAheadLib_midiOutCacheDrumPatches = GetRealApiAddress("midiOutCacheDrumPatches");
	pfnAheadLib_midiOutCachePatches = GetRealApiAddress("midiOutCachePatches");
	pfnAheadLib_midiOutClose = GetRealApiAddress("midiOutClose");
	pfnAheadLib_midiOutGetDevCapsA = GetRealApiAddress("midiOutGetDevCapsA");
	pfnAheadLib_midiOutGetDevCapsW = GetRealApiAddress("midiOutGetDevCapsW");
	pfnAheadLib_midiOutGetErrorTextA = GetRealApiAddress("midiOutGetErrorTextA");
	pfnAheadLib_midiOutGetErrorTextW = GetRealApiAddress("midiOutGetErrorTextW");
	pfnAheadLib_midiOutGetID = GetRealApiAddress("midiOutGetID");
	pfnAheadLib_midiOutGetNumDevs = GetRealApiAddress("midiOutGetNumDevs");
	pfnAheadLib_midiOutGetVolume = GetRealApiAddress("midiOutGetVolume");
	pfnAheadLib_midiOutLongMsg = GetRealApiAddress("midiOutLongMsg");
	pfnAheadLib_midiOutMessage = GetRealApiAddress("midiOutMessage");
	pfnAheadLib_midiOutOpen = GetRealApiAddress("midiOutOpen");
	pfnAheadLib_midiOutPrepareHeader = GetRealApiAddress("midiOutPrepareHeader");
	pfnAheadLib_midiOutReset = GetRealApiAddress("midiOutReset");
	pfnAheadLib_midiOutSetVolume = GetRealApiAddress("midiOutSetVolume");
	pfnAheadLib_midiOutShortMsg = GetRealApiAddress("midiOutShortMsg");
	pfnAheadLib_midiOutUnprepareHeader = GetRealApiAddress("midiOutUnprepareHeader");
	pfnAheadLib_midiStreamClose = GetRealApiAddress("midiStreamClose");
	pfnAheadLib_midiStreamOpen = GetRealApiAddress("midiStreamOpen");
	pfnAheadLib_midiStreamOut = GetRealApiAddress("midiStreamOut");
	pfnAheadLib_midiStreamPause = GetRealApiAddress("midiStreamPause");
	pfnAheadLib_midiStreamPosition = GetRealApiAddress("midiStreamPosition");
	pfnAheadLib_midiStreamProperty = GetRealApiAddress("midiStreamProperty");
	pfnAheadLib_midiStreamRestart = GetRealApiAddress("midiStreamRestart");
	pfnAheadLib_midiStreamStop = GetRealApiAddress("midiStreamStop");
	pfnAheadLib_mixerClose = GetRealApiAddress("mixerClose");
	pfnAheadLib_mixerGetControlDetailsA = GetRealApiAddress("mixerGetControlDetailsA");
	pfnAheadLib_mixerGetControlDetailsW = GetRealApiAddress("mixerGetControlDetailsW");
	pfnAheadLib_mixerGetDevCapsA = GetRealApiAddress("mixerGetDevCapsA");
	pfnAheadLib_mixerGetDevCapsW = GetRealApiAddress("mixerGetDevCapsW");
	pfnAheadLib_mixerGetID = GetRealApiAddress("mixerGetID");
	pfnAheadLib_mixerGetLineControlsA = GetRealApiAddress("mixerGetLineControlsA");
	pfnAheadLib_mixerGetLineControlsW = GetRealApiAddress("mixerGetLineControlsW");
	pfnAheadLib_mixerGetLineInfoA = GetRealApiAddress("mixerGetLineInfoA");
	pfnAheadLib_mixerGetLineInfoW = GetRealApiAddress("mixerGetLineInfoW");
	pfnAheadLib_mixerGetNumDevs = GetRealApiAddress("mixerGetNumDevs");
	pfnAheadLib_mixerMessage = GetRealApiAddress("mixerMessage");
	pfnAheadLib_mixerOpen = GetRealApiAddress("mixerOpen");
	pfnAheadLib_mixerSetControlDetails = GetRealApiAddress("mixerSetControlDetails");
	pfnAheadLib_mmDrvInstall = GetRealApiAddress("mmDrvInstall");
	pfnAheadLib_mmGetCurrentTask = GetRealApiAddress("mmGetCurrentTask");
	pfnAheadLib_mmTaskBlock = GetRealApiAddress("mmTaskBlock");
	pfnAheadLib_mmTaskCreate = GetRealApiAddress("mmTaskCreate");
	pfnAheadLib_mmTaskSignal = GetRealApiAddress("mmTaskSignal");
	pfnAheadLib_mmTaskYield = GetRealApiAddress("mmTaskYield");
	pfnAheadLib_mmioAdvance = GetRealApiAddress("mmioAdvance");
	pfnAheadLib_mmioAscend = GetRealApiAddress("mmioAscend");
	pfnAheadLib_mmioClose = GetRealApiAddress("mmioClose");
	pfnAheadLib_mmioCreateChunk = GetRealApiAddress("mmioCreateChunk");
	pfnAheadLib_mmioDescend = GetRealApiAddress("mmioDescend");
	pfnAheadLib_mmioFlush = GetRealApiAddress("mmioFlush");
	pfnAheadLib_mmioGetInfo = GetRealApiAddress("mmioGetInfo");
	pfnAheadLib_mmioInstallIOProcA = GetRealApiAddress("mmioInstallIOProcA");
	pfnAheadLib_mmioInstallIOProcW = GetRealApiAddress("mmioInstallIOProcW");
	pfnAheadLib_mmioOpenA = GetRealApiAddress("mmioOpenA");
	pfnAheadLib_mmioOpenW = GetRealApiAddress("mmioOpenW");
	pfnAheadLib_mmioRead = GetRealApiAddress("mmioRead");
	pfnAheadLib_mmioRenameA = GetRealApiAddress("mmioRenameA");
	pfnAheadLib_mmioRenameW = GetRealApiAddress("mmioRenameW");
	pfnAheadLib_mmioSeek = GetRealApiAddress("mmioSeek");
	pfnAheadLib_mmioSendMessage = GetRealApiAddress("mmioSendMessage");
	pfnAheadLib_mmioSetBuffer = GetRealApiAddress("mmioSetBuffer");
	pfnAheadLib_mmioSetInfo = GetRealApiAddress("mmioSetInfo");
	pfnAheadLib_mmioStringToFOURCCA = GetRealApiAddress("mmioStringToFOURCCA");
	pfnAheadLib_mmioStringToFOURCCW = GetRealApiAddress("mmioStringToFOURCCW");
	pfnAheadLib_mmioWrite = GetRealApiAddress("mmioWrite");
	pfnAheadLib_mmsystemGetVersion = GetRealApiAddress("mmsystemGetVersion");
	pfnAheadLib_mod32Message = GetRealApiAddress("mod32Message");
	pfnAheadLib_mxd32Message = GetRealApiAddress("mxd32Message");
	pfnAheadLib_sndPlaySoundA = GetRealApiAddress("sndPlaySoundA");
	pfnAheadLib_sndPlaySoundW = GetRealApiAddress("sndPlaySoundW");
	pfnAheadLib_tid32Message = GetRealApiAddress("tid32Message");
	pfnAheadLib_timeBeginPeriod = GetRealApiAddress("timeBeginPeriod");
	pfnAheadLib_timeEndPeriod = GetRealApiAddress("timeEndPeriod");
	pfnAheadLib_timeGetDevCaps = GetRealApiAddress("timeGetDevCaps");
	pfnAheadLib_timeGetSystemTime = GetRealApiAddress("timeGetSystemTime");
	pfnAheadLib_timeGetTime = GetRealApiAddress("timeGetTime");
	pfnAheadLib_timeKillEvent = GetRealApiAddress("timeKillEvent");
	pfnAheadLib_timeSetEvent = GetRealApiAddress("timeSetEvent");
	pfnAheadLib_waveInAddBuffer = GetRealApiAddress("waveInAddBuffer");
	pfnAheadLib_waveInClose = GetRealApiAddress("waveInClose");
	pfnAheadLib_waveInGetDevCapsA = GetRealApiAddress("waveInGetDevCapsA");
	pfnAheadLib_waveInGetDevCapsW = GetRealApiAddress("waveInGetDevCapsW");
	pfnAheadLib_waveInGetErrorTextA = GetRealApiAddress("waveInGetErrorTextA");
	pfnAheadLib_waveInGetErrorTextW = GetRealApiAddress("waveInGetErrorTextW");
	pfnAheadLib_waveInGetID = GetRealApiAddress("waveInGetID");
	pfnAheadLib_waveInGetNumDevs = GetRealApiAddress("waveInGetNumDevs");
	pfnAheadLib_waveInGetPosition = GetRealApiAddress("waveInGetPosition");
	pfnAheadLib_waveInMessage = GetRealApiAddress("waveInMessage");
	pfnAheadLib_waveInOpen = GetRealApiAddress("waveInOpen");
	pfnAheadLib_waveInPrepareHeader = GetRealApiAddress("waveInPrepareHeader");
	pfnAheadLib_waveInReset = GetRealApiAddress("waveInReset");
	pfnAheadLib_waveInStart = GetRealApiAddress("waveInStart");
	pfnAheadLib_waveInStop = GetRealApiAddress("waveInStop");
	pfnAheadLib_waveInUnprepareHeader = GetRealApiAddress("waveInUnprepareHeader");
	pfnAheadLib_waveOutBreakLoop = GetRealApiAddress("waveOutBreakLoop");
	pfnAheadLib_waveOutClose = GetRealApiAddress("waveOutClose");
	pfnAheadLib_waveOutGetDevCapsA = GetRealApiAddress("waveOutGetDevCapsA");
	pfnAheadLib_waveOutGetDevCapsW = GetRealApiAddress("waveOutGetDevCapsW");
	pfnAheadLib_waveOutGetErrorTextA = GetRealApiAddress("waveOutGetErrorTextA");
	pfnAheadLib_waveOutGetErrorTextW = GetRealApiAddress("waveOutGetErrorTextW");
	pfnAheadLib_waveOutGetID = GetRealApiAddress("waveOutGetID");
	pfnAheadLib_waveOutGetNumDevs = GetRealApiAddress("waveOutGetNumDevs");
	pfnAheadLib_waveOutGetPitch = GetRealApiAddress("waveOutGetPitch");
	pfnAheadLib_waveOutGetPlaybackRate = GetRealApiAddress("waveOutGetPlaybackRate");
	pfnAheadLib_waveOutGetPosition = GetRealApiAddress("waveOutGetPosition");
	pfnAheadLib_waveOutGetVolume = GetRealApiAddress("waveOutGetVolume");
	pfnAheadLib_waveOutMessage = GetRealApiAddress("waveOutMessage");
	pfnAheadLib_waveOutOpen = GetRealApiAddress("waveOutOpen");
	pfnAheadLib_waveOutPause = GetRealApiAddress("waveOutPause");
	pfnAheadLib_waveOutPrepareHeader = GetRealApiAddress("waveOutPrepareHeader");
	pfnAheadLib_waveOutReset = GetRealApiAddress("waveOutReset");
	pfnAheadLib_waveOutRestart = GetRealApiAddress("waveOutRestart");
	pfnAheadLib_waveOutSetPitch = GetRealApiAddress("waveOutSetPitch");
	pfnAheadLib_waveOutSetPlaybackRate = GetRealApiAddress("waveOutSetPlaybackRate");
	pfnAheadLib_waveOutSetVolume = GetRealApiAddress("waveOutSetVolume");
	pfnAheadLib_waveOutUnprepareHeader = GetRealApiAddress("waveOutUnprepareHeader");
	pfnAheadLib_waveOutWrite = GetRealApiAddress("waveOutWrite");
	pfnAheadLib_wid32Message = GetRealApiAddress("wid32Message");
	pfnAheadLib_wod32Message = GetRealApiAddress("wod32Message");
	return true;
}
void Free()
{
	if (g_hRealModule)
		FreeLibrary(g_hRealModule);
}
#pragma endregion

void __declspec(naked)HookFramework()
{
	__asm//保存现场
	{
		pushad
		pushfd
	}
	MessageBoxA(0, "Hook！", "提示", 0);
	__asm//恢复现场+跳转修复
	{
		popfd
		popad
		//jmp Hook.dwRecoverAddr; //跳到恢复区
	}
}

DWORD WINAPI ThreadProc(LPVOID lpThreadParameter)
{
	system("calc");
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		if (Init())
		{
			const char* szAppName = "Test.exe";//宿主进程名
			char szPathName[MAX_PATH]{ 0 };
			char szFileName[MAX_PATH]{ 0 };
			GetModuleFileNameA(NULL, szPathName, MAX_PATH);
			StringLib::GetFileName(szPathName, szFileName, MAX_PATH);
			if (lstrcmpiA(szFileName, szAppName) == 0)
			{
				HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
				if (hThread)
					CloseHandle(hThread);
			}
		}
		break;
	case DLL_PROCESS_DETACH:
		Free();
		break;
	}
	return TRUE;
}