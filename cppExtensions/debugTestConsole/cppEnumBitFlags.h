#pragma once

/*
    Template class Used to handle bitwise operations on enum classes containing bit flags fx. create a class of int flags
    TEMPLATE INPUT:
        T = The enum class
        TdataType = the data type of enum class "NOTE! enum must enherit this data type that suits the amount of flags fx. 8 flags shlould be uint8_t, 16 flags, uint16_t etc...

    enum class myClass : int
    {
        IS_FLAG_A = 1<<0,
        IS_FLAG_B = 1<<1,
        .....        
    }

    cppEnumBitFlag<myClass, int> myBitFlag;

    // As function arg
    void myFunc(cppEnumBitFlag<myEnum, int> myFlag_, ....)

    but ofc it can also be used just to handle bits of and data type. like so
    cppEnumBitFlag<int, int>

*/
template <class T, class TdataType>
class cppEnumBitFlag
{

private:
    T   thisFlag_; // keep trak of thisFlags value

public:
    /*
        Def. Constructor, ensures that the class can be initialized
    */
    cppEnumBitFlag()
    {
        thisFlag_ = 0;
        return;
    }

    cppEnumBitFlag(T flag_)
    {
        thisFlag_ = flag_;
        return;
    }

    /* 

    */
/*
    T operator~ (T a_) 
    { 
        return (T)~(int)a_; 
    }
    */

    /*
    inline T operator~ () { return (T)~(int)this; } // bitwise NEGATE/INVERT (~this)
    inline T operator| (T flag_) { return (T)((int)this | (int)flag_); } // bitwise OR (thisFlag | flag)
    inline T operator& (T flag_) { return (T)((int)this & (int)flag_); } // bitwise AND (thisFlag & flag)
    inline T operator^ (T flag_) { return (T)((int)this ^ (int)flag_); } // bitwise XOR (thisFlag ^ flag)
    inline T operator|= (T& flag_) { return (T&)((int&)this |= (int)flag_); } // XOR (thisFlag |= flag = thisFlag = (thisFlag | flag))
    inline T operator&= (T& flag_) { return (T&)((int&)this &= (int)flag_); } // AND (thisFlag &= flag = thisFlag = (thisFlag & flag))
    inline T operator^= (T& flag_) { return (T&)((int&)this ^= (int)flag_); } // NEGATE/INVERT (thisFlag ^= flag = thisFlag = (thisFlag ^ flag))
    */

    // ASSIGNMENT OPERATOR OVERLOADS
    T operator=(T flag_) { return (T)((TdataType)thisFlag_ = (TdataType)flag_); }

