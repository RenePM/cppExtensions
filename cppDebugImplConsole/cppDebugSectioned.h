#pragma once

// DLL EXPORT/IMPORT Interface Define 
// NOTE!! DONT FORGET TO REPLACE PART BEFORE "_" TO YOUR PROJECT NAME
#ifdef CPPDEBUGIMPLCONSOLE_EXPORTS
#   define CPPDEBUGIMPLCONSOLE_API    __declspec(dllexport)
#   define CPPDEBUGIMPLCONSOLE_FUNC   extern "C" __declspec(dllexport)
#   define CPPDEBUGIMPLCONSOLE_TEMPLATE
#else
#   define CPPDEBUGIMPLCONSOLE_API    __declspec(dllimport)
#   define CPPDEBUGIMPLCONSOLE_FUNC   extern "C" __declspec(dllimport)
#   define CPPDEBUGIMPLCONSOLE_TEMPLATE    extern
#endif

// Add includes here

#include <cstdio>
#include <basetsd.h> // WIn Api types
#include <Windows.h> // WIn api types
#include <fstream> // Req. by file handling
#include <iostream> // Reg. by file handling
#include <sstream> // Required to use string as stream
#include <string>  // Req. by string handling
#include <initializer_list> // used for variable ars
#include <stdarg.h> // Used for variable args
#include <winnt.h> // required to make enums compatible with bit flags

using namespace std;

//--- START [DESIGN/DEFINITION] SECTION
namespace rpmExt
{
    /*
        C++ Class Template implemented in one header (.h) file but sectioned
        so the [IMPLEMENTATION/DECLARATION] section can be moved to a .cpp file for quick convert to
        .cpp-> .h paired form.
    */
    /*
        Class used for ?

        CLASS TEMPLATE INPUTS: NONE
    */
    class thisClass
    {
    public: // Members exposed/accessable to user/client
        // Data struct that keep track of last know debug location
        struct structDebugInfo
        {
            string appName_;
            string fileName_;
            string className_;
            string functionName_;
            int lineNum_;


            /*
                Constructor used to init data struct with def. values
            */
            structDebugInfo()
            {
                appName_ = "";
                fileName_ = "";
                className_ = "";
                functionName_ = "";
                lineNum_ = 0;
            }
        };

        // File mode ids
        enum class enumFileModes : int
        {
            IS_APPEND = ios::app,
            IS_BINARY = ios::binary,
            IS_READ = ios::in,
            IS_WRITE = ios::out,
            IS_APPEND_FROM_END = (ios::ate | ios::app),
            IS_OVERWRITE = ios::trunc
        };

        // enum bit flags for log messge detail       
        enum class enumMessageFlags : uint8_t
        {
            IS_LINE = (1 << 0),
            IS_APP = (1 << 1),
            IS_FILE = (1 << 2),
            IS_CLASS = (1 << 3),
            IS_FUNC = (1 << 4),
        };

        // ASSIGNMENT OPERATOR OVERLOADS (NOT ALLOWED FOR friend Class enums) (MUST BE MEMBER OF CLASS::FUNCTION :( )

        // COMPARISON OPERATOR OVERLOADS
        friend const bool operator== (const enumMessageFlags a_, const enumMessageFlags b_) { return (bool)((uint8_t)a_ == (uint8_t)b_); } // EQUAL TO, a_ == b_
        friend const bool operator== (const enumMessageFlags a_, const uint8_t b_) { return (bool)((uint8_t)a_ == b_); } // EQUAL TO, a_ == b_
        friend const bool operator!= (const enumMessageFlags a_, const enumMessageFlags b_) { return (bool)((uint8_t)a_ != (uint8_t)b_); } // NOT EQUAL TO, a_ != b_
        friend const bool operator!= (const enumMessageFlags a_, const uint8_t b_) { return (bool)((uint8_t)a_ != b_); } // NOT EQUAL TO, a_ != b_

