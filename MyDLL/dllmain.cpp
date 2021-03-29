// dllmain.cpp : Defines the entry point for the DLL application.
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

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    char command[512] = { "whoami" };
    switch (ul_reason_for_call)
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
    }
    return TRUE;
}

