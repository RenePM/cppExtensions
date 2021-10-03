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

namespace rpmExt
{
    class debug
    {
        // Data struct that keep track of last know debug location
        struct structDebugInfo
        {
            string appName_;
            string fileName_;
            string className_;
            string functionName_;
            int lineNum_;
            ostringstream message_;


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
                message_.flush();
            }
        };


    private:
        // private class Properties
        structDebugInfo myDebugInfo; // data struct that keeps track of last know debug msg location

    public:
        ostringstream logMessage_; // String Stream used to create formatted strings

        // File mode ids
        enum class enumFileModes : int
        {
            IS_APPEND = ios::app,
            IS_BINARY = ios::binary,
            IS_READ = ios::in,
            IS_WRITE = ios::out,
            IS_APPEND_FROM_END = (ios::ate|ios::app),
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


        // public class properties
        ofstream logFile_;


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
            Construtor used to init debug class without log file handling
        */
        debug()
        {
            // Assume no log file is used
        
        }
        
        /*
            Constructor used to init pot. log file
            STATUS: OK, TESTED
            INPUT:
                logFileName_: Ptr to chr buf containing Name of log file to use, (DEF. NULL = dont use log file)

            OUTPUT:

            RETURN:
        */
        debug(string logFileName_ = "", enumFileModes openMode_ = enumFileModes::IS_APPEND_FROM_END)
        {
            // has logFileName been specified?
            if (logFileName_ == "")
            {
                //N -> Assume no file logging is used to debug
                return;
            }

            // Assume Y-> Open the specified log file for specified mode
            logFile_.open(logFileName_, (std::ios_base::openmode)openMode_);
            
        }


        // Destructor
        ~debug()
        {
            // Has a log file been opened?
            if (logFile_.is_open())
            {
                //Y->Close it
                logFile_.close();
            }
        }


        // Helper Functions
        /*
            Function used to construct a formattedMsg like sprintf
            STATUS: OK, TESTED
            INPUT:
                message_: The message to format
                ...     : Variable arguments containing the vars for the formatted message

            OUTPUT:

            RETURN:
                string: String containing the resulting formatted message
        */
        string  formatMsg(string message_, ...)
        {
            string newMessage;
            // Create new const c string

            // Get formatted message inital size and dbl it to ensure the identified vars fits in the new formatted msg
            int messageSize = 2 * message_.length();
            int stringSize = messageSize;

            // Create variable arg list
            va_list args;

            // Loop until all args has been processed
            while (true)
            {
                newMessage.resize(messageSize);
                // Create the new string
                //**LPSTR cNewMessage = newMessage.c_str();
                // Get nextArg
                va_start(args, message_);
                // Get str len of thisArg
                stringSize = vsnprintf((char*)newMessage.c_str(), messageSize, message_.c_str(), args);
                va_end(args);

                // Has all args been read?
                if (stringSize > -1 && stringSize < messageSize)
                {
                    //Y->Resize output message to new size
                    newMessage.resize(stringSize);
                    return newMessage;
                }

                // Has a valid arg been found?
                if (stringSize > -1)
                {
                    // Y->Update message size
                    messageSize = stringSize + 1;
                }
                else // Assume arg not valid
                {
                    // Dbl the size of the message
                    messageSize *= 2;
                }
            }

        }
            
        //------------------
        // ------------ CODE LOG FUNCTION -------------

        //----------------------------
        // --------- CLASSLESS DEBUG LOG FUNCTIONS -----------
        /*
            Function used to log a msg to log file, this can be used when logging global or local code that does not exist
            in a class or function "file level code"
            STATUS: OK, TESTED
            INPUT:
                formattedMsg_: The message you want to log
                appName_     : App or Filename that log msg exists in

            OUTPUT:
                None

            RETURN:
                None
        */
        void logFileMessage(string formattedMsg_, string appName_ = "")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Create msg senderId
            string senderId = myDebugInfo.appName_;

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;
            
            return;
        }

