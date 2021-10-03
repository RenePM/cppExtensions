#pragma once

#ifndef CPPCLASSSECTIONED_H // INCLUDE GUARD, Ensure the Header is not redefined more then once (DONT FORGET TO CHANE NAME TO [fileName]_H
#define CPPCLASSSECTIONED_H

// DLL EXPORT/IMPORT Interface Define 
// NOTE!! DONT FORGET TO REPLACE PART BEFORE "_" TO YOUR PROJECT NAME
#pragma region DLL INTERFACE SECTION
#ifdef CPPTEMPLATESIMPLCONSOLE_EXPORTS
#   define CPPTEMPLATESIMPLCONSOLE_API    __declspec(dllexport)
#   define CPPTEMPLATESIMPLCONSOLE_FUNC   extern "C" __declspec(dllexport)
#   define CPPTEMPLATESIMPLCONSOLE_TEMPLATE
#else
#   define CPPTEMPLATESIMPLCONSOLE_API    __declspec(dllimport)
#   define CPPTEMPLATESIMPLCONSOLE_FUNC   extern "C" __declspec(dllimport)
#   define CPPTEMPLATESIMPLCONSOLE_TEMPLATE    extern
#endif
#pragma endregion

// Add includes here
#pragma region INCLUDES SECTION
#include <iostream>
#pragma endregion

// Add using namespaces here
#pragma region NAMESPACES SECTION
using namespace std;
#pragma endregion

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
        #pragma region PUBLIC DEFINITION SECTION
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
        #pragma endregion

    private: // Members hidden from user/client
        #pragma region PRIVATE DEFINITION SECTION
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
        #pragma endregion
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
    #pragma region PUBLIC DECLARATION SECTION
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
    #pragma endregion

    // PRIVATE MEMBERS SECTION
    #pragma region PRIVATE DECLARATION SECTION
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
    #pragma endregion
}
//--- END [IMPLEMENTATION/DECLARATION] SECTION
#endif