// cppDebugImplConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cppDebugImplConsole.h"
#include "cppDebug.h"

 #define DEBUG_FILE // Outcomment this flag to use debug file
 #define DEBUG_MSGBOX // Outcomment this flag to use debug msgbox
 //#define DEBUG_CONSOLE // Outcomment this flag to use console for debugging (NOT IMPLEMENTED)
 #define DEBUG_SCREEN // Outcomment this flag to use screen for debugging
using namespace rpmExt;

int main()
{
    // Create new debug handler
    
    
    std::cout << "Hello World!\n";
    
    // Run log file test
    //**logFileTests();
    
    // Run msgbox log test
    logMessageBoxTests();

    // Run Screen log test
    logScreenTests();

}

/*
    Function used to test log file debug functions
    STATUS: TESTED, OK
*/
void logFileTests()
{

#ifdef DEBUG_FILE
    // Create debug handler
    debug myDebug("debugLog.txt");

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
        "C++ Debug", "cppDebug.h", 49);

    myDebug.logFileClass(myDebug.formatMsg("logFileClass: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug");

    myDebug.logFileClassEx(myDebug.formatMsg("logFileClassEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug");

    myDebug.logFileClassLineNum(myDebug.formatMsg("logFileClassLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", 59);

    myDebug.logFileClassLineNumEx(myDebug.formatMsg("logFileClassLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", 61);

    myDebug.logFileClassFunction(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logFileClassFunction");

    myDebug.logFileClassFunctionEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logFileClassFunctionEx");

    myDebug.logFileClassFunctionLineNum(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logFileClassFunctionLineNum", 71);

    myDebug.logFileClassFunctionLineNumEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logFileClassFunctionLineNumEx", 73);

    myDebug.logFileCustomMessage(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logFileCustomMessage", 76,
        (debug::enumMessageFlags::IS_APP | debug::enumMessageFlags::IS_FILE));

#endif

    return;
}

/*
    Function used to test msgbox debug functions
    STATUS: TESTED, OK
*/
void logMessageBoxTests()
{

#ifdef DEBUG_MSGBOX
    // Create debug handler
    debug myDebug("");

    int testNum = 1;

    myDebug.logMessageBoxMessage(myDebug.formatMsg("logMessageBoxMessage: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug");

    myDebug.logMessageBoxMessageEx(myDebug.formatMsg("logMessageBoxMessageEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h");

    myDebug.logMessageBoxMessageLineNum(myDebug.formatMsg("logMessageBoxMessageLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", 103);

    myDebug.logMessageBoxMessageLineNumEx(myDebug.formatMsg("logMessageBoxMessageLineNumEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", 106);

    myDebug.logMessageBoxClass(myDebug.formatMsg("logMessageBoxClass: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug");

    myDebug.logMessageBoxClassEx(myDebug.formatMsg("logMessageBoxClassEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug");

    myDebug.logMessageBoxClassLineNum(myDebug.formatMsg("logMessageBoxClassLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", 43);

    myDebug.logMessageBoxClassLineNumEx(myDebug.formatMsg("logMessageBoxClassLineNumEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", 118);

    myDebug.logMessageBoxClassFunction(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logMessageBoxClassFunction");

    myDebug.logMessageBoxClassFunctionEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logMessageBoxClassFunctionEx");

    myDebug.logMessageBoxClassFunctionLineNum(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logMessageBoxClassFunctionLineNum", 127);

    myDebug.logMessageBoxClassFunctionLineNumEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logMessageBoxClassFunctionLineNumEx", 130);

    myDebug.logMessageBoxCustomMessage(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logMessageBoxCustomMessage", 133,
        (debug::enumMessageFlags::IS_APP | debug::enumMessageFlags::IS_FILE | debug::enumMessageFlags::IS_LINE));

#endif

    return;
}

/*
    Function used to test screen (std out) debug functions
    STATUS: TESTED, OK
*/
void logScreenTests()
{

#ifdef DEBUG_SCREEN
    // Create debug handler
    debug myDebug("");

    int testNum = 1;

    myDebug.logScreenMessage(myDebug.formatMsg("logScreenMessage: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug");

    myDebug.logScreenMessageEx(myDebug.formatMsg("logScreenMessageEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h");

    myDebug.logScreenMessageLineNum(myDebug.formatMsg("logScreenMessageLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", 163);

    myDebug.logScreenMessageLineNumEx(myDebug.formatMsg("logScreenMessageLineNumEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", 166);

    myDebug.logScreenClass(myDebug.formatMsg("logScreenClass: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug");

    myDebug.logScreenClassEx(myDebug.formatMsg("logScreenClassEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug");

    myDebug.logScreenClassLineNum(myDebug.formatMsg("logScreenClassLineNum: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", 175);

    myDebug.logScreenClassLineNumEx(myDebug.formatMsg("logScreenClassLineNumEx: Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", 178);

    myDebug.logScreenClassFunction(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logScreenClassFunction");

    myDebug.logScreenClassFunctionEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logScreenClassFunctionEx");

    myDebug.logScreenClassFunctionLineNum(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "debug", "logScreenClassFunctionLineNum", 187);

    myDebug.logScreenClassFunctionLineNumEx(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logScreenClassFunctionLineNumEx", 190);

    myDebug.logScreenCustomMessage(myDebug.formatMsg("Test num = %i, codename: %s Data address: 0x%X\r\n", testNum++, "FALCON", &myDebug),
        "C++ Debug", "cppDebug.h", "debug", "logScreenCustomMessage", 193,
        (debug::enumMessageFlags::IS_APP | debug::enumMessageFlags::IS_FILE | debug::enumMessageFlags::IS_LINE));

#endif

    return;
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
