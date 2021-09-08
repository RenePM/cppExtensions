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
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        // Create debug handler
        debug myDebug("debugLog.txt");
        #ifdef DEBUG_FILE
        myDebug.logMessage_ << "Test num = " << 10 << " codename: " << "FALCON";
        myDebug.logFileMessage(myDebug.formatMsg("Test num = %i, codename: %s", 10, "FALCON"), "C++ Debug");
        #endif
        break;
    }
    return TRUE;
}