        // LOGICAL OPERATOR OVERLOADS
        friend bool operator! (const enumMessageFlags a_) { return (bool)(!(uint8_t)a_); } // LOGICAL NEGATION (NOT/FLIP VALUE), !a_ ==> if a_ <= 0 => !a_ = true, else false
        friend bool operator&& (const enumMessageFlags a_, const enumMessageFlags b_) { return (bool)((uint8_t)a_ && (uint8_t)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
        friend bool operator&& (const enumMessageFlags a_, const uint8_t b_) { return (bool)((uint8_t)a_ && (uint8_t)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
        friend bool operator|| (const enumMessageFlags a_, const enumMessageFlags b_) { return (bool)((uint8_t)a_ || (uint8_t)b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false
        friend bool operator|| (const enumMessageFlags a_, const uint8_t b_) { return (bool)((uint8_t)a_ || b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false

        // BITWISE OPERATOR OVERLOADS
        friend enumMessageFlags operator~ (const enumMessageFlags a_) { return (enumMessageFlags)(~(uint8_t)a_); }// BITWISE NOT (NEGATE/INVERT/FLIP BITS), ~a_ ==> if Bit(n) = 1 the ~bit(n) = 0 and if Bit(n) = 0 then ~Bit(n) = 1
        friend enumMessageFlags operator| (const enumMessageFlags a_, const enumMessageFlags b_) { return (enumMessageFlags)((uint8_t)a_ | (uint8_t)b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
        friend enumMessageFlags operator| (const enumMessageFlags a_, const uint8_t b_) { return (enumMessageFlags)((uint8_t)a_ | b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
        friend enumMessageFlags operator& (const enumMessageFlags a_, const enumMessageFlags b_) { return (enumMessageFlags)((uint8_t)a_ & (uint8_t)b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
        friend enumMessageFlags operator& (const enumMessageFlags a_, const uint8_t b_) { return (enumMessageFlags)((uint8_t)a_ & b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
        friend enumMessageFlags operator^ (const enumMessageFlags a_, const enumMessageFlags b_) { return (enumMessageFlags)((uint8_t)a_ ^ (uint8_t)b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0
        friend enumMessageFlags operator^ (const enumMessageFlags a_, const uint8_t b_) { return (enumMessageFlags)((uint8_t)a_ ^ b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0

        // BITWISE ASSIGNEMNT OPERATORS
        friend enumMessageFlags& operator|= (const enumMessageFlags& a_, const enumMessageFlags b_) { return (enumMessageFlags&)((uint8_t&)a_ |= (uint8_t)b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
        friend enumMessageFlags& operator|= (const enumMessageFlags& a_, const uint8_t b_) { return (enumMessageFlags&)((uint8_t&)a_ |= b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
        friend enumMessageFlags& operator&= (const enumMessageFlags& a_, const enumMessageFlags b_) { return (enumMessageFlags&)((uint8_t&)a_ &= (uint8_t)b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
        friend enumMessageFlags& operator&= (const enumMessageFlags& a_, const uint8_t b_) { return (enumMessageFlags&)((uint8_t&)a_ &= b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
        friend enumMessageFlags& operator^= (const enumMessageFlags& a_, const enumMessageFlags b_) { return (enumMessageFlags&)((uint8_t&)a_ ^= (uint8_t)b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)
        friend enumMessageFlags& operator^= (const enumMessageFlags& a_, const uint8_t b_) { return (enumMessageFlags&)((uint8_t&)a_ ^= b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)

        /*
            Allways place debug code in IN DEBUG CONDITION BLOCKS, so that it can be removed fast and effeciently when sw is released
            CopyPaste these DEBUG CONDITION FLAGS to your sw to ensure the debug code is removed on sw release just by commenting them.
        */
        // #define DEBUG_FILE // Outcomment this flag to use debug file
        // #define DEBUG_MSGBOX // Outcomment this flag to use debug msgbox
        // #define DEBUG_CONSOLE // Outcomment this flag to use console for debugging (NOT IMPLEMENTED)
        // #define DEBUG_SCREEN // Outcomment this flag to use Screen (std out) for debugging
        /*
            DEBUG CONDITION BLOCKS:
            #ifdef [DEBUG CONDITION FLAG]
                debug function calls....
            #endif
        */

         /*
            Def. Constructor
            Function used for creating a newObject (newInstance) of thisClass
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS:
                    thisClass: newObject (newInstance) of thisClass
        */
        thisClass();

        /*
            Def. Copy Constructor
            Function used for creating a newObject (newInstance) that is a copy of otherObject (otherInstance) of otherClass
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS:
                    - otherClass_: Reference to otherClass that you want to create a copy of

                OUTPUTS: NONE

                RETURNS:
                    thisClass: newObject (newInstance) of thisClass, that is a copy of otherObject
        */
        thisClass(const thisClass& otherClass_);

        /*
            Destructor
            Function used for destroying thisObject (thisInstance) of thisClass
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS: NONE
        */
        ~thisClass();

        /*
           Public Member functon
           Function used for ?
               STATUS: ?
               FUNCTION TEMPLATE INPUTS: ?
               INPUTS:
                   - aValue_: ?
               OUTPUTS:
                   - oBValue_: ?

               RETURNS:
                   TYPE?: VALUES?
       */
        void somePubFunction();

    private: // Members hidden from user/client
        /*
           Private Member functon
           Function used for ?
               STATUS: ?
               FUNCTION TEMPLATE INPUTS: ?
               INPUTS:
                   - aValue_: ?
               OUTPUTS:
                   - oBValue_: ?

               RETURNS:
                   TYPE?: VALUES?
       */
        void somePrivFunction();

        structDebugInfo myDebugInfo; // data struct that keeps track of last know debug msg location
        ofstream logFile_; // file handler for log file

    };

}
//--- END [DESIGN/DEFINITION] SECTION

//--- START [IMPLEMENTATION/DECLARATION] SECTION
namespace rpmExt
{
    /*
        C++ Class Template implemented in one header (.h) file but sectioned
        so the [IMPLEMENTATION/DECLARATION] section can be moved to a .cpp file for quick convert to
        .cpp-> .h paired form.
    */

    // PUBLIC MEMBERS SECTION
    /*
        Def. Constructor
        Function used for creating a newObject (newInstance) of thisClass
            STATUS: ?
            FUNCTION TEMPLATE INPUTS: NONE
            INPUTS: NONE

            OUTPUTS: NONE

            RETURNS:
                thisClass: newObject (newInstance) of thisClass
    */
    thisClass::thisClass()
    {

    }

    /*
        Copy Constructor
        Function used for creating a newObject (newInstance) that is a copy of otherObject (otherInstance) of otherClass
            STATUS: ?
            FUNCTION TEMPLATE INPUTS: NONE
            INPUTS:
                - otherClass_: Reference to otherClass that you want to create a copy of

            OUTPUTS: NONE

            RETURNS:
                thisClass: newObject (newInstance) of thisClass, that is a copy of otherObject
    */
    thisClass::thisClass(const thisClass& otherClass_)
    {

    }

    /*
        Destructor
        Function used for destroying thisObject (thisInstance) of thisClass
            STATUS: ?
            FUNCTION TEMPLATE INPUTS: NONE
            INPUTS: NONE

            OUTPUTS: NONE

            RETURNS: NONE
    */
    thisClass::~thisClass()
    {

    }

    /*
       Public Members section
       Function used for ?
           STATUS: ?
           FUNCTION TEMPLATE INPUTS: ?
           INPUTS:
               - aValue_: ?
           OUTPUTS:
               - oBValue_: ?

           RETURNS:
               TYPE?: VALUES?
   */
    void thisClass::somePubFunction()
    {

    }

    // PRIVATE MEMBERS SECTION
    /*
       Private Member functon
       Function used for ?
           STATUS: ?
           FUNCTION TEMPLATE INPUTS: ?
           INPUTS:
               - aValue_: ?
           OUTPUTS:
               - oBValue_: ?

           RETURNS:
               TYPE?: VALUES?
   */
    void thisClass::somePrivFunction()
    {

    }

}
//--- END [IMPLEMENTATION/DECLARATION] SECTION