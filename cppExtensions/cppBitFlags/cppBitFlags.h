#pragma once

/*
    Template class Used to handle bitwise operations on enum classes containing bit flags fx. create a class of int flags
    TEMPLATE INPUT:
        T = The enum class
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
    
    cppEnumBitFlag(const cppEnumBitFlag<T, TdataType>& flag_)
    {
        // Update thisFlag and return
        thisFlag_ = flag_.thisFlag_;
        return;
    }

    cppEnumBitFlag(const T flag_)
    {
        // Update thisFlag and return
        thisFlag_ = flag_;
        return;
    }

    cppEnumBitFlag(const TdataType flag_)
    {
        // Update thisFlag and return
        thisFlag_ = (T)flag_;
        return;
    }

    // Get function
    /*
        Function used to get thisFlag
        INPUT:

        OUTPUT:

        RETURN:
            T: The value of thisFlag
    */
    T get()
    {
        // return thisFlag
        return thisFlag_;
    }


    // ASSIGNMENT OPERATOR OVERLOADS
    //**cppEnumBitFlag& operator= (const )
    cppEnumBitFlag& operator= (const cppEnumBitFlag<T, TdataType> flag_)
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
    
    cppEnumBitFlag& operator= (const T flag_) 
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
        if (this->thisFlag_ == (T)flag_)
        {
            //Y->Just forced exit nothing to assign
            // Return ref to thisObject
            return *this;
        }

        // Update thisFlag
        thisFlag_ = (T)flag_;
        // Return ref to thisObject
        return *this;
    }

    // COMPARISON OPERATOR
    const bool operator== (const T flag_) { return (bool)((TdataType)thisFlag_ == (TdataType)flag_); } // EQUAL TO, thisFlag == flag
    const bool operator== (const TdataType flag_) { return (bool)((TdataType)thisFlag_ == flag_); } // EQUAL TO, thisFlag == flag
    const bool operator!= (const T flag_) { return (bool)((TdataType)thisFlag_ != (TdataType)flag_); } // NOT EQUAL TO, thisFlag != flag
    const bool operator!= (const TdataType flag_) { return (bool)((TdataType)thisFlag_ != flag_); } // NOT EQUAL TO, thisFlag != flag

    // LOGICAL OPERATOR OVERLOADS
    bool operator! () { return (bool)(!(TdataType)thisFlag_); } // LOGICAL NEGATION (NOT)
    bool operator&& (const T flag_) { return (bool)((TdataType)thisFlag_ && (TdataType)flag_); } // LOGICAL AND
    bool operator&& (const TdataType flag_) { return (bool)((TdataType)thisFlag_ && flag_); } // LOGICAL AND
    bool operator|| (const T flag_) { return (bool)((TdataType)thisFlag_ || (TdataType)flag_); } // LOGICAL OR
    bool operator|| (const TdataType flag_) { return (bool)((TdataType)thisFlag_ || flag_); } // LOGICAL OR
                        
    // BITWISE OPERATORS OVERLOADS
    T operator~() { return (T)(~(TdataType)thisFlag_); } // BITWISE NOT/NEGATE (INVERT/FLIP BITS)
    T operator| (const T flag_) { return (T)((TdataType)thisFlag_ | (TdataType)flag_); } // BITWISE OR
    T operator| (const TdataType flag_) { return (T)((TdataType)thisFlag_ | flag_); } // BITWISE OR
    T operator& (const T flag_) { return (T)((TdataType)thisFlag_ & (TdataType)flag_); } // BITWISE AND
    T operator& (const TdataType flag_) { return (T)((TdataType)thisFlag_ & flag_); } // BITWISE AND
    T operator^ (const T flag_) { return (T)((TdataType)thisFlag_ ^ (TdataType)flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1
    T operator^ (const TdataType flag_) { return (T)((TdataType)thisFlag_ ^ flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1

    //BITWISE ASSIGNEMNT OPERATOR OVERLOADS
    T& operator|= (const T flag_) { return (T&)((TdataType&)thisFlag_ |= (TdataType)flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
    T& operator|= (const TdataType flag_) { return (T&)((TdataType&)thisFlag_ |= flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
    T& operator&= (const T flag_) { return (T&)((TdataType&)thisFlag_ &= (TdataType)flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
    T& operator&= (const TdataType flag_) { return (T&)((TdataType&)thisFlag_ &= flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
    T& operator^= (const T flag_) { return (T&)((TdataType&)thisFlag_ ^= (TdataType)flag_); } // BITWISE XOR ASSIGNEMT (BITWISE TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)
    T& operator^= (const TdataType flag_) { return (T&)((TdataType&)thisFlag_ ^= flag_); } // BITWISE XOR ASSIGNEMT (BITWISE TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

    // BIT MANIPULATION
    /*
        Function used to set bits (specified by flag_) in thisFlag
        INPUT:
            flag_: flag containing bit mask specifing bits to set
        OUTPUT:

        RETURN:
            T: the new value of thisFlag
    */
    T   setBits(const T flag_)
    {                
        return (thisFlag_ |= flag_);
    }
    T   setBits(const TdataType flag_)
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
    T   setBit(const TdataType bitIx_ = 0)
    {
        return (thisFlag_ |= ((T)(1 << bitIx_)));
    }

    /*
        Function used to clear bits (specified by flag_) in thisFlag
        INPUT:
            flag_: flag containing bit mask specifing bits to clear

        OUTPUT:

        RETURN:
            T: new value of thisFlag
    */
    T   clearBits(const T flag_)
    {
        return (thisFlag_ &= ~flag_);
    }
    T   clearBits(const TdataType flag_)
    {
        return (thisFlag_ &= ~(T)flag_);
    }

    /*
        Function used to clear a specific bit (specified by bitIx) in thisFlag
        INPUT :
            bitIx_: bit ix of bit to clear

        OUTPUT :

        RETURN :
            T: new value of thisFlag
    */
    T   clearBit(const TdataType bitIx_ = 0)
    {
        return (thisFlag_ &= (~(T)(1 << bitIx_)));
    }

    /*
        Function used to toggle bits (specified by flag) in thisFlag
        INPUT :
            flag_: flag containing bit mask specifying bits to toggle

        OUTPUT :

        RETURN :
            T: new value of thisFlag 
    */
    T   toggleBits(const T flag_)
    {
        return (thisFlag_ ^= flag_);
    }
    T   toggleBits(const TdataType flag_)
    {
        return (thisFlag_ ^= (T)flag_);
    }

    /*
        Function used to toggle a specific bit (specified by bitIx) in thisFlag
        INPUT :
            bitIx_: bit ix of bit to toggle
        OUTPUT :

        RETURN :
            T: new value of thisFlag
            
    */
    T   toggleBit(const TdataType bitIx_ = 0)
    {
        return (thisFlag_ ^= ((T)(1 << bitIx_)));
    }

    /*
        Function used to set bits (specified by flag) in thisFlag, to specified state
        INPUT :
            flag_       : flag containing bit mask specifying bits to set to specified state
            reservMask_ : bit mask specifying the reserved bit, hence DONT TOUCH bits "READ ONLY"

        OUTPUT :

        RETURN :
            T: new value of thisFlag
    */
    T   configBits(const T flag_, const T reservMask_)
    {
        // Clear all non reserved bits
        thisFlag_ &= reservMask_;

        // Set the specifed bits and return result
        return (thisFlag_ |= flag_);
    }
    T   configBits(const TdataType flag_, const TdataType reservMask_)
    {
        // Clear all non reserved bits
        thisFlag_ &= (T)reservMask_;

        // Set the specifed bits and return result
        return (thisFlag_ |= (T)flag_);
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
    bool    isSet(const T flag_)
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
    bool    isClear(const T flag_)
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
Solution: Copy - paste the operator overload functions template beneath to a location beneath the your enum class and replace the T with enum name and TdataType with enum data type!!
NOTE!!If enum is a member of another class add friend in front on the operator overload function or c++ will assue the overload is for the parrentClass of enum!!
NOTE!!If more flags then bits in int is required replace the int cast with a data type that can hold all your bit flags
*/
// CLASSLESS ENUM OPERATOR OVERLOAD TEMPLATE, hence the enum is a free enum not a member of a class (OUTSIDE CLASS)-------------------
/*
        // LOGICAL OPERATOR OVERLOADS
        bool operator! (const T a) { return (bool)(!(TdataType)a); } // LOGICAL NEGATION (NOT)
        bool operator&& (const T a, const T b) { return (bool)((TdataType)a && (TdataType)b); } // LOGICAL AND
        bool operator|| (const T a, const T b) { return (bool)((TdataType)a || (TdataType)b); } //LOGICAL OR

        // BITWISE OPERATOR OVERLOADS
        T operator~ (const T a) { return (T)(~(TdataType)a); }// BITWISE NOT (NEGATE/INVER/FLIP BITS)
        T operator| (const T a, const T b) { return (T)((TdataType)a | (TdataType)b); } // BITWISE OR
        T operator& (const T a, const T b) { return (T)((TdataType)a & (TdataType)b); } // BITWISE AND
        T operator^ (const T a, const T b) { return (T)((TdataType)a ^ (TdataType)b); } // BITWISE XOR (UNEQUAL DETECTOR)

        // BITWISE ASSIGNEMNT OPERATORS
        T& operator|= (const T& a, const T b) { return (T&)((TdataType&)a |= (TdataType)b); } // BITWISE OR ASSIGNMENT, thisFlag |= flag = thisFlag = (thisFlag | flag_)
        T& operator&= (const T& a, const T b) { return (T&)((TdataType&)a &= (TdataType)b); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        T& operator^= (const T& a, const T b) { return (T&)((TdataType&)a ^= (TdataType)b); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

*/

// CLASS ENUM OPERATOR OVERLOAD TEMPLATE, hence the enum is a member of a class (is inside another class) (INSIDE CLASS)
/*
        // LOGICAL OPERATOR OVERLOADS
        friend bool operator! (const T a) { return (bool)(!(TdataType)a); } // LOGICAL NEGATION (NOT)
        friend bool operator&& (const T a, const T b) { return (bool)((TdataType)a && (TdataType)b); } // LOGICAL AND
        friend bool operator|| (const T a, const T b) { return (bool)((TdataType)a || (TdataType)b); } //LOGICAL OR

        // BITWISE OPERATOR OVERLOADS
        friend T operator~ (const T a) { return (T)(~(TdataType)a); }// BITWISE NOT (NEGATE/INVER/FLIP BITS)
        friend T operator| (const T a, const T b) { return (T)((TdataType)a | (TdataType)b); } // BITWISE OR
        friend T operator& (const T a, const T b) { return (T)((TdataType)a & (TdataType)b); } // BITWISE AND
        friend T operator^ (const T a, const T b) { return (T)((TdataType)a ^ (TdataType)b); } // BITWISE XOR (UNEQUAL DETECTOR)

        // BITWISE ASSIGNEMNT OPERATORS
        friend T& operator|= (const T& a, const T b) { return (T&)((TdataType&)a |= (TdataType)b); } // BITWISE OR ASSIGNMENT, thisFlag |= flag = thisFlag = (thisFlag | flag_)
        friend T& operator&= (const T& a, const T b) { return (T&)((TdataType&)a &= (TdataType)b); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        friend T& operator^= (const T& a, const T b) { return (T&)((TdataType&)a ^= (TdataType)b); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

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