    // LOGICAL OPERATOR OVERLOADS
    bool operator! () { return (bool)!((TdataType)thisFlag_); } // LOGICAL NEGATION (NOT)
    bool operator&& (T flag_) { return (bool)((TdataType)thisFlag_ && (TdataType)flag_); } // LOGICAL AND
    bool operator|| (T flag_) { return (bool)((TdataType)thisFlag_ || (TdataType)flag_); } // LOGICAL OR   
            
            
    // BITWISE OPERATORS OVERLOADS
    T operator~() { return (T)(~(TdataType)thisFlag_); } // BITWISE NOT/NEGATE (INVERT/FLIP BITS)
    T operator| (T flag_) { return (T)((TdataType)thisFlag_ | (TdataType)flag_); } // BITWISE OR
    T operator& (T flag_) { return (T)((TdataType)thisFlag_ & (TdataType)flag_); } // BITWISE AND
    T operator^ (T flag_) { return (T)((TdataType)thisFlag_ ^ (TdataType)flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1

    //BITWISE ASSIGNEMNT OPERATOR OVERLOADS
    T& operator|= (T flag_) { return (T&)((TdataType&)thisFlag_ |= (TdataType)flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
    T& operator&= (T flag_) { return (T&)((TdataType&)thisFlag_ &= (TdataType)flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
    T& operator^= (T flag_) { return (T&)((TdataType&)thisFlag_ ^= (TdataType)flag_); } // BITWISE XOR ASSIGNEMT, thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

    // BIT MANIPULATION
    T   setBits(T flag_)
    {
        return (thisFlag_ |= flag_);
    }
    T   setBit(TdataType bitIx_)
    {
        return (thisFlag_ |= (TdataType)(1 << bitIx_));
    }

    T   clearBits(T flag_)
    {
        return (thisFlag_ &= ~flag_);
    }
    T   clearBit(TdataType bitIx_)
    {
        return (thisFlag_ &= ~(TdataType)(1 << bitIx_));
    }

    T   toggleBits(T flag_)
    {
        return (thisFlag_ ^= flag_);
    }

    T   toggleBit(TdataType bitIx_)
    {
        return (thisFlag_ ^= (TdataType)(1 << bitIx_));
    }

    T   configBits(T flag_, T reservMask_)
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

        OUTPUT

        RETURN:
            bool: T = Bit is set(1), F = bit is not set(0) 
    */
    bool    isSet(T flag_)
    {
        // Return result of BITWISE AND
        return (bool)(thisFlag_ & flag_);
    }
    /*
        Function used to check if a specific bit is set (BIT n ON TEST)
        INPUT:
            bitIx_: bit ix for bit to test
    */
    bool    isSet(TdataType bitIx_ = 0)
    {
        // Return result of BITWISE AND
        return (bool)(thisFlag_ & (TdataType)(1 << bitIx_));
    }


    /*
        Function used to check if one or more specific bit flag is cleared (BIT OFF TEST)
        INPUT:

        OUTPUT

        RETURN:
            bool: T = Bit is set(1), F = bit is not set(0)
    */
    bool    isClear(T flag_)
    {
        // Return result of BITWISE AND        
        return (bool)(thisFlag_ & ~flag_);
    }
    /*
        Function used to check if a specific bit is cleared (BIT n OFF TEST)
        INPUT:
            bitIx_: bit ix for bit to test
    */
    bool    isClear(TdataType bitIx_ = 0)
    {
        // Return result of BITWISE AND
        return (bool)(thisFlag_ & ~(TdataType)(1 << bitIx_));
    }
  
};

/*
Solution: Copy - paste the operator overload functions template beneath to a location beneath the your enum class and replace the T with enum name and TdataType with enum data type!!
NOTE!!If enum is a member of another class add friend in front on the operator overload function or c++ will assue the overload is for the parrentClass of enum!!
NOTE!!If more flags then bits in int is required replace the int cast with a data type that can hold all your bit flags
*/
// CLASSLESS ENUM OPERATOR OVERLOAD TEMPLATE, hence the enum is a free enum not a member of a class (OUTSIDE CLASS)-------------------
/*
        // LOGICAL OPERATOR OVERLOADS
        bool operator! (T a) { return (bool)(~(TdataType)a); } // LOGICAL NEGATION (NOT)
        bool operator&& (T a, T b) { return (bool)((TdataType)a && (TdataType)b); } // LOGICAL AND
        bool operator|| (T a, T b) { return (bool)((TdataType)a || (TdataType)b); } //LOGICAL OR

        // BITWISE OPERATOR OVERLOADS
        T operator~ (T a) { return (T)(~(TdataType)a); }// BITWISE NOT (NEGATE/INVER/FLIP BITS)
        T operator| (T a, T b) { return (T)((TdataType)a | (TdataType)b); } // BITWISE OR
        T operator& (T a, T b) { return (T)((TdataType)a & (TdataType)b); } // BITWISE AND
        T operator^ (T a, T b) { return (T)((TdataType)a ^ (TdataType)b); } // BITWISE XOR (UNEQUAL DETECTOR)

        // BITWISE ASSIGNEMNT OPERATORS
        T& operator|= (T& a, T b) { return (T&)((TdataType&)a |= (TdataType)b); } // BITWISE OR ASSIGNMENT, thisFlag |= flag = thisFlag = (thisFlag | flag_)
        T& operator&= (T& a, T b) { return (T&)((TdataType&)a &= (TdataType)b); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        T& operator^= (T& a, T b) { return (T&)((TdataType&)a ^= (TdataType)b); } // BITWISE XOR ASSIGNEMNT, thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

*/


// CLASS ENUM OPERATOR OVERLOAD TEMPLATE, hence the enum is a member of a class (is inside another class) (INSIDE CLASS)
/*
        // LOGICAL OPERATOR OVERLOADS
        friend bool operator! (T a) { return (bool)(~(TdataType)a); } // LOGICAL NEGATION (NOT)
        friend bool operator&& (T a, T b) { return (bool)((TdataType)a && (TdataType)b); } // LOGICAL AND
        friend bool operator|| (T a, T b) { return (bool)((TdataType)a || (TdataType)b); } //LOGICAL OR

        // BITWISE OPERATOR OVERLOADS
        friend T operator~ (T a) { return (T)(~(TdataType)a); }// BITWISE NOT (NEGATE/INVER/FLIP BITS)
        friend T operator| (T a, T b) { return (T)((TdataType)a | (TdataType)b); } // BITWISE OR
        friend T operator& (T a, T b) { return (T)((TdataType)a & (TdataType)b); } // BITWISE AND
        friend T operator^ (T a, T b) { return (T)((TdataType)a ^ (TdataType)b); } // BITWISE XOR (UNEQUAL DETECTOR)

        // BITWISE ASSIGNEMNT OPERATORS
        friend T& operator|= (T& a, T b) { return (T&)((TdataType&)a |= (TdataType)b); } // BITWISE OR ASSIGNMENT, thisFlag |= flag = thisFlag = (thisFlag | flag_)
        friend T& operator&= (T& a, T b) { return (T&)((TdataType&)a &= (TdataType)b); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        friend T& operator^= (T& a, T b) { return (T&)((TdataType&)a ^= (TdataType)b); } // BITWISE XOR ASSIGNEMNT, thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

*/

/*
    Template class Used to handle bitwise operations on data Types used for bit flags fx. create a bitFla handler for int flags
    TEMPLATE INPUT:
        TdataType = the data type of enum class "NOTE! enum must enherit this data type that suits the amount of flags fx. 8 flags shlould be uint8_t, 16 flags, uint16_t etc...

    cppBitFlag<int> myBitFlags;

    // As function arg
    void myFunc(cppBitFlag<int> myFlag_, ....)

*/
template <class TdataType>
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
        thisFlag_ = 0;
        return;
    }

    cppBitFlag(TdataType flag_)
    {
        thisFlag_ = flag_;
        return;
    }

    /*

    */
    /*
        T operator~ (T a_)
        {
            return (T)~(int)a_;
        }
        */

        /*
        inline T operator~ () { return (T)~(int)this; } // bitwise NEGATE/INVERT (~this)
        inline T operator| (T flag_) { return (T)((int)this | (int)flag_); } // bitwise OR (thisFlag | flag)
        inline T operator& (T flag_) { return (T)((int)this & (int)flag_); } // bitwise AND (thisFlag & flag)
        inline T operator^ (T flag_) { return (T)((int)this ^ (int)flag_); } // bitwise XOR (thisFlag ^ flag)
        inline T operator|= (T& flag_) { return (T&)((int&)this |= (int)flag_); } // XOR (thisFlag |= flag = thisFlag = (thisFlag | flag))
        inline T operator&= (T& flag_) { return (T&)((int&)this &= (int)flag_); } // AND (thisFlag &= flag = thisFlag = (thisFlag & flag))
        inline T operator^= (T& flag_) { return (T&)((int&)this ^= (int)flag_); } // NEGATE/INVERT (thisFlag ^= flag = thisFlag = (thisFlag ^ flag))
        */

        // ASSIGNMENT OPERATOR OVERLOADS
    TdataType operator=(TdataType flag_) { return (TdataType)(thisFlag_ = flag_); }

    // LOGICAL OPERATOR OVERLOADS
    bool operator! () { return (bool)!(thisFlag_); } // LOGICAL NEGATION (NOT)
    bool operator&& (TdataType flag_) { return (bool)(thisFlag_ && flag_); } // LOGICAL AND
    bool operator|| (TdataType flag_) { return (bool)(thisFlag_ || flag_); } // LOGICAL OR   


    // BITWISE OPERATORS OVERLOADS
    TdataType operator~() { return (TdataType)(~thisFlag_); } // BITWISE NOT/NEGATE (INVERT/FLIP BITS)
    TdataType operator| (TdataType flag_) { return (thisFlag_ | flag_); } // BITWISE OR
    TdataType operator& (TdataType flag_) { return (thisFlag_ & flag_); } // BITWISE AND
    TdataType operator^ (TdataType flag_) { return (thisFlag_ ^ flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1

    //BITWISE ASSIGNEMNT OPERATOR OVERLOADS
    TdataType& operator|= (TdataType flag_) { return (TdataType&)(thisFlag_ |= flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
    TdataType& operator&= (TdataType flag_) { return (TdataType&)(thisFlag_ &= flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
    TdataType& operator^= (TdataType flag_) { return (TdataType&)(thisFlag_ ^= flag_); } // BITWISE XOR ASSIGNEMT, thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

    // BIT MANIPULATION
    TdataType   setBits(TdataType flag_)
    {
        return (thisFlag_ |= flag_);
    }
    TdataType   setBitAtIx(TdataType bitIx_)
    {
        return (thisFlag_ |= (TdataType)(1 << bitIx_));
    }

    TdataType   clearBits(TdataType flag_)
    {
        return (thisFlag_ &= ~flag_);
    }
    TdataType   clearBitAtIx(TdataType bitIx_)
    {
        return (thisFlag_ &= ~(TdataType)(1 << bitIx_));
    }

    TdataType   toggleBits(TdataType flag_)
    {
        return (thisFlag_ ^= flag_);
    }

    TdataType   toggleBitAtIx(TdataType bitIx_)
    {
        return (thisFlag_ ^= (TdataType)(1 << bitIx_));
    }

    TdataType   configBits(TdataType flag_, TdataType reservMask_)
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

        OUTPUT

        RETURN:
            bool: T = Bit is set(1), F = bit is not set(0)
    */
    bool    isSet(TdataType flag_)
    {
        // Return result of BITWISE AND
        return (bool)(thisFlag_ & flag_);
    }
    /*
        Function used to check if a specific bit is set (BIT n ON TEST)
        INPUT:
            bitIx_: bit ix for bit to test
    */
    bool    isSetAtIx(TdataType bitIx_ = 0)
    {
        // Return result of BITWISE AND
        return (bool)(thisFlag_ & (TdataType)(1 << bitIx_));
    }


    /*
        Function used to check if one or more specific bit flag is cleared (BIT OFF TEST)
        INPUT:

        OUTPUT

        RETURN:
            bool: T = Bit is set(1), F = bit is not set(0)
    */
    bool    isClear(TdataType flag_)
    {
        // Return result of BITWISE AND        
        return (bool)(thisFlag_ & ~flag_);
    }
    /*
        Function used to check if a specific bit is cleared (BIT n OFF TEST)
        INPUT:
            bitIx_: bit ix for bit to test
    */
    bool    isClearAtIx(TdataType bitIx_ = 0)
    {
        // Return result of BITWISE AND
        return (bool)(thisFlag_ & ~(TdataType)(1 << bitIx_));
    }

};
