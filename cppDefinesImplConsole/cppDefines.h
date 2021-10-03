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

#define	STRINGIFY(X)	STRINGIFY2(X)
#define STRINGIFY2(X)	X
#define DEFID	#pragma

#define CAT(X, Y)	CAT2(X, Y)
#define CAT2(X, Y)	X##Y


// DLL Interface
#define DLL_INTERFACE(ifName) DEFID ifName


DLL_INTERFACE(CPPBITFLAG)

#endif

//**#define BEGIN_DLL_INTERFACE(defId, ifName)	defId ifName#_EXPORTS
//**#define END_DLL_INTERAFCE(defId)	defId

// Access control defines
//**#define PUBLIC_SECTION
/*
#define	BEGIN_PUBLIC(sectionName)	DEFID region sectionName
#define END_PUBLIC(sectionName)	DEFID pragma endregion sectionName 
*/
#define BEGIN_SECTION //{ public
#define END_SECTION	//}

#define	CREATE_REGION(regionName)  { \
	DEFID region regionName \
	/* SOME TEXT*/ \
	DEFID endregion regionName \
	} 

// Bit manipulation

CREATE_REGION(TEST)

namespace PUBLIC_SETION

}

class cppDef
{
public:
	
	BEGIN_SECTION
		int x;
	END_SECTION
	/*
	BEGIN_PUBLIC
		int 10;
	END_PUBLIC
		*/
	/*
	BEGIN_DLL_INTERFACE(#ifdef, CPPBITFLAGS)
		int 10;
	END_DLL_INTERAFCE(#endif)
		*/
		#ifdef CPPBITFLAGS_EXPORTS

		#endif


private:
};