        /*
            Function used to log a more location specific msg to log file, this can be used when logging global or local code that does not exist
            in a class or function "file level code"
            STATUS: OK, TESTED
            INPUT:
                formattedMsg_: The message you want to log
                appName_     : App or Filename that log msg exists in

            OUTPUT:
                None

            RETURN:
                None
        */
        void logFileMessageEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.fileName_ = fileName_;
            }
            // Create msg senderId, appName::fileName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.fileName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a msg with line num to log file, this can be used when logging global or local code that does not exist
            in a class or function
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileMessageLineNum(string formattedMsg_, string appName_ = "", int lineNum_ = -1)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDebugInfo.appName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific msg with line num to log file, this can be used when logging global or local code that does not exist
            in a class or function
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileMessageLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", int lineNum_ = -1, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }



        /*
            Function used to log a classless function call process to log file
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileFunction(string formattedMsg_, string appName_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific classless function call process to log file
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileFunctionEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a classless function call process to log file with line num specified
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileFunctionLineNum(string formattedMsg_, string appName_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::functionName
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific classless function call process to log file with line num specified
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileFunctionLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::functionName w. def. obj seperator
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }



        //------------------------------------------
        // ------------- FUNCTIONS FOR CLASS FUNCTIONS DEBUG LOGGING -------------
        /*
            Function used to log a msg regarding class, to log file,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClass(string formattedMsg_, string appName_ = "", string className_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Create msg senderId, appName::className
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a location specific msg regarding class, to log file,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.className_ = className_;
            }

            // Create msg senderId, appName::fileName::className w. def obj seperator
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a msg with line num, regarding a class, to log file,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassLineNum(string formattedMsg_, string appName_ = "", string className_ = "", int lineNum_ = -1, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className w. def. obj seperator "::"
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific msg with line num, regarding a class, to log file,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", int lineNum_ = -1, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName::className w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }



        /*
            Function used to log a class::function call process to log file
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassFunction(string formattedMsg_, string appName_ = "", string className_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y-> Update last known class name 
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::className::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific class::function call process to log file
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassFunctionEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a class::function call process with line num to log file
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassFunctionLineNum(string formattedMsg_, string appName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className::functionName w. def obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific class::function call process w. line num to log file
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logFileClassFunctionLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }

        //--------------------------------------

        //------------ CUSTOM LOG MESSSAGE FUNCTIONS ---------------
        /*
            Function used to log a custom log message to file, hence user specify what information to include in the message
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
//        void logFileCustomMessage(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, cppEnumBitFlag<enumMessageFlags, int> messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::")
        void logFileCustomMessage(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, enumMessageFlags messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create custom msg senderId
            string senderId = "";

            // Look through message flags and construct specified message

            // Is use linenum bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_LINE) == enumMessageFlags::IS_LINE)
            {
                //Y->Add line num
                senderId = "[";
                senderId.append(to_string(myDebugInfo.lineNum_));
                senderId.push_back(']');
            }

            // Is use app name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_APP) == enumMessageFlags::IS_APP)
            {
                //Y->Add app name
                senderId.append(myDebugInfo.appName_);
                senderId.append(objSeperator_);
            }

            // Is use filename bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_FILE) == enumMessageFlags::IS_FILE)
            {
                //Y->Add file name
                senderId.append(myDebugInfo.fileName_);
                senderId.append(objSeperator_);
            }

            // Is use class name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_CLASS) == enumMessageFlags::IS_CLASS)
            {
                //Y->Add class name
                senderId.append(myDebugInfo.className_);
                senderId.append(objSeperator_);
            }

            // Is use function name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_FUNC) == enumMessageFlags::IS_FUNC)
            {
                //Y->Add func name
                senderId.append(myDebugInfo.functionName_);
                senderId.append(objSeperator_);
            }

            // Is senderId valid?
            if (senderId.substr(senderId.length() - 2, 2) == "::")
            {
                //N-> Strip the last obj seperator
                senderId.pop_back();
                senderId.pop_back();
            }

            // Log the message to file
            logFile_ << senderId << ": " << formattedMsg_;

            return;
        }
        //----------------------------

        //------------- MESSAGE BOX LOG FUNCTIONS --------------------
        // --------- CLASSLESS DEBUG LOG FUNCTIONS -----------
        /*
            Function used to log a msg to msgbox, this can be used when logging global or local code that does not exist
            in a class or function "file level code"
            STATUS: OK, TESTED
            INPUT:
                formattedMsg_: The message you want to log
                appName_     : App or Filename that log msg exists in
                hWindow_     : Handle to Window that the message box should be shown in

            OUTPUT:
                None

            RETURN:
                None
        */
        void logMessageBoxMessage(string formattedMsg_, string appName_ = "", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Create msg senderId
            string senderId = myDebugInfo.appName_;
            
            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);
                       
            return;
        }

        /*
            Function used to log a more location specific msg to msg box, this can be used when logging global or local code that does not exist
            in a class or function "file level code"
            STATUS: OK, TESTED
            INPUT:
                formattedMsg_: The message you want to log
                appName_     : App or Filename that log msg exists in

            OUTPUT:
                None

            RETURN:
                None
        */
        void logMessageBoxMessageEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.fileName_ = fileName_;
            }
            // Create msg senderId, appName::fileName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.fileName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a msg with line num to msgbox, this can be used when logging global or local code that does not exist
            in a class or function
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxMessageLineNum(string formattedMsg_, string appName_ = "", int lineNum_ = -1, HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDebugInfo.appName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a more location specific msg with line num to msgbox, this can be used when logging global or local code that does not exist
            in a class or function
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxMessageLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", int lineNum_ = -1, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }



        /*
            Function used to log a classless function call process to msgbox
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxFunction(string formattedMsg_, string appName_ = "", string functionName_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a more location specific classless function call process to msgbox
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxFunctionEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string functionName_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a classless function call process to msgbox with line num specified
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxFunctionLineNum(string formattedMsg_, string appName_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::functionName
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a more location specific classless function call process to msgbox with line num specified
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxFunctionLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::functionName w. def. obj seperator
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }



        //------------------------------------------
        // ------------- FUNCTIONS FOR CLASS FUNCTIONS DEBUG LOGGING -------------
        /*
            Function used to log a msg regarding class, to msgbox,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClass(string formattedMsg_, string appName_ = "", string className_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Create msg senderId, appName::className
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to file
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a location specific msg regarding class, to msgbox,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.className_ = className_;
            }

            // Create msg senderId, appName::fileName::className w. def obj seperator
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a msg with line num, regarding a class, to msgbox,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassLineNum(string formattedMsg_, string appName_ = "", string className_ = "", int lineNum_ = -1, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className w. def. obj seperator "::"
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a more location specific msg with line num, regarding a class, to msgbox,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", int lineNum_ = -1, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName::className w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }



        /*
            Function used to log a class::function call process to msgbox
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassFunction(string formattedMsg_, string appName_ = "", string className_ = "", string functionName_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y-> Update last known class name 
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::className::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a more location specific class::function call process to msgbox
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassFunctionEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a class::function call process with line num to msgbox
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassFunctionLineNum(string formattedMsg_, string appName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className::functionName w. def obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        /*
            Function used to log a more location specific class::function call process w. line num to msgbox
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logMessageBoxClassFunctionLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);

            return;
        }

        //--------------------------------------

        //------------ CUSTOM LOG MESSSAGE BOX FUNCTIONS ---------------
        /*
            Function used to log a custom log message to msgbox, hence user specify what information to include in the message
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        //        void logFileCustomMessage(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, cppEnumBitFlag<enumMessageFlags, int> messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::")
        void logMessageBoxCustomMessage(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, enumMessageFlags messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::", HWND hWindow_ = NULL)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create custom msg senderId
            string senderId = "";

            // Look through message flags and construct specified message

            // Is use linenum bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_LINE) == enumMessageFlags::IS_LINE)
            {
                //Y->Add line num
                senderId = "[";
                senderId.append(to_string(myDebugInfo.lineNum_));
                senderId.push_back(']');
            }

            // Is use app name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_APP) == enumMessageFlags::IS_APP)
            {
                //Y->Add app name
                senderId.append(myDebugInfo.appName_);
                senderId.append(objSeperator_);
            }

            // Is use filename bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_FILE) == enumMessageFlags::IS_FILE)
            {
                //Y->Add file name
                senderId.append(myDebugInfo.fileName_);
                senderId.append(objSeperator_);
            }

            // Is use class name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_CLASS) == enumMessageFlags::IS_CLASS)
            {
                //Y->Add class name
                senderId.append(myDebugInfo.className_);
                senderId.append(objSeperator_);
            }

            // Is use function name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_FUNC) == enumMessageFlags::IS_FUNC)
            {
                //Y->Add func name
                senderId.append(myDebugInfo.functionName_);
                senderId.append(objSeperator_);
            }

            // Is senderId valid?
            if (senderId.substr(senderId.length() - 2, 2) == "::")
            {
                //N-> Strip the last obj seperator
                senderId.pop_back();
                senderId.pop_back();
            }

            // Log the message to msgbox
            ::MessageBoxA(hWindow_, (LPCSTR)formattedMsg_.c_str(), (LPCSTR)senderId.c_str(), MB_OK);
            
            return;
        }
        //----------------------------

        //-------------------- LOG TO SCREEN (STD OUT) FUNCTIONS --------------
        // --------- CLASSLESS DEBUG LOG FUNCTIONS -----------
        /*
            Function used to log a msg to screen (std out), this can be used when logging global or local code that does not exist
            in a class or function "file level code"
            STATUS: OK, TESTED
            INPUT:
                formattedMsg_: The message you want to log
                appName_     : App or Filename that log msg exists in

            OUTPUT:
                None

            RETURN:
                None
        */
        void logScreenMessage(string formattedMsg_, string appName_ = "")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Create msg senderId
            string senderId = myDebugInfo.appName_;

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific msg to screen (std out), this can be used when logging global or local code that does not exist
            in a class or function "file level code"
            STATUS: OK, TESTED
            INPUT:
                formattedMsg_: The message you want to log
                appName_     : App or Filename that log msg exists in

            OUTPUT:
                None

            RETURN:
                None
        */
        void logScreenMessageEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.fileName_ = fileName_;
            }
            // Create msg senderId, appName::fileName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.fileName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a msg with line num to screen (std out), this can be used when logging global or local code that does not exist
            in a class or function
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenMessageLineNum(string formattedMsg_, string appName_ = "", int lineNum_ = -1)
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDebugInfo.appName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific msg with line num to screen (std out), this can be used when logging global or local code that does not exist
            in a class or function
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenMessageLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", int lineNum_ = -1, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }



        /*
            Function used to log a classless function call process to screen (std out)
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenFunction(string formattedMsg_, string appName_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.functionName_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific classless function call process to screen (std out)
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenFunctionEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);
            senderId.append(myDebugInfo.functionName_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a classless function call process to screen (std out) with line num specified
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenFunctionLineNum(string formattedMsg_, string appName_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::functionName
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific classless function call process to screen (std out) with line num specified
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenFunctionLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::functionName w. def. obj seperator
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }



        //------------------------------------------
        // ------------- FUNCTIONS FOR CLASS FUNCTIONS DEBUG LOGGING -------------
        /*
            Function used to log a msg regarding class, to screen (std out),
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClass(string formattedMsg_, string appName_ = "", string className_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Create msg senderId, appName::className
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a location specific msg regarding class, to screen (std out),
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known fileName
                myDebugInfo.className_ = className_;
            }

            // Create msg senderId, appName::fileName::className w. def obj seperator
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a msg with line num, regarding a class, to screen,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassLineNum(string formattedMsg_, string appName_ = "", string className_ = "", int lineNum_ = -1, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className w. def. obj seperator "::"
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific msg with line num, regarding a class, to screen,
            this can be used when code that exists in a class but outside any functions.
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", int lineNum_ = -1, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName::className w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }



        /*
            Function used to log a class::function call process to screen (std out)
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassFunction(string formattedMsg_, string appName_ = "", string className_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y-> Update last known class name 
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::className::functionName
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific class::function call process to screen (std out)
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassFunctionEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDebugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = myDebugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to screen
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a class::function call process with line num to screen (std out)
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassFunctionLineNum(string formattedMsg_, string appName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className::functionName w. def obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        /*
            Function used to log a more location specific class::function call process w. line num to screen (std out)
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        void logScreenClassFunctionLineNumEx(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDebugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDebugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDebugInfo.functionName_);

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }

        //--------------------------------------

        //------------ CUSTOM LOG MESSSAGE FUNCTIONS ---------------
        /*
            Function used to log a custom log message to screen (std out), hence user specify what information to include in the message
            STATUS: OK, TESTED
            INPUT:

            OUTPUT:

            RETURN:
        */
        //        void logFileCustomMessage(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, cppEnumBitFlag<enumMessageFlags, int> messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::")
        void logScreenCustomMessage(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, enumMessageFlags messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDebugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDebugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDebugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDebugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDebugInfo.lineNum_ = lineNum_;
            }

            // Create custom msg senderId
            string senderId = "";

            // Look through message flags and construct specified message

            // Is use linenum bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_LINE) == enumMessageFlags::IS_LINE)
            {
                //Y->Add line num
                senderId = "[";
                senderId.append(to_string(myDebugInfo.lineNum_));
                senderId.push_back(']');
            }

            // Is use app name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_APP) == enumMessageFlags::IS_APP)
            {
                //Y->Add app name
                senderId.append(myDebugInfo.appName_);
                senderId.append(objSeperator_);
            }

            // Is use filename bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_FILE) == enumMessageFlags::IS_FILE)
            {
                //Y->Add file name
                senderId.append(myDebugInfo.fileName_);
                senderId.append(objSeperator_);
            }

            // Is use class name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_CLASS) == enumMessageFlags::IS_CLASS)
            {
                //Y->Add class name
                senderId.append(myDebugInfo.className_);
                senderId.append(objSeperator_);
            }

            // Is use function name bitflag set?
            if ((messageFlags_ & enumMessageFlags::IS_FUNC) == enumMessageFlags::IS_FUNC)
            {
                //Y->Add func name
                senderId.append(myDebugInfo.functionName_);
                senderId.append(objSeperator_);
            }

            // Is senderId valid?
            if (senderId.substr(senderId.length() - 2, 2) == "::")
            {
                //N-> Strip the last obj seperator
                senderId.pop_back();
                senderId.pop_back();
            }

            // Log the message to file
            std::cout << senderId << ": " << formattedMsg_;

            return;
        }
        //----------------------------
    };
};
