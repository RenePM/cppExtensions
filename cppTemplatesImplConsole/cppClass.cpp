#include "cppClass.h"

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
