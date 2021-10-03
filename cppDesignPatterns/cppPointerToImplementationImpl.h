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

// Add using namespaces here
using namespace std;

namespace rpmExt
{
    /*
        C++ Template Class Template implemnted in one header (.h) file, hence
        DESIGN/DEFINITION and IMPLEMENTATION/DECLARATION is in same file as
        recommended for templates

        Class used for ?

        CLASS TEMPLATE INPUTS: T = the C++ STL object to hide
    */
    template <class T>
    class ptrToImpl
    {
    public: // Members exposed/accessable to user/client

         /*
            Def. Constructor
            Function used for creating a newObject (newInstance) of ptrToImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS:
                    ptrToImpl: newObject (newInstance) of ptrToImpl
        */
        ptrToImpl()
        {
            // Init smart pointer
            this->impl_ = new T;
        }

        /*
           Constructor
           Function used for creating a newObject (newInstance) of ptrToImpl and contains a STL object to hide
               STATUS: ?
               FUNCTION TEMPLATE INPUTS: NONE
               INPUTS: NONE

               OUTPUTS: NONE

               RETURNS:
                   ptrToImpl: newObject (newInstance) of ptrToImpl
       */
        ptrToImpl(const T& otherClass_)
        {
            // Assign the smart pointer to a new smart pointer to the otherObject
            this->impl_ = make_unique<T>(otherClass_);

        }

        /*
            Def. Copy Constructor
            Function used for creating a newObject (newInstance) that is a copy of otherObject (otherInstance) of otherClass
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS:
                    - otherClass_: Reference to otherClass that you want to create a copy of

                OUTPUTS: NONE

                RETURNS:
                    ptrToImpl: newObject (newInstance) of ptrToImpl, that is a copy of otherObject
        */
        ptrToImpl(const ptrToImpl& otherClass_)
        {

        }

        /*
            Destructor
            Function used for destroying thisObject (thisInstance) of ptrToImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS: NONE
        */
        ~ptrToImpl()
        {

        }

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
        void somePubFunction()
        {

        }

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
        void somePrivFunction()
        {

        }

        class T;
        unique_ptr<T> impl_;

    };

}