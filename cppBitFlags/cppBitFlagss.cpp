#include "pch.h"
#include "cppBitFlags.h"

namespace rpmClasses
{



        /*
            Def. Constructor, ensures that the class can be initialized
        */
        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>::cppEnumBitFlag()
        {
            thisFlag_ = (Tclass)0;
            return;
        }
        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>::cppEnumBitFlag(const cppEnumBitFlag<Tclass, TdataType>& flag_)
        {
            // Update thisFlag and return
            thisFlag_ = flag_.thisFlag_;
            return;
        }

        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>::cppEnumBitFlag(const Tclass flag_)
        {
            // Update thisFlag and return
            thisFlag_ = flag_;
            return;
        }

        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>::cppEnumBitFlag(const TdataType flag_)
        {
            // Update thisFlag and return
            thisFlag_ = (Tclass)flag_;
            return;
        }

        /* Specialization to allow the template to be exported*/
        cppEnumBitFlag<myEnum, int>::cppEnumBitFlag()
        {
            thisFlag_ = (myEnum)0;
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
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::get()
        {
            // return thisFlag
            return thisFlag_;
        }

        // ASSIGNMENT OPERATOR OVERLOADS
        //**cppEnumBitFlag& operator= (const )
        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>& cppEnumBitFlag<Tclass, TdataType>::operator= (const cppEnumBitFlag<Tclass, TdataType> flag_);
        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>& cppEnumBitFlag<Tclass, TdataType>::operator= (const Tclass flag_);
        template<class Tclass, class TdataType>
        cppEnumBitFlag<Tclass, TdataType>& cppEnumBitFlag<Tclass, TdataType>::operator= (const TdataType flag_);

        // COMPARISON OPERATOR
        template<class Tclass, class TdataType>
        const bool cppEnumBitFlag<Tclass, TdataType>::operator== (const Tclass flag_) { return (bool)((TdataType)thisFlag_ == (TdataType)flag_); } // EQUAL TO, thisFlag == flag
        template<class Tclass, class TdataType>
        const bool cppEnumBitFlag<Tclass, TdataType>::operator== (const TdataType flag_) { return (bool)((TdataType)thisFlag_ == flag_); } // EQUAL TO, thisFlag == flag
        template<class Tclass, class TdataType>
        const bool cppEnumBitFlag<Tclass, TdataType>::operator!= (const Tclass flag_) { return (bool)((TdataType)thisFlag_ != (TdataType)flag_); } // NOT EQUAL TO, thisFlag != flag
        template<class Tclass, class TdataType>
        const bool cppEnumBitFlag<Tclass, TdataType>::operator!= (const TdataType flag_) { return (bool)((TdataType)thisFlag_ != flag_); } // NOT EQUAL TO, thisFlag != flag

        // LOGICAL OPERATOR OVERLOADS
        template<class Tclass, class TdataType>
        bool cppEnumBitFlag<Tclass, TdataType>::operator! () { return (bool)(!(TdataType)thisFlag_); } // LOGICAL NEGATION (NOT)
        template<class Tclass, class TdataType>
        bool cppEnumBitFlag<Tclass, TdataType>::operator&& (const Tclass flag_) { return (bool)((TdataType)thisFlag_ && (TdataType)flag_); } // LOGICAL AND
        template<class Tclass, class TdataType>
        bool cppEnumBitFlag<Tclass, TdataType>::operator&& (const TdataType flag_) { return (bool)((TdataType)thisFlag_ && flag_); } // LOGICAL AND
        template<class Tclass, class TdataType>
        bool cppEnumBitFlag<Tclass, TdataType>::operator|| (const Tclass flag_) { return (bool)((TdataType)thisFlag_ || (TdataType)flag_); } // LOGICAL OR
        template<class Tclass, class TdataType>
        bool cppEnumBitFlag<Tclass, TdataType>::operator|| (const TdataType flag_) { return (bool)((TdataType)thisFlag_ || flag_); } // LOGICAL OR

        // BITWISE OPERATORS OVERLOADS
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator~() { return (Tclass)(~(TdataType)thisFlag_); } // BITWISE NOT/NEGATE (INVERT/FLIP BITS)
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator| (const Tclass flag_) { return (Tclass)((TdataType)thisFlag_ | (TdataType)flag_); } // BITWISE OR
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator| (const TdataType flag_) { return (Tclass)((TdataType)thisFlag_ | flag_); } // BITWISE OR
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator& (const Tclass flag_) { return (Tclass)((TdataType)thisFlag_ & (TdataType)flag_); } // BITWISE AND
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator& (const TdataType flag_) { return (Tclass)((TdataType)thisFlag_ & flag_); } // BITWISE AND
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator^ (const Tclass flag_) { return (Tclass)((TdataType)thisFlag_ ^ (TdataType)flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1
        template<class Tclass, class TdataType>
        Tclass cppEnumBitFlag<Tclass, TdataType>::operator^ (const TdataType flag_) { return (Tclass)((TdataType)thisFlag_ ^ flag_); } // BITWISE XOR (BITWISE UNEQUAL DETECTOR), 1&1=0, 1&0=1, 0&1=1, 0&0=1

        //BITWISE ASSIGNEMNT OPERATOR OVERLOADS
        template<class Tclass, class TdataType>
        Tclass& cppEnumBitFlag<Tclass, TdataType>::operator|= (const Tclass flag_) { return (Tclass&)((TdataType&)thisFlag_ |= (TdataType)flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
        template<class Tclass, class TdataType>
        Tclass& cppEnumBitFlag<Tclass, TdataType>::operator|= (const TdataType flag_) { return (Tclass&)((TdataType&)thisFlag_ |= flag_); } // BITWISE OR ASSIGNEMT, thisFlag |= flag = thisFlag = (thisFlag | flag)
        template<class Tclass, class TdataType>
        Tclass& cppEnumBitFlag<Tclass, TdataType>::operator&= (const Tclass flag_) { return (Tclass&)((TdataType&)thisFlag_ &= (TdataType)flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        template<class Tclass, class TdataType>
        Tclass& cppEnumBitFlag<Tclass, TdataType>::operator&= (const TdataType flag_) { return (Tclass&)((TdataType&)thisFlag_ &= flag_); } // BITWISE AND ASSIGNEMT, thisFlag &= flag = thisFlag = (thisFlag & flag)
        template<class Tclass, class TdataType>
        Tclass& cppEnumBitFlag<Tclass, TdataType>::operator^= (const Tclass flag_) { return (Tclass&)((TdataType&)thisFlag_ ^= (TdataType)flag_); } // BITWISE XOR ASSIGNEMT (BITWISE TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)
        template<class Tclass, class TdataType>
        Tclass& cppEnumBitFlag<Tclass, TdataType>::operator^= (const TdataType flag_) { return (Tclass&)((TdataType&)thisFlag_ ^= flag_); } // BITWISE XOR ASSIGNEMT (BITWISE TOGGLE BIT), thisFlag ^= flag = thisFlag = (thisFlag ^ flag)

        // BIT MANIPULATION
        /*
            Function used to set bits (specified by flag_) in thisFlag
            INPUT:
                flag_: flag containing bit mask specifing bits to set
            OUTPUT:

            RETURN:
                Tclass: the new value of thisFlag
        */
        template<class Tclass, class TdataType>
        Tclass&   cppEnumBitFlag<Tclass, TdataType>::setBits(const Tclass flag_)
        {
            return (Tclass&)(thisFlag_ |= flag_);
        }
        template<class Tclass, class TdataType>
        Tclass&   cppEnumBitFlag<Tclass, TdataType>::setBits(const TdataType flag_)
        {
            return (Tclass&)(thisFlag_ |= flag_);
        }

        
        myEnum& cppEnumBitFlag<myEnum, int>::setBits(const int flag_)
        {
            return (myEnum&)((int)thisFlag_ |= flag_);
        }
        
        /*
            Function used to set a specific bit (specified by bitIx) in thisFlag
            INPUT:
                bitIx_: bit ix of bit to set

            OUTPUT:

            RETURN:
                Tclass: the new value of thisFlag
        */
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::setBit(const TdataType bitIx_)
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
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::clearBits(const Tclass flag_)
        {
            return (thisFlag_ &= ~flag_);
        }
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::clearBits(const TdataType flag_)
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
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::clearBit(const TdataType bitIx_)
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
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::toggleBits(const Tclass flag_)
        {
            return (thisFlag_ ^= flag_);
        }
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::toggleBits(const TdataType flag_)
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
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::toggleBit(const TdataType bitIx_)
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
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::configBits(const Tclass flag_, const Tclass reservMask_)
        {
            // Clear all non reserved bits
            thisFlag_ &= reservMask_;

            // Set the specifed bits and return result
            return (thisFlag_ |= flag_);
        }
        template<class Tclass, class TdataType>
        Tclass   cppEnumBitFlag<Tclass, TdataType>::configBits(const TdataType flag_, const TdataType reservMask_)
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
        template<class Tclass, class TdataType>
        bool    cppEnumBitFlag<Tclass, TdataType>::isSet(const Tclass flag_)
        {
            // Return result of BITWISE AND
            return (bool)(thisFlag_ & flag_);
        }
        template<class Tclass, class TdataType>
        bool    cppEnumBitFlag<Tclass, TdataType>::isSetHex(const TdataType flag_)
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
        template<class Tclass, class TdataType>
        bool    cppEnumBitFlag<Tclass, TdataType>::isSet(const TdataType bitIx_)
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
        template<class Tclass, class TdataType>
        bool    cppEnumBitFlag<Tclass, TdataType>::isClear(const Tclass flag_)
        {
            // Return result of BITWISE AND        
            return (bool)(thisFlag_ & ~flag_);
        }
        template<class Tclass, class TdataType>
        bool    cppEnumBitFlag<Tclass, TdataType>::isClearHex(const TdataType flag_)
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
        template<class Tclass, class TdataType>
        bool    cppEnumBitFlag<Tclass, TdataType>::isClear(const TdataType bitIx_)
        {
            // Return result of BITWISE AND, 
            /*
                thisFlag is casted as TdataTYpe because operator overload dont work inside class
                where the Operator is overloaded ??
            */
            return (bool)((TdataType)thisFlag_ & (~(TdataType)(1 << bitIx_)));
        }

        // Define allowable template types
        //CPPBITFLAGS_TEMPLATE    template class CPPBITFLAGS_API cppEnumBitFlag<myEnum, int>;
        template cppEnumBitFlag<myEnum, int>;
       // CPPBITFLAGS_TEMPLATE    template class CPPBITFLAGS_API cppEnumBitFlag<class Tclass, class TdataType>;


        //CPPBITFLAGS_TEMPLATE    template class CPPBITFLAGS_API cppBitFlag<int, int>;
        //**template cppBitFlag<int, int>;

}
