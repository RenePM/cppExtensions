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

// TODO : Convert StringToImplSectioned to this org one header version.
// Add using namespaces here
using namespace std;

namespace rpmExt
{
    /*
        C++ Class Template implemnted in one header (.h) file, hence
        DESIGN/DEFINITION and IMPLEMENTATION/DECLARATION is in same file
    */


    /*
        Class used as container of hidden C++ STL std::string from user using PIMPL technique so the

    CLASS TEMPLATE INPUTS: T = the C++ STL object to hide
    */
    class stringImpl
    {
    public: // Members exposed/accessable to user/client

         /*
            Def. Constructor
            Function used for creating a newObject (newInstance) of stringImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS:
                    stringImpl: newObject (newInstance) of stringImpl
        */
        stringImpl()
        {

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
                    stringImpl: newObject (newInstance) of stringImpl, that is a copy of otherObject
        */
        stringImpl(const stringImpl& otherClass_)
        {

        }

        /*
            Destructor
            Function used for destroying thisObject (thisInstance) of stringImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS: NONE
        */
        ~stringImpl()
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

        string  string_;

    };

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
        stringToImpl()
        {
            // Init smart pointer
            this->impl_ = new stringImpl;
        }

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
        stringToImpl(const T& otherClass_)
        {
            // Assign the smart pointer to a new smart pointer to the otherObject
            this->impl_ = make_unique<stringImpl>(otherClass_);

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
                    stringToImpl: newObject (newInstance) of stringToImpl, that is a copy of otherObject
        */
        stringToImpl(const stringToImpl& otherClass_)
        {

        }

        /*
            Destructor
            Function used for destroying thisObject (thisInstance) of stringToImpl
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS: NONE
        */
        ~stringToImpl() = default
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

        class stringImpl;
        unique_ptr<stringImpl> impl_;

    };

}
