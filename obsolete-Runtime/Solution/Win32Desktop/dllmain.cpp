#include <winsdkver.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <assert.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		BOOL ret = DisableThreadLibraryCalls(hModule);
		assert(ret != FALSE);
		break;
	}
	case DLL_PROCESS_DETACH:
	{
		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	default:
	{
		assert(0);
	}
	}
	return TRUE;
}

