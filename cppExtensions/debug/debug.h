#pragma once
#include <cstdio>
#include <fstream> // Req. by file handling
#include <iostream> // Reg. by file handling
#include <sstream> // Required to use string as stream
#include <string>  // Req. by string handling
#include <initializer_list> // used for variable ars
#include <stdarg.h> // Used for variable args

using namespace std;

namespace rpmClasses
{
    class debug
    {
        // Data struct that keep strack of last know debug location
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
        structDebugInfo myDeybugInfo; // data struct that keeps track of last know debug msg location

    public:
        ostringstream logMessage_; // String Stream used to create formatted strings

        // File mode ids
        enum class enumFileModes
        {
            IS_APPEND = ios::app,
            IS_BINARY = ios::binary,
            IS_READ = ios::in,
            IS_WRITE = ios::out,
            IS_APPEND_FROM_END = ios::ate,
            IS_OVERWRITE = ios::trunc
        };

        // Custom log message ids
        enum class enumMessageFlags
        {
            IS_LINE = (1 << 0),
            IS_APP = (1 << 1),
            IS_FILE = (1 << 2),
            IS_CLASS = (1 << 3),
            IS_FUNC = (1 << 4),
        };

        // public class properties
        ofstream logFile_;


        /*
            Allways place debug code in IN DEBUG CONDITION BLOCKS, so that it can be removed fast and effeciently when sw is released
            CopyPaste these DEBUG CONDITION FLAGS to your sw to ensure the debug code is removed on sw release just by commenting them.
        */
        // #define DEBUG_FILE // Outcomment this flag to use debug file
        // #define DEBUG_MSGBOX // Outcomment this flag to use debug msgbox
        // #define DEBUG_CONSOLE // Outcomment this flag to use console for debugging

        /*
            DEBUG CONDITION BLOCKS:
            #ifdef [DEBUG CONDITION FLAG]
                debug function calls....
            #endif
        */



        /*
            Constructor used to init pot. log file
            INPUT:
                logFileName_: Ptr to chr buf containing Name of log file to use, (DEF. NULL = dont use log file)

            OUTPUT:

            RETURN:
        */
        debug(string logFileName_ = "", enumFileModes openMode_ = enumFileModes::IS_APPEND)
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
        */

        template <typename T>
        void  formatMsg(T formatString_)
        {
            // Add next message
            logMessage_ << formatString_;
            return; //logMessage_.str();
        }

        template <typename T, typename... Args>
        string  formatMsg(string newMessage_, T formatString_, Args... args_)
        {
            //LPSTR  cMsg;
            int ix = 0;
            int stIx = 0;
            bool endOfString = false;

            //**sprintf_s(cMsg, sizeof(formatString_), args_...);

            // Conver c string to string
            //string newMessage(cMsg);

            /*
            // Loop thorugh args
            for each (Args arg in args_)
            {
                // Search for first or next format id
                ix = formatString_.find_first_of("%", ix + 1)

                // Was a format id located?


            }

            if (typeof(arg_) == std::string)
            {
                newMessage.append(arg_);
            }
            else
            {
                newMessage.append(to_string(arg_));
            }

            // Recursive call until all args has been read
            formatMsg(args...);
            */
            logMessage_ << formatString_;
            newMessage_ = logMessage_.str();
            // Recursive call until all args read
            formatMsg(args_...);

            return newMessage_;
         }

/*
        template <typename Args>
        string formatMsg(int numArgs_, ...)
        {
            string formatString;
            LPCSTR  cString;
            LPSTR cMsg;
            va_list args;
            
            va_start(args, numArgs_);
                
            formatString = va_arg(args, string);
            
            cString = formatString.c_str();

            sprintf_s(cMsg, formatString.length(), cString, args);

            // Convert the c string to c++ string
            string newMessage(cMsg);

            return newMessage;
        }
*/
/*
        template <typename T>
        string  formatMsg(T arg_)
        {
            if (typeof(arg_) == std::string)
            {
                return arg_;
            }
            else
            {
                return to_string(arg_);
            }
        }

        template <typename T, typename... Args>
        string  formatMsg(string formatString_, Args... args_)
        {
            LPSTR  cMsg;
            int ix = 0;
            int stIx = 0;
            bool endOfString = false;

            sprintf_s(cMsg, formatString_.length(), args_...);

            // Conver c string to string
            string newMessage(cMsg);
            
            /*
            // Loop thorugh args
            for each (Args arg in args_)
            {
                // Search for first or next format id
                ix = formatString_.find_first_of("%", ix + 1)

                // Was a format id located?
                

            }

            if (typeof(arg_) == std::string)
            {
                newMessage.append(arg_);
            }
            else
            {
                newMessage.append(to_string(arg_));
            }

            // Recursive call until all args has been read
            formatMsg(args...);
            */
        /*
            return newMessage;
        }
*/            
        //------------------
        // ------------ CODE LOG FUNCTION -------------

