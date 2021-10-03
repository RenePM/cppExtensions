#include "stringToImpl.h"
//**#include "stringImplementationImpl.h"

//--- START [DESIGN/DEFINITION] SECTION stringToImpl::stringImpl
namespace rpmExt
{
    /*
        C++ Class Template implemnted in one header (.h) file, hence
        DESIGN/DEFINITION and IMPLEMENTATION/DECLARATION is in same file
    */

    /*
        Class used for declaring the hidden stringImpl Container for C++ STL std::string from user using PIMPL technique so the
        The Declaration is required for stringToImpl to be able to create a pointer to the stringImpl class

        CLASS TEMPLATE INPUTS: T = the C++ STL object to hide
    */
    class stringToImpl::stringImpl
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
        //**stringImpl();

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
       //**stringImpl(const stringImpl& otherClass_);


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
       //**stringImpl(const stringToImpl& otherClass_);

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
       //**~stringImpl();

        // -- METHODS TO ACCESS THE HIDDEN C++ STL Types
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

        //**class stringImpl; // Forward declaration of the hidden stringImpl
        //**unique_ptr<stringImpl> impl_;
        string  string_; // The hidden C++ STL Type, std::string

    };



}
//--- END [DESIGN/DEFINITION] SECTION stringToImpl::stringImpl
// 
//---- START [IMPLEMENTATION/DECLARATION] SECTION stringToImpl::stringImpl
namespace rpmExt
{
    // PUBLIC Members exposed/accessable to user/client

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
    /*
    stringToImpl::stringImpl::stringImpl()
    {

    }
    */


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
    /*
    stringToImpl::stringImpl::stringImpl(const stringImpl& otherClass_)
    {

    }
    */


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
    /*
    stringToImpl::stringImpl::stringImpl(const stringImpl& otherClass_)
    {

    }
    */

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
    //**stringToImpl::stringImpl::~stringImpl();

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

    void stringToImpl::stringImpl::somePubFunction()
    {
        /* WILL RESULT IN LINKER ERROR IF stringToImpl->impl_->somePubFunction is called but
           not implemented ;)
        */

    }

    // PRIVATE Members hidden from user/client
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
    void stringToImpl::stringImpl::somePrivFunction()
    {

    }
}
//---- END [IMPLEMENTATION/DECLARATION] SECTION stringToImpl::stringImpl

//--- START [IMPLEMENTATION/DECLARATION] SECTION stringToImpl
using namespace rpmExt;
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


    // PUBLIC Members exposed/accessable to user/client

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
    stringToImpl::stringToImpl() : impl_(make_unique<stringToImpl::stringImpl>()) 
    {
        // Init smart pointer
        //**this->impl_ = new unique_ptr<stringToImpl::stringImpl>;
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
    //**stringToImpl::stringToImpl(const stringImpl& otherClass_)
   /*
    {
        // Assign the smart pointer to a new smart pointer to the otherObject
        this->impl_ = make_unique<stringImpl>(otherClass_);

    }
    */

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
    /*
    stringToImpl::stringToImpl(const stringToImpl& otherClass_)
    {

    }
    */

    /*
        Destructor
        Function used for destroying thisObject (thisInstance) of stringToImpl
            STATUS: ?
            FUNCTION TEMPLATE INPUTS: NONE
            INPUTS: NONE

            OUTPUTS: NONE

            RETURNS: NONE
    */
    stringToImpl::~stringToImpl() = default;

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
    void stringToImpl::somePubFunction()
    {
        this->impl_->somePubFunction();
    }

    // PRIVATE Members hidden from user/client
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
    void stringToImpl::somePrivFunction()
    {
        
    }

}
//--- END [IMPLEMENTATION/DECLARATION] SECTION stringToImpl
