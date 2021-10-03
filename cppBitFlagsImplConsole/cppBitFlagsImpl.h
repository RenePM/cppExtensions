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

// Add using namespaces here
using namespace std;

/*
    Template class Used to handle bitwise operations on enum classes containing bit flags fx. create a class of int flags
    TEMPLATE INPUT:
        Tclass = The enum class
        TdataType = the data type of enum class "NOTE! enum must enherit this data type that suits the amount of flags fx. 8 flags shlould be uint8_t, 16 flags, uint16_t etc...

    enum class enumClass : int
    {
        IS_FLAG_A = 1<<0,
        IS_FLAG_B = 1<<1,
        .....        
    }

    cppEnumBitFlag<enumClass, int> myBitFlag;

    // As function arg
    void myFunc(cppEnumBitFlag<enumClass, int> myFlag_, ....)

    TO USE cppBitFlags in your project you must either :
    A. Refernce this h file in your project,
    Right click your project
        - Select Configuration Properties->C/C++->Genereal
            - Click Additional Include Directories
                - Choose location of this file
        - NOTE: Best solution since the project will always have a update version of the file

    B. copy/paste this file to your project 
        - Copy/paste the file from outside of visual studio
          to the project folder of project that requires this bit flags handling
        - NOTE!! Is a quick and dirty solution but hard to keep the file uptodate since
          you need to copy/paste each time you modify the origrnal file
*/

// DLL EXPORT/IMPORT Define
/*
// Not used because this templated class cannot be placed in a dll file since it takes
// "undefined template args", but feel free to use this define to create your dll's, or give it i try for yourself :P
#ifdef CPPBITFLAGS_EXPORTS
#define CPP_BITFLAGS_API    __declspec(dllexport)
#define CPP_BITFLAGS_FUNC   extern "C" __declspec(dllexport)
#else
#define CPP_BITFLAGS_API    __declspec(dllimport)
#define CPP_BITFLAGS_FUNC   extern "C" __declspec(dllimport)
#endif
*/

namespace rpmExt
{
    /*
        TEMPLATE INPUTS
            Tclass: the enum class to use
            TdataType: The data type that the enum class handles
    */
    template <class Tclass, class TdataType>
    class cppEnumBitFlag
    {

    private:
        Tclass   thisFlag_; // keep trak of thisFlags value

    public:

        /*
            Def. Constructor, ensures that the class can be initialized
        */
        cppEnumBitFlag()
        {
            thisFlag_ = 0;
            return;
        }

        cppEnumBitFlag(const cppEnumBitFlag<Tclass, TdataType>& flag_)
        {
            // Update thisFlag and return
            thisFlag_ = flag_.thisFlag_;
            return;
        }

        cppEnumBitFlag(const Tclass flag_)
        {
            // Update thisFlag and return
            thisFlag_ = flag_;
            return;
        }

        cppEnumBitFlag(const TdataType flag_)
        {
            // Update thisFlag and return
            thisFlag_ = (Tclass)flag_;
            return;
        }

        // Get function
        /*
            Function used to get thisFlag
            INPUT:

            OUTPUT:

            RETURN:
                Tclass: The value of thisFlag
        */
        Tclass get()
        {
            // return thisFlag
            return thisFlag_;
        }


        // ASSIGNMENT OPERATOR OVERLOADS
        //**cppEnumBitFlag& operator= (const )
        cppEnumBitFlag& operator= (const cppEnumBitFlag<Tclass, TdataType> flag_)
        {
            // Is this self assignemnt or object?
            if (thisFlag_ == flag_.thisFlag_)
            {
                //Y->Just forced exit nothing to assign
                // Return ref to thisObject
                return *this;
            }

            //Assume N-> Update thisFlag and return result
            thisFlag_ = flag_.thisFlag_;
            // Return ref to thisObject
            return *this;
        }

