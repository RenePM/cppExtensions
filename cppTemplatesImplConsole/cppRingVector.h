#pragma once

// DLL EXPORT/IMPORT Interface Define 
// NOTE!! DONT FORGET TO REPLACE PART BEHIND "_" TO YOUR PROJECT NAME
#ifdef CPPTEMPLATESIMPLCONSOLE_EXPORTS
#   define CPPTEMPLATESIMPLCONSOLE_API    __declspec(dllexport)
#   define CPPTEMPLATESIMPLCONSOLE_FUNC   extern "C" __declspec(dllexport)
#   define CPPTEMPLATESIMPLCONSOLE_TEMPLATE
#else
#   define CPPTEMPLATESIMPLCONSOLE_API    __declspec(dllimport)
#   define CPPTEMPLATESIMPLCONSOLE_FUNC   extern "C" __declspec(dllimport)
#   define CPPTEMPLATESIMPLCONSOLE_TEMPLATE    extern
#endif

#include <vector>

using namespace std;

//--- START [DESIGN/DEFINITION] SECTION
namespace rpmExt
{
    namespace io
    {
        /*
            C++ Templated Vector Implemented/Behaving as a Ring Buffer
            Ringbuffer (Type Of Relationship) implemented in one .h file but sectioned
            so the [IMPLEMENTATION/DECLARATION] section can be moved to a .cpp file for the
            .cpp-> .h paired form.
            Uses PIMPL Technique to allow thed templated class to be exported from a dll without exposing C++ STL (std)
        */
        class ringVector
        {
            /*
                Def. Constructor
            */
            ringVector();

            /*
                Copy Constructor
            */
            ringVector(const ringVector& otherVector_);

            /*
                Destructor
            */
            ~ringVector();

        };

    }
}
//--- END [DESIGN/DEFINITION] SECTION

//--- START [IMPLEMENTATION/DECLARATION] SECTION
namespace rpmExt
{
    namespace io
    {
        /*
            C++ Templated Vector Implemented/Behaving as a Ring Buffer
            Ringbuffer (Type Of Relationship) implemented in one .h file but sectioned
            so the [IMPLEMENTATION/DECLARATION] section can be moved to a .cpp file for the
            .cpp-> .h paired form.
            Uses PIMPL Technique to allow thed templated class to be exported from a dll without exposing C++ STL (std)
        */
        /*
            Def. Constructor
        */
        ringVector::ringVector()
        {

        }

        /*
            Copy Constructor
        */
        ringVector::ringVector(const ringVector& otherVector_)
        {

        }

        /*
            Destructor
        */
        ringVector::~ringVector()
        {

        }

    }
}
//--- END [IMPLEMENTATION/DECLARATION] SECTION
