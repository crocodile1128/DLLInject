#include <stdio.h>
#include <Windows.h>

__declspec(dllexport) int __stdcall Func1(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
    return a + b;
} // end proc

__declspec(dllexport) void __stdcall ShowInformation(const char* msg)
{
    MessageBoxA(NULL, msg, "DLL Messagebox", MB_OK);
} // end proc

BOOL WINAPI DllMain(HINSTANCE hDllHandle, DWORD dwReason, LPVOID lpReserved)
{
    char command[512] = { "whoami" };

    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        MessageBoxA(NULL, "Attach", "WOW", MB_OK);

        system("cmd.exe /C C:\\Windows\\system32\\mspaint.exe");

        printf("Process attach. \n");
        break;

    case DLL_PROCESS_DETACH:
        printf("Process detach. \n");
        break;

    case DLL_THREAD_ATTACH:
        printf("Thread attach. \n");
        break;

    case DLL_THREAD_DETACH:
        printf("Thread detach. \n");
        break;
    } // end switch

    return TRUE;
} // end main