        cppEnumBitFlag& operator= (const Tclass flag_)
        {
            // Is this self assignemnt?
            if (this->thisFlag_ == flag_)
            {
                //Y->forced exit nothing to assign
                // Return ref to thisObject
                return *this;
            }

            //Assume N-> Update thisFlag and return result
            thisFlag_ = flag_;
            // Return ref to thisObject
            return *this;
        }

        cppEnumBitFlag& operator= (const TdataType flag_)
        {
            // Is this self assignemnt?
            if (this->thisFlag_ == (Tclass)flag_)
            {
                //Y->Just forced exit nothing to assign
                // Return ref to thisObject
                return *this;
            }

            // Update thisFlag
            thisFlag_ = (Tclass)flag_;
            // Return ref to thisObject
            return *this;
        }

        // COMPARISON OPERATOR
        const bool operator== (const Tclass flag_) { return (bool)((TdataType)thisFlag_ == (TdataType)flag_); } // EQUAL TO, thisFlag == flag
        const bool operator== (const TdataType flag_) { return (bool)((TdataType)thisFlag_ == flag_); } // EQUAL TO, thisFlag == flag
        const bool operator!= (const Tclass flag_) { return (bool)((TdataType)thisFlag_ != (TdataType)flag_); } // NOT EQUAL TO, thisFlag != flag
        const bool operator!= (const TdataType flag_) { return (bool)((TdataType)thisFlag_ != flag_); } // NOT EQUAL TO, thisFlag != flag

        // LOGICAL OPERATOR OVERLOADS
        bool operator! () { return (bool)(!(TdataType)thisFlag_); } // LOGICAL NEGATION (NOT)
        bool operator&& (const Tclass flag_) { return (bool)((TdataType)thisFlag_ && (TdataType)flag_); } // LOGICAL AND
        bool operator&& (const TdataType flag_) { return (bool)((TdataType)thisFlag_ && flag_); } // LOGICAL AND
        bool operator|| (const Tclass flag_) { return (bool)((TdataType)thisFlag_ || (TdataType)flag_); } // LOGICAL OR
        bool operator|| (const TdataType flag_) { return (bool)((TdataType)thisFlag_ || flag_); } // LOGICAL OR

