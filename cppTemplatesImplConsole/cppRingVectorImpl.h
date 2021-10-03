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
#include <vector>

// Add using namespaces here
using namespace std;

namespace rpmExt
{
    namespace io
    {
        /*
            C++ Class Template implemnted in one header (.h) file, hence
            DESIGN/DEFINITION and IMPLEMENTATION/DECLARATION is in same file
            
            C++ Templated Vector Implemented/Behaving as a Ring Buffer of Object of type T
            Ringbuffer (Type Of Relationship) implemented in one .h file but sectioned
            so the [IMPLEMENTATION/DECLARATION] section can be moved to a .cpp file for the
            .cpp-> .h paired form.
            Uses PIMPL Technique to allow thed templated class to be exported from a dll without exposing C++ STL (std)

            TEMPLATE INPUT:
                - ?
        */
        template <class T>
        class ringVector
        {
        public: // Members exposed/accessable to user/client

             /*
                Def. Constructor
                Function used for creating a newObject (newInstance) of ringVector
                    STATUS: ?
                    INPUTS: NONE

                    OUTPUTS: NONE

                    RETURNS:
                        ringVector: newObject (newInstance) of ringVector
            */
            ringVector()
            {

            }

            /*
                Def. Copy Constructor
                Function used for creating a newObject (newInstance) that is a copy of otherObject (otherInstance) of otherClass
                    STATUS: ?
                    INPUTS:
                        - otherClass_: Reference to otherClass that you want to create a copy of

                    OUTPUTS: NONE

                    RETURNS:
                        ringVector: newObject (newInstance) of ringVector, that is a copy of otherObject
            */
            ringVector(const ringVector& otherClass_)
            {

            }

            /*
                Destructor
                Function used for destroying thisObject (thisInstance) of ringVector
                    STATUS: ?
                    INPUTS: NONE

                    OUTPUTS: NONE

                    RETURNS: NONE
            */
            ~ringVector()
            {

            }

            /*
               Public Member functon
               Function used for ?
                   STATUS: ?
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

        };
    }
}