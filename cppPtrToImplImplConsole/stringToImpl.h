#pragma once

// DLL EXPORT/IMPORT Interface Define 
// NOTE!! DONT FORGET TO REPLACE PART BEFORE "_" TO YOUR PROJECT NAME
#ifdef CPPTEMPLATESIMPLCONSOLE_EXPORTS
#   define CPPTEMPLATESIMPLCONSOLE_API    __declspec(dllexport)
#   define CPPTEMPLATESIMPLCONSOLE_FUNC   extern "C" __declspec(dllexport)
#   define CPPTEMPLATESIMPLCONSOLE_TEMPLATE
#else
#   define CPPTEMPLATESIMPLCONSOLE_API    __declspec(dllimport)
#   define CPPTEMPLATESIMPLCONSOLE_FUNC   extern "C" __declspec(dllimport)
#   define CPPTEMPLATESIMPLCONSOLE_TEMPLATE    extern
#endif

// Add includes here
#include <iostream>
#include <memory>
#include <string>

// Add using namespaces here
using namespace std;

//--- START [DESIGN/DEFINITION] SECTION stringToImpl
namespace rpmExt
{
    /*
        C++ Class Template implemnted in one header (.h) file, hence
        DESIGN/DEFINITION and IMPLEMENTATION/DECLARATION is in same file
    */

    /*
        Class used for handling hiding C++ STL std::string from user using PIMPL technique so the

        CLASS TEMPLATE INPUTS: T = the C++ STL object to hide
    */
    class stringToImpl
    {
    public: // Members exposed/accessable to user/client

         /*
            Def. Constructor
            Function used for creating a newObject (newInstance) of stringToImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS:
                    stringToImpl: newObject (newInstance) of stringToImpl
        */
        stringToImpl();

        /*
           Constructor
           Function used for creating a newObject (newInstance) of stringToImpl and contains a STL object to hide
               STATUS: ?
               FUNCTION TEMPLATE INPUTS: NONE
               INPUTS: NONE

               OUTPUTS: NONE

               RETURNS:
                   stringToImpl: newObject (newInstance) of stringToImpl
       */
        //**stringToImpl(const stringImpl& otherClass_);


        /*
            Def. Copy Constructor
            Function used for creating a newObject (newInstance) that is a copy of otherObject (otherInstance) of otherClass
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS:
                    - otherClass_: Reference to otherClass that you want to create a copy of

                OUTPUTS: NONE

                RETURNS:
                    stringToImpl: newObject (newInstance) of stringToImpl, that is a copy of otherObject
        */
        //**stringToImpl(const stringToImpl& otherClass_);

        /*
            Destructor
            Function used for destroying thisObject (thisInstance) of stringToImpl
            Unrequired since smart pointer takes care of destroying the pointer to stringImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS: NONE
        */
        ~stringToImpl();

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

        class stringImpl; // Forward declaration of the hidden stringImpl
        unique_ptr<stringToImpl::stringImpl> impl_; // Pointer to stringImpl object (the C++ STL container for string)

    };

}
//--- END [DESIGN/DEFINITION] SECTION stringToImpl


