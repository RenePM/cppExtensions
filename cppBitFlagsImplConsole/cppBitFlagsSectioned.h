#pragma once

// DLL EXPORT/IMPORT Interface Define 
// NOTE!! DONT FORGET TO REPLACE PART BEFORE "_" TO YOUR PROJECT NAME
#ifdef CPPBITFLAGSIMPLCONSOLE_EXPORTS
#   define CPPBITFLAGSIMPLCONSOLE_API    __declspec(dllexport)
#   define CPPBITFLAGSIMPLCONSOLE_FUNC   extern "C" __declspec(dllexport)
#   define CPPBITFLAGSIMPLCONSOLE_TEMPLATE
#else
#   define CPPBITFLAGSIMPLCONSOLE_API    __declspec(dllimport)
#   define CPPBITFLAGSIMPLCONSOLE_FUNC   extern "C" __declspec(dllimport)
#   define CPPBITFLAGSIMPLCONSOLE_TEMPLATE    extern
#endif

// Add includes here
#include <iostream>

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

    // Enum class used to provide template with a known enum class
    enum class enumClass : int
    {
        IS_FLAG_A = (1 << 0),
        IS_FLAG_B = (1 << 1),
        IS_FLAG_B = (1 << 2),
        IS_FLAG_B = (1 << 3),
        IS_FLAG_B = (1 << 4),
        IS_FLAG_B = (1 << 5),
        IS_FLAG_B = (1 << 6),
        IS_FLAG_B = (1 << 7),
    };


    /*
        Class used for handling bit operations on enums class

        CLASS TEMPLATE INPUTS:
            Tclass   : the enum class to use def. to the known type enumClass
            TdataType: The data type that the enum class handles def. int
    */
    template <class Tclass = enumClass, class TdataType = int> 
    class cppEnumBitFlag
    {
    
    public: // Members exposed/accessable to user/client
        /*
            Def. Constructor
            Function used for creating a newObject (newInstance) of cppEnumBitFlag
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS:
                    cppEnumBitFlag: newObject (newInstance) of cppEnumBitFlag
        */
        cppEnumBitFlag();

        /*
            Def. Copy Constructor
            Function used for creating a newObject (newInstance) that is a copy of otherObject (otherInstance) of otherClass
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS:
                    - otherClass_: Reference to otherClass that you want to create a copy of

                OUTPUTS: NONE

                RETURNS:
                    cppEnumBitFlag: newObject (newInstance) of cppEnumBitFlag, that is a copy of otherObject
        */
        cppEnumBitFlag(const cppEnumBitFlag& otherClass_);

        /*
            Destructor
            Function used for destroying thisObject (thisInstance) of cppEnumBitFlag
                STATUS: ?
                FUNCTION TEMPLATE INPUTS: NONE
                INPUTS: NONE

                OUTPUTS: NONE

                RETURNS: NONE
        */
        ~cppEnumBitFlag();

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
        Function used for creating a newObject (newInstance) of cppEnumBitFlag
            STATUS: ?
            FUNCTION TEMPLATE INPUTS: NONE
            INPUTS: NONE

            OUTPUTS: NONE

            RETURNS:
                cppEnumBitFlag: newObject (newInstance) of cppEnumBitFlag
    */
    cppEnumBitFlag::cppEnumBitFlag()
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
                cppEnumBitFlag: newObject (newInstance) of cppEnumBitFlag, that is a copy of otherObject
    */
    cppEnumBitFlag::cppEnumBitFlag(const cppEnumBitFlag& otherClass_)
    {

    }

    /*
        Destructor
        Function used for destroying thisObject (thisInstance) of cppEnumBitFlag
            STATUS: ?
            FUNCTION TEMPLATE INPUTS: NONE
            INPUTS: NONE

            OUTPUTS: NONE

            RETURNS: NONE
    */
    cppEnumBitFlag::~cppEnumBitFlag()
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
    void cppEnumBitFlag::somePubFunction()
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
    void cppEnumBitFlag::somePrivFunction()
    {

    }

}
//--- END [IMPLEMENTATION/DECLARATION] SECTION