        // BITWISE OPERATORS OVERLOADS
        Tclass operator~() { return (Tclass)(~(TdataType)thisFlag_); } // BITWISE NOT/NEGATE (INVERT/FLIP BITS)
        Tclass operator| (const Tclass flag_) { return (Tclass)((TdataType)thisFlag_ | (TdataType)flag_); } // BITWISE OR
        Tclass operator| (const TdataType flag_) { return (Tclass)((TdataType)thisFlag_ | flag_); } // BITWISE OR
        Tclass operator& (const Tclass flag_) { return (Tclass)((TdataType)thisFlag_ & (TdataType)flag_); } // BITWISE AND
        Tclass operator& (const TdataType flag_) { return (Tclass)((TdataType)thisFlag_ & flag_); } // BITWISE AND
        Tclass operator^ (const Tclass flag_) { return (Tclass)((TdataType)thisFlag_ ^ (TdataType)flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1
        Tclass operator^ (const TdataType flag_) { return (Tclass)((TdataType)thisFlag_ ^ flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1

        //BITWISE ASSIGNEMNT OPERATOR OVERLOADS
        Tclass& operator|= (const Tclass flag_) { return (Tclass&)((TdataType&)thisFlag_ |= (TdataType)flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
        Tclass& operator|= (const TdataType flag_) { return (Tclass&)((TdataType&)thisFlag_ |= flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
        Tclass& operator&= (const Tclass flag_) { return (Tclass&)((TdataType&)thisFlag_ &= (TdataType)flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        Tclass& operator&= (const TdataType flag_) { return (Tclass&)((TdataType&)thisFlag_ &= flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        Tclass& operator^= (const Tclass flag_) { return (Tclass&)((TdataType&)thisFlag_ ^= (TdataType)flag_); } // BITWISE XOR ASSIGNEMT (BITWISE TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)
        Tclass& operator^= (const TdataType flag_) { return (Tclass&)((TdataType&)thisFlag_ ^= flag_); } // BITWISE XOR ASSIGNEMT (BITWISE TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

        // BIT MANIPULATION
        /*
            Function used to set bits (specified by flag_) in thisFlag
            INPUT:
                flag_: flag containing bit mask specifing bits to set
            OUTPUT:

            RETURN:
                Tclass: the new value of thisFlag
        */
        Tclass   setBits(const Tclass flag_)
        {
            return (thisFlag_ |= flag_);
        }
        Tclass   setBits(const TdataType flag_)
        {
            return (thisFlag_ |= flag_);
        }

        /*
            Function used to set a specific bit (specified by bitIx) in thisFlag
            INPUT:
                bitIx_: bit ix of bit to set

            OUTPUT:

            RETURN:
                Tclass: the new value of thisFlag
        */
        Tclass   setBit(const TdataType bitIx_ = 0)
        {
            return (thisFlag_ |= ((Tclass)(1 << bitIx_)));
        }

        /*
            Function used to clear bits (specified by flag_) in thisFlag
            INPUT:
                flag_: flag containing bit mask specifing bits to clear

            OUTPUT:

            RETURN:
                Tclass: new value of thisFlag
        */
        Tclass   clearBits(const Tclass flag_)
        {
            return (thisFlag_ &= ~flag_);
        }
        Tclass   clearBits(const TdataType flag_)
        {
            return (thisFlag_ &= ~(Tclass)flag_);
        }

        /*
            Function used to clear a specific bit (specified by bitIx) in thisFlag
            INPUT :
                bitIx_: bit ix of bit to clear

            OUTPUT :

            RETURN :
                Tclass: new value of thisFlag
        */
        Tclass   clearBit(const TdataType bitIx_ = 0)
        {
            return (thisFlag_ &= (~(Tclass)(1 << bitIx_)));
        }

        /*
            Function used to toggle bits (specified by flag) in thisFlag
            INPUT :
                flag_: flag containing bit mask specifying bits to toggle

            OUTPUT :

            RETURN :
                Tclass: new value of thisFlag
        */
        Tclass   toggleBits(const Tclass flag_)
        {
            return (thisFlag_ ^= flag_);
        }
        Tclass   toggleBits(const TdataType flag_)
        {
            return (thisFlag_ ^= (Tclass)flag_);
        }

        /*
            Function used to toggle a specific bit (specified by bitIx) in thisFlag
            INPUT :
                bitIx_: bit ix of bit to toggle
            OUTPUT :

            RETURN :
                Tclass: new value of thisFlag

        */
        Tclass   toggleBit(const TdataType bitIx_ = 0)
        {
            return (thisFlag_ ^= ((Tclass)(1 << bitIx_)));
        }

        /*
            Function used to set bits (specified by flag) in thisFlag, to specified state
            INPUT :
                flag_       : flag containing bit mask specifying bits to set to specified state
                reservMask_ : bit mask specifying the reserved bit, hence DONT TOUCH bits "READ ONLY"

            OUTPUT :

            RETURN :
                Tclass: new value of thisFlag
        */
        Tclass   configBits(const Tclass flag_, const Tclass reservMask_)
        {
            // Clear all non reserved bits
            thisFlag_ &= reservMask_;

            // Set the specifed bits and return result
            return (thisFlag_ |= flag_);
        }
        Tclass   configBits(const TdataType flag_, const TdataType reservMask_)
        {
            // Clear all non reserved bits
            thisFlag_ &= (Tclass)reservMask_;

            // Set the specifed bits and return result
            return (thisFlag_ |= (Tclass)flag_);
        }

        // BIT COMPARE TESTS
        /*
            Function used to check if one or more specific bit flag is set (BIT ON TEST)
            INPUT:
                flag_: flag containing bit mask specifying bits to check

            OUTPUT

            RETURN:
                bool: T = Bit is set(1), F = bit is cleared(0)
        */
        bool    isSet(const Tclass flag_)
        {
            // Return result of BITWISE AND
            return (bool)(thisFlag_ & flag_);
        }
        bool    isSetHex(const TdataType flag_)
        {
            // Return result of BITWISE AND
            return (bool)((TdataType)thisFlag_ & flag_);
        }

        /*
            Function used to check if a specific bit is set (BIT n ON TEST)
            INPUT:
                bitIx_: bit ix for bit to check

            OUTPUT:

            RETURN:
                bool: T = Bit is set(1), F = bit is cleared(0)
        */
        bool    isSet(const TdataType bitIx_ = 0)
        {
            // Return result of BITWISE AND
            return (bool)((TdataType)thisFlag_ & ((TdataType)(1 << bitIx_)));
        }


        /*
            Function used to check if one or more specific bit flag is cleared (BIT OFF TEST)
            INPUT:
                flag_: flag containing bit mask specifying bits to check

            OUTPUT

            RETURN:
                bool: T = Bit is cleared(0), F = bit is set(1)
        */
        bool    isClear(const Tclass flag_)
        {
            // Return result of BITWISE AND        
            return (bool)(thisFlag_ & ~flag_);
        }
        bool    isClearHex(const TdataType flag_)
        {
            // Return result of BITWISE AND, thisFlag is casted as TdataTYpe because there is no operator overload for a & ~b        
            return (bool)((TdataType)thisFlag_ & ~flag_);
        }

        /*
            Function used to check if a specific bit is cleared (BIT n OFF TEST)
            INPUT:
                bitIx_: bit ix for bit to check

            OUTPUT:

            RETURN:
                bool: T = Bit is cleared(0), F = Bit is set(1)
        */
        bool    isClear(const TdataType bitIx_ = 0)
        {
            // Return result of BITWISE AND, 
            /*
                thisFlag is casted as TdataTYpe because operator overload dont work inside class
                where the Operator is overloaded ??
            */
            return (bool)((TdataType)thisFlag_ & (~(TdataType)(1 << bitIx_)));
        }

    };

    /*
    ENUM OVERLOAD SOLUTION: Copy - paste the operator overload functions template beneath to a location beneath the your enum class and replace the T with enum name and TdataType with enum data type!!
    NOTE!!If enum is a member of another class add friend in front on the operator overload function or c++ will assue the overload is for the parrentClass of enum!!
    NOTE!!Make sure TdataType is a data type that is big enough (bit size wise) for all the bit flags needed by your enum, fx. int typ. has 32 bits so thats 32 bit flags.
    HINT!! WHEN UING FIND-REPLACE ALLWAYS START WITH TdataType, this makes it easier to Replace the T's ;)
    TEMPLATE ARGS:
        Tclass      : Replace with the name of your enum class
        TdataType   : Replace with the data type of your enum Class, fx. int
        NOTE!!: const keyword is not really required it just a safety measure to tell the operator overload that the arg is read only
        SORUCE      : If more non binary oriented overloads is needed the prototype design can be found here https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
    */
    // CLASSLESS ENUM OPERATOR OVERLOAD TEMPLATE, hence the enum is a free enum not a member of a class (ENUM OUTSIDE CLASS)-------------------
    /*
            // ASSIGNMENT OPERATOR OVERLOADS (NOT ALLOWED FOR Classless enums) (MUST BE MEMBER OF CLASS::FUNCTION :( )

            // COMPARISON OPERATOR OVERLOADS
            const bool operator== (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ == (TdataType)b_); } // EQUAL TO, a_ == b_
            const bool operator== (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ == b_); } // EQUAL TO, a_ == b_
            const bool operator!= (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ != (TdataType)b_); } // NOT EQUAL TO, a_ != b_
            const bool operator!= (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ != b_); } // NOT EQUAL TO, a_ != b_

            // LOGICAL OPERATOR OVERLOADS
            bool operator! (const Tclass a_) { return (bool)(!(TdataType)a_); } // LOGICAL NEGATION (NOT/FLIP VALUE), !a_ ==> if a_ <= 0 => !a_ = true, else false
            bool operator&& (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ && (TdataType)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
            bool operator&& (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ && (TdataType)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
            bool operator|| (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ || (TdataType)b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false
            bool operator|| (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ || b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false

            // BITWISE OPERATOR OVERLOADS
            Tclass operator~ (const Tclass a_) { return (Tclass)(~(TdataType)a_); }// BITWISE NOT (NEGATE/INVERT/FLIP BITS), ~a_ ==> if Bit(n) = 1 the ~bit(n) = 0 and if Bit(n) = 0 then ~Bit(n) = 1
            Tclass operator| (const Tclass a_, const Tclass b_) { return (Tclass)((TdataType)a_ | (TdataType)b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
            Tclass operator| (const Tclass a_, const TdataType b_) { return (Tclass)((TdataType)a_ | b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
            Tclass operator& (const Tclass a_, const Tclass b_) { return (Tclass)((TdataType)a_ & (TdataType)b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
            Tclass operator& (const Tclass a_, const TdataType b_) { return (Tclass)((TdataType)a_ & b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
            Tclass operator^ (const Tclass a_, const Tclass b_) { return (Tclass)((TdataType)a_ ^ (TdataType)b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0
            Tclass operator^ (const Tclass a_, const TdataType b_) { return (Tclass)((TdataType)a_ ^ b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0

            // BITWISE ASSIGNEMNT OPERATORS
            Tclass& operator|= (const Tclass& a_, const Tclass b_) { return (Tclass&)((TdataType&)a_ |= (TdataType)b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
            Tclass& operator|= (const Tclass& a_, const TdataType b_) { return (Tclass&)((TdataType&)a_ |= b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
            Tclass& operator&= (const Tclass& a_, const Tclass b_) { return (Tclass&)((TdataType&)a_ &= (TdataType)b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
            Tclass& operator&= (const Tclass& a_, const TdataType b_) { return (Tclass&)((TdataType&)a_ &= b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
            Tclass& operator^= (const Tclass& a_, const Tclass b_) { return (Tclass&)((TdataType&)a_ ^= (TdataType)b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)
            Tclass& operator^= (const Tclass& a_, const TdataType b_) { return (Tclass&)((TdataType&)a_ ^= b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)

    */

    /*
    ENUM OVERLOAD SOLUTIONS: Copy - paste the operator overload functions template beneath to a location beneath the your enum class and replace the T with enum name and TdataType with enum data type!!
    NOTE!!When enum is a member of another class, friend in front on the operator overload function is required or c++ will assume the overload is for the parrentClass of enum!!
    NOTE!!Make sure TdataType is a data type that is big enough (bit size wise) for all the bit flags needed by your enum, fx. int typ. has 32 bits so thats 32 bit flags.
    HINT!! WHEN UING FIND-REPLACE ALLWAYS START WITH TdataType, this makes it easier to Replace the T's ;)
    TEMPLATE ARGS :
        Tclass    : Replace with the name of your enum class
        TdataType : Replace with the data type of your enum Class, fx. int
        NOTE!! const keyword is not really required it just a safety measure to tell the operator overload that the arg is read only
        SORUCE : If more non binary oriented overloads is needed the prototype design can be found here https ://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

    */
    // CLASS ENUM OPERATOR OVERLOAD TEMPLATE, hence the enum is a member of a class (is inside another class) (ENUM INSIDE CLASS)
    /*
            // ASSIGNMENT OPERATOR OVERLOADS (NOT ALLOWED FOR friend Class enums) (MUST BE MEMBER OF CLASS::FUNCTION :( )

            // COMPARISON OPERATOR OVERLOADS
            friend const bool operator== (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ == (TdataType)b_); } // EQUAL TO, a_ == b_
            friend const bool operator== (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ == b_); } // EQUAL TO, a_ == b_
            friend const bool operator!= (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ != (TdataType)b_); } // NOT EQUAL TO, a_ != b_
            friend const bool operator!= (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ != b_); } // NOT EQUAL TO, a_ != b_

            // LOGICAL OPERATOR OVERLOADS
            friend bool operator! (const Tclass a_) { return (bool)(!(TdataType)a_); } // LOGICAL NEGATION (NOT/FLIP VALUE), !a_ ==> if a_ <= 0 => !a_ = true, else false
            friend bool operator&& (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ && (TdataType)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
            friend bool operator&& (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ && (TdataType)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
            friend bool operator|| (const Tclass a_, const Tclass b_) { return (bool)((TdataType)a_ || (TdataType)b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false
            friend bool operator|| (const Tclass a_, const TdataType b_) { return (bool)((TdataType)a_ || b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false

            // BITWISE OPERATOR OVERLOADS
            friend Tclass operator~ (const Tclass a_) { return (Tclass)(~(TdataType)a_); }// BITWISE NOT (NEGATE/INVERT/FLIP BITS), ~a_ ==> if Bit(n) = 1 the ~bit(n) = 0 and if Bit(n) = 0 then ~Bit(n) = 1
            friend Tclass operator| (const Tclass a_, const Tclass b_) { return (Tclass)((TdataType)a_ | (TdataType)b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
            friend Tclass operator| (const Tclass a_, const TdataType b_) { return (Tclass)((TdataType)a_ | b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
            friend Tclass operator& (const Tclass a_, const Tclass b_) { return (Tclass)((TdataType)a_ & (TdataType)b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
            friend Tclass operator& (const Tclass a_, const TdataType b_) { return (Tclass)((TdataType)a_ & b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
            friend Tclass operator^ (const Tclass a_, const Tclass b_) { return (Tclass)((TdataType)a_ ^ (TdataType)b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0
            friend Tclass operator^ (const Tclass a_, const TdataType b_) { return (Tclass)((TdataType)a_ ^ b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0

            // BITWISE ASSIGNEMNT OPERATORS
            friend Tclass& operator|= (const Tclass& a_, const Tclass b_) { return (Tclass&)((TdataType&)a_ |= (TdataType)b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
            friend Tclass& operator|= (const Tclass& a_, const TdataType b_) { return (Tclass&)((TdataType&)a_ |= b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
            friend Tclass& operator&= (const Tclass& a_, const Tclass b_) { return (Tclass&)((TdataType&)a_ &= (TdataType)b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
            friend Tclass& operator&= (const Tclass& a_, const TdataType b_) { return (Tclass&)((TdataType&)a_ &= b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
            friend Tclass& operator^= (const Tclass& a_, const Tclass b_) { return (Tclass&)((TdataType&)a_ ^= (TdataType)b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)
            friend Tclass& operator^= (const Tclass& a_, const TdataType b_) { return (Tclass&)((TdataType&)a_ ^= b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)

    */

    /*
        Template class Used to handle bitwise operations on data Types used for bit flags fx. create a bitFlag handler for int flags.
        NOTE! This class can also handle enums as TdataType
        TEMPLATE INPUT:
            TdataType = the data type of enum class "NOTE! enum must enherit this data type that suits the amount of flags fx. 8 flags shlould be uint8_t, 16 flags, uint16_t etc...
            TcastSize = A dataType that is large enough to handle the bit operations on TdataTypes, fx. int Flags => TcastSize >= TdataType (int) fx int64_t
        cppBitFlag<int, int> myBitFlags;

        // As function arg
        void myFunc(cppBitFlag<int, int> myFlag_, ....)

    */
    template <class TdataType, class TcastSize>
    class cppBitFlag
    {

    private:
        TdataType   thisFlag_; // keep trak of thisFlags value

    public:
        /*
            Def. Constructor, ensures that the class can be initialized
        */
        cppBitFlag()
        {
            // Init thisFlag
            thisFlag_ = 0;
            return;
        }

        cppBitFlag(const cppBitFlag<TdataType, TcastSize>& flag_)
        {
            //Update thisFlag
            this->thisFlag_ = flag_.thisFlag_;
            return;
        }

        cppBitFlag(const TdataType flag_)
        {
            // Update thisFlag
            thisFlag_ = flag_;
            return;
        }

        // Get function
        /*
            Function used to get the value of thisFlag
            INPUT:

            OUTPUT:

            RETURN:
                TdataType: The new value of thisFlag
        */
        TdataType get()
        {
            // Return thisFlag
            return thisFlag_;
        }


        // ASSIGNMENT OPERATOR OVERLOADS
        cppBitFlag& operator= (const cppBitFlag<TdataType, TcastSize> flag_)
        {
            // Is this self assignemnt or object?
            if (thisFlag_ == flag_.thisFlag_)
            {
                //Y->Just forced exit nothing to assign
                // Return ref to thisObject
                return *this;
            }

            //Assume N-> Update thisFlag and return result
            thisFlag_ = flag_.thisFlag_;
            // Return ref to thisObject
            return *this;
        }

        cppBitFlag& operator= (const TdataType flag_)
        {
            // Is this self assignemnt?
            if (this->thisFlag_ == flag_)
            {
                //Y->Just forced exit nothing to assign
                // Return ref to thisObject
                return *this;
            }

            // Update thisFlag
            thisFlag_ = flag_;
            // Return ref to thisObject
            return *this;
        }

        // COMPARISON OPERATOR
        const bool operator== (const TdataType flag_) { return (bool)(thisFlag_ == flag_); } // EQUAL TO, thisFlag == flag
        const bool operator!= (const TdataType flag_) { return (bool)(thisFlag_ != flag_); } // NOT EQUAL TO, thisFlag != flag

        // LOGICAL OPERATOR OVERLOADS
        bool operator! () { return (bool)(!thisFlag_); } // LOGICAL NEGATION (NOT)
        bool operator&& (const TdataType flag_) { return (bool)(thisFlag_ && flag_); } // LOGICAL AND
        bool operator|| (const TdataType flag_) { return (bool)(thisFlag_ || flag_); } // LOGICAL OR   

        // BITWISE OPERATORS OVERLOADS
        TdataType operator~() { return (TdataType)(~thisFlag_); } // BITWISE NOT/NEGATE (INVERT/FLIP BITS)
        TdataType operator| (const TdataType flag_) { return (thisFlag_ | flag_); } // BITWISE OR
        TdataType operator& (const TdataType flag_) { return (thisFlag_ & flag_); } // BITWISE AND
        TdataType operator^ (const TdataType flag_) { return (thisFlag_ ^ flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1

        //BITWISE ASSIGNEMNT OPERATOR OVERLOADS
        TdataType& operator|= (const TdataType flag_) { return (TdataType&)(thisFlag_ |= flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
        TdataType& operator&= (const TdataType flag_) { return (TdataType&)(thisFlag_ &= flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        TdataType& operator^= (const TdataType flag_) { return (TdataType&)(thisFlag_ ^= flag_); } // BITWISE XOR ASSIGNEMT, thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

        // BIT MANIPULATION
        /*
            Function used to set bits (specified by flag_) in thisFlag
            INPUT:
                flag_: flag containing bit mask specifing bits to set
            OUTPUT:

            RETURN:
                T: the new value of thisFlag
        */
        TdataType   setBits(const TdataType flag_)
        {
            return (thisFlag_ |= flag_);
        }
        /*
            Function used to set a specific bit (specified by bitIx) in thisFlag
            INPUT:
                bitIx_: bit ix of bit to set

            OUTPUT:

            RETURN:
                T: the new value of thisFlag
        */
        TdataType   setBit(const TdataType bitIx_ = 0)
        {
            return (thisFlag_ |= ((TdataType)((TcastSize)1 << (TcastSize)bitIx_)));
        }

        /*
            Function used to clear bits (specified by flag_) in thisFlag
            INPUT:
                flag_: flag containing bit mask specifing bits to clear

            OUTPUT:

            RETURN:
                T: new value of thisFlag
        */
        TdataType   clearBits(const TdataType flag_)
        {
            return (thisFlag_ &= ~flag_);
        }

        /*
            Function used to clear a specific bit (specified by bitIx) in thisFlag
            INPUT :
                bitIx_: bit ix of bit to clear

            OUTPUT :

            RETURN :
                T: new value of thisFlag
        */
        TdataType   clearBit(const TdataType bitIx_ = 0)
        {
            return (thisFlag_ &= (~(TdataType)((TcastSize)1 << (TcastSize)bitIx_)));
        }

        /*
            Function used to toggle bits (specified by flag) in thisFlag
            INPUT :
                flag_: flag containing bit mask specifying bits to toggle

            OUTPUT :

            RETURN :
                T: new value of thisFlag
        */
        TdataType   toggleBits(const TdataType flag_)
        {
            return (thisFlag_ ^= flag_);
        }

        /*
            Function used to toggle a specific bit (specified by bitIx) in thisFlag
            INPUT :
                bitIx_: bit ix of bit to toggle
            OUTPUT :

            RETURN :
                T: new value of thisFlag

        */
        TdataType   toggleBit(const TdataType bitIx_ = 0)
        {
            return (thisFlag_ ^= ((TdataType)((TcastSize)1 << (TcastSize)bitIx_)));
        }

        /*
            Function used to set bits (specified by flag) in thisFlag, to specified state
            INPUT :
                flag_       : bit mask specifying bits to set to specified state
                reservMask_ : bit mask specifying the reserved bit, hence DONT TOUCH bits "READ ONLY"
            OUTPUT :

            RETURN :
                T: new value of thisFlag
        */
        TdataType   configBits(const TdataType flag_, const TdataType reservMask_)
        {
            // Clear all non reserved bits
            thisFlag_ &= reservMask_;

            // Set the specifed bits and return result
            return (thisFlag_ |= flag_);
        }

        // BIT COMPARE TESTS
        /*
            Function used to check if one or more specific bit flag is set (BIT ON TEST)
            INPUT:
                flag_: flag containing bit mask specifying bits to check

            OUTPUT

            RETURN:
                bool: T = Bit is set(1), F = bit is cleared(0)
        */
        bool    isSet(const TdataType flag_)
        {
            // Return result of BITWISE AND
            return (bool)(thisFlag_ & flag_);
        }

        /*
            Function used to check if a specific bit is set (BIT n ON TEST)
            INPUT:
                bitIx_: bit ix for bit to check

            OUTPUT:

            RETURN:
                bool: T = Bit is set(1), F = bit is cleared(0)
        */
        bool    isSetAtIx(const TdataType bitIx_ = 0)
        {
            // Return result of BITWISE AND
            return (bool)(thisFlag_ & ((TdataType)((TcastSize)1 << (TcastSize)bitIx_)));
        }

        /*
            Function used to check if one or more specific bit flag is cleared (BIT OFF TEST)
            INPUT:
                flag_: flag containing bit mask specifying bits to check

            OUTPUT:

            RETURN:
                bool: T = Bit is cleared(0), F = bit is set(1)
        */
        bool    isClear(const TdataType flag_)
        {
            // Return result of BITWISE AND        
            return (bool)(thisFlag_ & ~flag_);
        }

        /*
            Function used to check if a specific bit is cleared (BIT n OFF TEST)
            INPUT:
                bitIx_: bit ix for bit to check

            OUTPUT:

            RETURN:
                T = Bit is cleared(0), F = bit is set(1)
        */
        bool    isClearAtIx(const TdataType bitIx_ = 0)
        {
            // Return result of BITWISE AND, 1 in the bit shift is casted as TdataType to avoid conversion failur when TdataType is a Enum or Class
            return (bool)(thisFlag_ & (~(TdataType)((TcastSize)1 << (TcastSize)bitIx_)));
        }

    };
}