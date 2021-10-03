#pragma once

// DLL EXPORT/IMPORT Interface Define 
// NOTE!! DONT FORGET TO REPLACE PART BEHIND "_" TO YOUR PROJECT NAME
#ifdef CPPDESIGNPATTERNSIMPLCONSOLE_EXPORTS
#   define CPPDESIGNPATTERNSIMPLCONSOLE_API    __declspec(dllexport)
#   define CPPDESIGNPATTERNSIMPLCONSOLE_FUNC   extern "C" __declspec(dllexport)
#   define CPPDESIGNPATTERNSIMPLCONSOLE_TEMPLATE
#else
#   define CPPDESIGNPATTERNSIMPLCONSOLE_API    __declspec(dllimport)
#   define CPPDESIGNPATTERNSIMPLCONSOLE_FUNC   extern "C" __declspec(dllimport)
#   define CPPDESIGNPATTERNSIMPLCONSOLE_TEMPLATE    extern
#endif


/*
	C++ Design Pattern
	Pointer To Implementation (PIMPL) implemented in one .h file but sectioned
	so the [IMPLEMENTATION/DECLARATION] section can be moved to a .cpp file for the
	.cpp-> .h paired form.
*/

// Add includes here
#include <string>

// Add using namespaces here
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