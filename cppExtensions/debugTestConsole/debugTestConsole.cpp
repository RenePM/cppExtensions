// debugTestConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "debug.h"

 #define DEBUG_FILE // Outcomment this flag to use debug file
// #define DEBUG_MSGBOX // Outcomment this flag to use debug msgbox
// #define DEBUG_CONSOLE // Outcomment this flag to use console for debugging
using namespace rpmClasses;

int main()
{
    // Create new debug handler
    
    
    std::cout << "Hello World!\n";
    // Create debug handler
    debug myDebug("debugLog.txt");
    
#ifdef DEBUG_FILE
    int testNum = 1;
    myDebug.logMessage_.flush();
    myDebug.logMessage_ << "Test num = " << 10 << " codename: " << "FALCON";
    
    myDebug.logFileMessage(myDebug.formatMsg("logFileMessage: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug), 
                                             "C++ Debug");

    myDebug.logFileMessageEx(myDebug.formatMsg("logFileMessageEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                             "C++ Debug", "cppDebug.h");

    myDebug.logFileMessageLineNum(myDebug.formatMsg("logFileMessageLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                                    "C++ Debug", 31);

    myDebug.logFileMessageLineNumEx(myDebug.formatMsg("logFileMessageLineNumEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                             "C++ Debug", "cppDebug.h", 34);

    myDebug.logFileClass(myDebug.formatMsg("logFileClass: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                             "C++ Debug", "debug");

    myDebug.logFileClassEx(myDebug.formatMsg("logFileClassEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                           "C++ Debug", "cppDebug.h", "debug");

    myDebug.logFileClassLineNum(myDebug.formatMsg("logFileClassLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                           "C++ Debug", "debug", 43);

    myDebug.logFileClassLineNumEx(myDebug.formatMsg("logFileClassLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                                  "C++ Debug", "cppDebug.h", "debug", 43);

    myDebug.logFileClassFunction(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                           "C++ Debug", "debug", "logFileClassFunction");

    myDebug.logFileClassFunctionEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                                     "C++ Debug", "debug", "logFileClassFunctionEx");

    myDebug.logFileClassFunctionLineNum(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                                   "C++ Debug", "debug", "logFileClassFunctionLineNum", 56);

    myDebug.logFileClassFunctionLineNumEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
                                                          "C++ Debug", "cppDebug.h", "debug", "logFileClassFunctionLineNumEx", 59);

    myDebug.logFileCustomMessage(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logFileCustomMessage", 62,
        (debug::enumMessageFlags::IS_APP | debug::enumMessageFlags::IS_FILE));

#endif
    

#ifdef DEBUG_FILE

#endif
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