        //----------------------------
        // --------- CLASSLESS DEBUG LOG FUNCTIONS -----------
                /*
                    Function used to log a msg to log file, this can be used when logging global or local code that does not exist
                    in a class or function "file level code"
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
                myDeybugInfo.appName_ = appName_;
            }

            // Create msg senderId
            string senderId = myDeybugInfo.appName_;

            // Create formatted log message
            LPCSTR message = nullptr;
            LPSTR logMessage = nullptr;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific msg to log file, this can be used when logging global or local code that does not exist
            in a class or function "file level code"
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDeybugInfo.fileName_ = fileName_;
            }
            // Create msg senderId, appName::fileName
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDeybugInfo.fileName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a msg with line num to log file, this can be used when logging global or local code that does not exist
            in a class or function
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDeybugInfo.appName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific msg with line num to log file, this can be used when logging global or local code that does not exist
            in a class or function
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName
            string senderId = "[";
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.fileName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }



        /*
            Function used to log a classless function call process to log file
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDeybugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::functionName
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the log msg string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific classless function call process to log file
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.appName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDeybugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::functionName
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);
            senderId.append(myDeybugInfo.fileName_);
            senderId.append(objSeperator_);
            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the log msg string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a classless function call process to log file with line num specified
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDeybugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::functionName
            string senderId = "[";
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific classless function call process to log file with line num specified
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDeybugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::functionName w. def. obj seperator
            string senderId = "[";
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }



        //------------------------------------------
        // ------------- FUNCTIONS FOR CLASS FUNCTIONS DEBUG LOGGING -------------
                /*
                    Function used to log a msg regarding class, to log file,
                    this can be used when code that exists in a class but outside any functions.
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.className_ = className_;
            }

            // Create msg senderId, appName::className
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a location specific msg regarding class, to log file,
            this can be used when code that exists in a class but outside any functions.
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known fileName
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known fileName
                myDeybugInfo.className_ = className_;
            }

            // Create msg senderId, appName::fileName::className w. def obj seperator
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a msg with line num, regarding a class, to log file,
            this can be used when code that exists in a class but outside any functions.
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.className_ = className_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className w. def. obj seperator "::"
            string senderId = "[";

            // Add line num
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            // Add app name
            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific msg with line num, regarding a class, to log file,
            this can be used when code that exists in a class but outside any functions.
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has fileName been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has className been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]::appName::fileName::className w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }



        /*
            Function used to log a class::function call process to log file
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y-> Update last known class name 
                myDeybugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDeybugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::className::functionName
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the log msg string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific class::function call process to log file
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.appName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y-> Update last known function name 
                myDeybugInfo.functionName_ = functionName_;
            }

            // Create msg senderId, appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = myDeybugInfo.appName_;
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the log msg string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a class::function call process with line num to log file
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDeybugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::className::functionName w. def obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        /*
            Function used to log a more location specific class::function call process w. line num to log file
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
                myDeybugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDeybugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create msg senderId, [lineNum]appName::fileName::className::functionName w. def. obj seperator "::"
            string senderId = "[";
            senderId.append(to_string(myDeybugInfo.lineNum_));
            senderId.push_back(']');

            senderId.append(myDeybugInfo.appName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.fileName_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.className_);
            senderId.append(objSeperator_);

            senderId.append(myDeybugInfo.functionName_);

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }

        //--------------------------------------

        //------------ CUSTOM LOG MESSSAGE FUNCTIONS ---------------
                /*
                    Function used to log a custom log message, hence user specify what information to include in the message
                    INPUT:

                    OUTPUT:

                    RETURN:
                */
        void logMessageCustom(string formattedMsg_, string appName_ = "", string fileName_ = "", string className_ = "", string functionName_ = "", int lineNum_ = 0, enumMessageFlags messageFlags_ = enumMessageFlags::IS_APP, string objSeperator_ = "::")
        {
            // Has app name been specified?
            if (appName_ != "")
            {
                //Y->Update last known app name
                myDeybugInfo.appName_ = appName_;
            }

            // Has file name been specified?
            if (fileName_ != "")
            {
                //Y->Update last known file name
                myDeybugInfo.fileName_ = fileName_;
            }

            // Has class name been specified?
            if (className_ != "")
            {
                //Y->Update last known class name
                myDeybugInfo.className_ = className_;
            }

            // Has function name been specified?
            if (functionName_ != "")
            {
                //Y->Update last known function name
                myDeybugInfo.functionName_ = functionName_;
            }

            // Has lineNum been specified?
            if (lineNum_ > -1)
            {
                //Y-> Update last know line num
                myDeybugInfo.lineNum_ = lineNum_;
            }

            // Create custom msg senderId
            string senderId = "";

            // Look through message flags and construct specified message

            // Is use linenum bitflag set?
            if (((int)messageFlags_ && (int)enumMessageFlags::IS_LINE))
            {
                //Y->Add line num
                senderId = "[";
                senderId.append(to_string(myDeybugInfo.lineNum_));
                senderId.push_back(']');
            }

            // Is use app name bitflag set?
            if (((int)messageFlags_ && (int)enumMessageFlags::IS_APP))
            {
                //Y->Add app name
                senderId.append(myDeybugInfo.appName_);
                senderId.append(objSeperator_);
            }

            // Is use filename bitflag set?
            if (((int)messageFlags_ && (int)enumMessageFlags::IS_FILE))
            {
                //Y->Add file name
                senderId.append(myDeybugInfo.fileName_);
                senderId.append(objSeperator_);
            }

            // Is use class name bitflag set?
            if (((int)messageFlags_ && (int)enumMessageFlags::IS_CLASS))
            {
                //Y->Add class name
                senderId.append(myDeybugInfo.className_);
                senderId.append(objSeperator_);
            }

            // Is use function name bitflag set?
            if (((int)messageFlags_ && (int)enumMessageFlags::IS_FUNC))
            {
                //Y->Add func name
                senderId.append(myDeybugInfo.functionName_);
                senderId.append(objSeperator_);
            }

            // Is senderId valid?
            if (senderId.substr(senderId.length() - 2, 2) == "::")
            {
                //N-> Strip the last obj seperator
                senderId.pop_back();
                senderId.pop_back();
            }

            // Create formatted log message
            LPCSTR message;
            LPSTR logMessage;

            // Convert the string to a c string
            message = formattedMsg_.c_str();

            // Create the formatted log msg
            sprintf_s(logMessage, formattedMsg_.length(), message);

            // Log the message to file
            logFile_ << senderId << ": " << logMessage;

            return;
        }
        //----------------------------
    };
};
