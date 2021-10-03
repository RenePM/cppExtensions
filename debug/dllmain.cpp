// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
using namespace std;
using namespace rpmClasses;

#define DEBUG_FILE

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    #ifdef DEBUG_FILE
        // Create debug handler
        debug myDebug("debugLog.txt");
    #endif

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            #ifdef DEBUG_FILE
            myDebug.logFileMessage(myDebug.formatMsg("DLL_PROCESS_ATTACH: hModule = 0x%X", hModule), "C++ Debug");
            #endif
            break;

        case DLL_THREAD_ATTACH:
            #ifdef DEBUG_FILE
            myDebug.logFileMessage(myDebug.formatMsg("DLL_THREAD_ATTACH: hModule = 0x%X", hModule), "C++ Debug");
            #endif
            break;

        case DLL_THREAD_DETACH:
            #ifdef DEBUG_FILE
            myDebug.logFileMessage(myDebug.formatMsg("DLL_THREAD_DETACH: hModule = 0x%X", hModule), "C++ Debug");
            #endif
            break;

        case DLL_PROCESS_DETACH:
            #ifdef DEBUG_FILE
            myDebug.logFileMessage(myDebug.formatMsg("DLL_PROCESS_DETACH: hModule = 0x%X", hModule), "C++ Debug");
            #endif
            break;

    }

    return TRUE;
}