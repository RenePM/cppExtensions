// cppBitFlagsImplConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "cppBitFlagsImplConsole.h"
#include "cppBitFlags.h"


using namespace std; // use c++ standard name space
using namespace rpmExt; // My C++ Extensions

// Classless enum class bitflags test 8 bits => dataType = (uint8_t)
enum class enumClasslessFlags : int // Datatype much match overloeded casting type to avoid stack corruption 
{
    FLAG_A = (1 << 0), // BIT0
    FLAG_B = (1 << 1), // BIT1
    FLAG_C = (1 << 2), // BIT2
    FLAG_D = (1 << 3), // BIT3
    FLAG_E = (1 << 4), // BIT4
    FLAG_F = (1 << 5), // BIT5
    FLAG_G = (1 << 6), // BIT6
    FLAG_H = (1 << 7), // BIT7
    FLAG_TEST1 = 0x55, // Toggle pattern to test all bits
    FLAG_TEST2 = ~(0x55), // Inverted toggle pattern to test all bits
    NO_FLAGS = 0x00,
    ALL_FLAGS = 0xFF,
};

// CLASSLESS ENUM OPERATOR OVERLOADS

// ASSIGNMENT OPERATOR OVERLOADS (MUST BE MEMBER OF CLASS::FUNCTION)

// COMPARISON OPERATOR OVERLOADS
const bool operator== (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (bool)((int)a_ == (int)b_); } // EQUAL TO, a_ == b_    
const bool operator== (const enumClasslessFlags a_, const int b_) { return (bool)((int)a_ == b_); } // EQUAL TO, a_ == b_
const bool operator!= (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (bool)((int)a_ != (int)b_); } // NOT EQUAL TO, a_ != b_
const bool operator!= (const enumClasslessFlags a_, const int b_) { return (bool)((int)a_ != b_); } // NOT EQUAL TO, a_ != b_

// LOGICAL OPERATOR OVERLOADS
bool operator! (const enumClasslessFlags a_) { return (bool)(!(int)a_); } // LOGICAL NEGATION (NOT/FLIP VALUE), !a_ ==> if a_ <= 0 => !a_ = true, else false
bool operator&& (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (bool)((int)a_ && (int)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
bool operator&& (const enumClasslessFlags a_, const int b_) { return (bool)((int)a_ && (int)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
bool operator|| (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (bool)((int)a_ || (int)b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false
bool operator|| (const enumClasslessFlags a_, const int b_) { return (bool)((int)a_ || b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false

// BITWISE OPERATOR OVERLOADS
enumClasslessFlags operator~ (const enumClasslessFlags a_) { return (enumClasslessFlags)(~(int)a_); }// BITWISE NOT (NEGATE/INVERT/FLIP BITS), ~a_ ==> if Bit(n) = 1 the ~bit(n) = 0 and if Bit(n) = 0 then ~Bit(n) = 1
enumClasslessFlags operator| (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (enumClasslessFlags)((int)a_ | (int)b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1 
enumClasslessFlags operator| (const enumClasslessFlags a_, const int b_) { return (enumClasslessFlags)((int)a_ | b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
enumClasslessFlags operator& (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (enumClasslessFlags)((int)a_ & (int)b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
enumClasslessFlags operator& (const enumClasslessFlags a_, const int b_) { return (enumClasslessFlags)((int)a_ & b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
enumClasslessFlags operator^ (const enumClasslessFlags a_, const enumClasslessFlags b_) { return (enumClasslessFlags)((int)a_ ^ (int)b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0
enumClasslessFlags operator^ (const enumClasslessFlags a_, const int b_) { return (enumClasslessFlags)((int)a_ ^ b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0

// BITWISE ASSIGNEMNT OPERATORS
enumClasslessFlags& operator|= (const enumClasslessFlags& a_, const enumClasslessFlags b_) { return (enumClasslessFlags&)((int&)a_ |= (int)b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
enumClasslessFlags& operator|= (const enumClasslessFlags& a_, const int b_) { return (enumClasslessFlags&)((int&)a_ |= b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
enumClasslessFlags& operator&= (const enumClasslessFlags& a_, const enumClasslessFlags b_) { return (enumClasslessFlags&)((int&)a_ &= (int)b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
enumClasslessFlags& operator&= (const enumClasslessFlags& a_, const int b_) { return (enumClasslessFlags&)((int&)a_ &= b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
enumClasslessFlags& operator^= (const enumClasslessFlags& a_, const enumClasslessFlags b_) { return (enumClasslessFlags&)((int&)a_ ^= (int)b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)
enumClasslessFlags& operator^= (const enumClasslessFlags& a_, const int b_) { return (enumClasslessFlags&)((int&)a_ ^= b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)

int main()
{
    std::cout << "Hello World!\n";

    // Classless enum class overload test
    testClasslessEnumOverload(); //OK

    // Class enum class overload test
    testClassEnumOverload(); // OK

    // enumbitFlag Template Classless Enum
    testEnumBitFlagClassClasslessEnum(); //OK

    // enumbitFlag Template Class Enum
    testEnumBitFlagClassClassEnum(); //OK

    // bitFlag Template Classless Enum
    testBitFlagClassClasslessEnum();

    // BitFlag Template Class Enum
    testBitFlagClassClassEnum();

    // BitFlag Template primite DataTYpe (int)
    testBitFlagClassDataType();

}

// OPERATOR OVERLOAD TEST
/*
    Function used to test Classless Enum Class Operator Overloads
    STATUS: OK, TESTED
*/
void testClasslessEnumOverload()
{
    // Show Test Identifier
    cout << "\r\n" << "testClasslessEnumOverload():\r\n";
    enumClasslessFlags myClasslessFlags = (enumClasslessFlags::FLAG_A |
        enumClasslessFlags::FLAG_C |
        enumClasslessFlags::FLAG_E |
        enumClasslessFlags::FLAG_G); // 0x55 (OK)

    myClasslessFlags = enumClasslessFlags::FLAG_TEST2; // ~0x55 (OK)
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    bool boolResult = false;


    // COMPARIASON
    if (myClasslessFlags == enumClasslessFlags::FLAG_TEST1)
    {
        cout << (int)myClasslessFlags << " == " << (int)enumClasslessFlags::FLAG_TEST1 << ": myClasslessFlags matches the FLAG TEST 1 Pattern [OK]\r\n"; // OK
    }
    if (myClasslessFlags != enumClasslessFlags::FLAG_TEST2)
    {
        cout << (int)myClasslessFlags << " != " << (int)enumClasslessFlags::FLAG_TEST2 << ": myClasslessFlags does not match FLAG TEST 2 Pattern [OK]\r\n"; // OK
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myClasslessFlags;
    boolResult = !enumClasslessFlags::FLAG_TEST1;
    boolResult = !enumClasslessFlags::NO_FLAGS;

    // LOGICAL AND(&&)
    if (myClasslessFlags && enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)myClasslessFlags << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessFlags > 0 AND and ALL_FLAGS > 0 [OK]\r\n"; // (OK)
    }
    else
    {
        cout << (int)myClasslessFlags << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessFlags = 0 OR ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClasslessFlags && enumClasslessFlags::NO_FLAGS)
    {
        cout << (int)myClasslessFlags << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessFlags > 0 AND and NO_FLAGS > 0 [FAIL]\r\n";
    }
    else
    {
        cout << (int)myClasslessFlags << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessFlags = 0 OR NO_FLAGS = 0 [OK]\r\n"; // OK
    }

    // LOGICAL OR(||)
    if (myClasslessFlags || enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)myClasslessFlags << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessFlags > 0 OR ALL_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClasslessFlags << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessFlags = 0 AND ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (enumClasslessFlags::FLAG_A || enumClasslessFlags::NO_FLAGS)
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0 [FAIL]\r\n";
    }
    if (~enumClasslessFlags::NO_FLAGS || ~enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0 [OK]\r\n"; //OK
    }
    else
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0 [FAIL]\r\n";
    }

    // Bitwise NOT (~)
    if ((myClasslessFlags & enumClasslessFlags::FLAG_A) == ~enumClasslessFlags::FLAG_A)
    {
        cout << "(" << (int)myClasslessFlags << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in MyClassFlags except Flag A [FAIL]\r\n";
    }
    else
    {
        cout << "(" << (int)myClasslessFlags << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in MyClassFlags except Flag A is not true [OK]\r\n"; // OK
    }

    myClasslessFlags = ~enumClasslessFlags::FLAG_A; // OK
    myClasslessFlags = ~enumClasslessFlags::FLAG_B; // OK
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1; // OK

    //BITWISE AND (&)
    if ((myClasslessFlags & enumClasslessFlags::FLAG_A) == enumClasslessFlags::FLAG_A)
    {
        cout << "(" << (int)myClasslessFlags << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslesFlags [OK]\r\n"; // OK
    }
    else
    {
        cout << "(" << (int)myClasslessFlags << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not in myClasslesFlags [FAIL]\r\n";
    }
    if ((myClasslessFlags & enumClasslessFlags::FLAG_A) != enumClasslessFlags::FLAG_A)
    {
        cout << "(" << (int)myClasslessFlags << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not set in myClasslesFlags [FAIL] \r\n";
    }
    else
    {
        cout << "(" << (int)myClasslessFlags << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslesFlags [OK]\r\n"; // OK
    }

    //BITWISE OR (|)
    myClasslessFlags = enumClasslessFlags::FLAG_A | enumClasslessFlags::FLAG_C; // OK
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1; // OK

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myClasslessFlags ^ enumClasslessFlags::FLAG_TEST1) == enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClasslessFlags << " ^ " << (int)enumClasslessFlags::FLAG_TEST1 << ") == " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessFlags AND FLAG_TEST1 MATCH [OK]\r\n"; //OK
    }

    if ((myClasslessFlags ^ enumClasslessFlags::FLAG_TEST2) != enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClasslessFlags << " ^ " << (int)enumClasslessFlags::FLAG_TEST2 << ") != " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessFlags AND FLAG_TEST2 DOES NOT MATCH [OK]\r\n"; //OK
    }

    //BITWISE AND ASSIGN (&=)
    myClasslessFlags &= enumClasslessFlags::FLAG_B; // => 0x00 since B is not set (OK)
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1;
    myClasslessFlags &= enumClasslessFlags::FLAG_A; // => 0x01 since A is set (OK)
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1;

    //BITWISE OR ASSIGN (|=)
    myClasslessFlags |= enumClasslessFlags::FLAG_B; // => BIT B becomes set (0x57) (OK)
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myClasslessFlags ^= enumClasslessFlags::FLAG_TEST1; // =>0x00 Since flags and flag_test1 match  (OK)
    myClasslessFlags = enumClasslessFlags::FLAG_TEST1;  // 
    myClasslessFlags ^= enumClasslessFlags::FLAG_TEST2; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL (OK)

    return;
}

// CLASS FUNTION TESTS

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Member of Class enum class bitflags test 
class myClass
{

public:
    // Member of class enum class
    enum class enumClassFlags : int
    {
        FLAG_A = (1 << 0), // BIT0
        FLAG_B = (1 << 1), // BIT1
        FLAG_C = (1 << 2), // BIT2
        FLAG_D = (1 << 3), // BIT3
        FLAG_E = (1 << 4), // BIT4
        FLAG_F = (1 << 5), // BIT5
        FLAG_G = (1 << 6), // BIT6
        FLAG_H = (1 << 7), // BIT7
        FLAG_TEST1 = 0x55, // Toggle pattern to test all bits
        FLAG_TEST2 = ~(0x55), // Inverted toggle pattern to test all bits
        NO_FLAGS = 0x00,
        ALL_FLAGS = 0xFF,
    };

    // MEMBER OF CLASS ENUM CLASS OPERATOR OVERLOADS (MUST BE MEMBER OF FUNCTION)
    // ASSIGNMENT OPERATOR OVERLOADS (NOT ALLOWED FOR friend Class enums) (MUST BE MEMBER OF CLASS::FUNCTION :( )

    // COMPARISON OPERATOR OVERLOADS
    friend const bool operator== (const enumClassFlags a_, const enumClassFlags b_) { return (bool)((int)a_ == (int)b_); } // EQUAL TO, a_ == b_
    friend const bool operator== (const enumClassFlags a_, const int b_) { return (bool)((int)a_ == b_); } // EQUAL TO, a_ == b_
    friend const bool operator!= (const enumClassFlags a_, const enumClassFlags b_) { return (bool)((int)a_ != (int)b_); } // NOT EQUAL TO, a_ != b_
    friend const bool operator!= (const enumClassFlags a_, const int b_) { return (bool)((int)a_ != b_); } // NOT EQUAL TO, a_ != b_

    // LOGICAL OPERATOR OVERLOADS
    friend bool operator! (const enumClassFlags a_) { return (bool)(!(int)a_); } // LOGICAL NEGATION (NOT/FLIP VALUE), !a_ ==> if a_ <= 0 => !a_ = true, else false
    friend bool operator&& (const enumClassFlags a_, const enumClassFlags b_) { return (bool)((int)a_ && (int)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
    friend bool operator&& (const enumClassFlags a_, const int b_) { return (bool)((int)a_ && (int)b_); } // LOGICAL AND, a_ && b_ ==> if a_ > 0 AND b_ > 0 then true, else false
    friend bool operator|| (const enumClassFlags a_, const enumClassFlags b_) { return (bool)((int)a_ || (int)b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false
    friend bool operator|| (const enumClassFlags a_, const int b_) { return (bool)((int)a_ || b_); } //LOGICAL OR, a_ || b_ ==> if a_ > 0 AND/OR b_ > 0 then true, else false

    // BITWISE OPERATOR OVERLOADS
    friend enumClassFlags operator~ (const enumClassFlags a_) { return (enumClassFlags)(~(int)a_); }// BITWISE NOT (NEGATE/INVERT/FLIP BITS), ~a_ ==> if Bit(n) = 1 the ~bit(n) = 0 and if Bit(n) = 0 then ~Bit(n) = 1
    friend enumClassFlags operator| (const enumClassFlags a_, const enumClassFlags b_) { return (enumClassFlags)((int)a_ | (int)b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
    friend enumClassFlags operator| (const enumClassFlags a_, const int b_) { return (enumClassFlags)((int)a_ | b_); } // BITWISE OR, a_ | b_ ==>  0|0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1
    friend enumClassFlags operator& (const enumClassFlags a_, const enumClassFlags b_) { return (enumClassFlags)((int)a_ & (int)b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
    friend enumClassFlags operator& (const enumClassFlags a_, const int b_) { return (enumClassFlags)((int)a_ & b_); } // BITWISE AND, a_ & b_ ==> 0&0 = 0, 0&1 = 0, 1&0 = 0, 1&1 = 1
    friend enumClassFlags operator^ (const enumClassFlags a_, const enumClassFlags b_) { return (enumClassFlags)((int)a_ ^ (int)b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0
    friend enumClassFlags operator^ (const enumClassFlags a_, const int b_) { return (enumClassFlags)((int)a_ ^ b_); } // BITWISE XOR (UNEQUAL DETECTOR), a_ ^ b_ ==> 0^0=0, 0^1=1, 1^0=1, 1^1=0

    // BITWISE ASSIGNEMNT OPERATORS
    friend enumClassFlags& operator|= (const enumClassFlags& a_, const enumClassFlags b_) { return (enumClassFlags&)((int&)a_ |= (int)b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
    friend enumClassFlags& operator|= (const enumClassFlags& a_, const int b_) { return (enumClassFlags&)((int&)a_ |= b_); } // BITWISE OR ASSIGNMENT, a_ |= b_ ==> a_ = (a_ | b_)
    friend enumClassFlags& operator&= (const enumClassFlags& a_, const enumClassFlags b_) { return (enumClassFlags&)((int&)a_ &= (int)b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
    friend enumClassFlags& operator&= (const enumClassFlags& a_, const int b_) { return (enumClassFlags&)((int&)a_ &= b_); } // BITWISE AND ASSIGNEMT, a_ &= b_ ==> a_ = (a_ & b_)
    friend enumClassFlags& operator^= (const enumClassFlags& a_, const enumClassFlags b_) { return (enumClassFlags&)((int&)a_ ^= (int)b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)
    friend enumClassFlags& operator^= (const enumClassFlags& a_, const int b_) { return (enumClassFlags&)((int&)a_ ^= b_); } // BITWISE XOR ASSIGNEMNT (TOGGLE BIT), a_ ^= b_ ==> a_ = (a_ ^ b_)

};

/*
    Function used to test Class Enum Class Operator Overloads
    STATUS: OK, TESTED
*/
void testClassEnumOverload()
{
    myClass::enumClassFlags myClassFlags = (myClass::enumClassFlags::FLAG_A |
        myClass::enumClassFlags::FLAG_C |
        myClass::enumClassFlags::FLAG_E |
        myClass::enumClassFlags::FLAG_G); // 0x55

    myClassFlags = myClass::enumClassFlags::FLAG_TEST2; // ~0x55
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1; // 0x55
    bool boolResult = false;

    cout << "\r\n" << "testClassEnumOverload():\r\n";

    // COMPARIASON
    if (myClassFlags == myClass::enumClassFlags::FLAG_TEST1)
    {
        cout << "myClassFlags matches the FLAG TEST 1 Pattern\r\n";
    }
    if (myClassFlags != myClass::enumClassFlags::FLAG_TEST2)
    {
        cout << "myClassFlags does not match FLAG TEST 2 Pattern\r\n";
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myClassFlags;
    boolResult = !myClass::enumClassFlags::FLAG_TEST1;
    boolResult = !myClass::enumClassFlags::NO_FLAGS;

    // LOGICAL AND(&&)
    if (myClassFlags && myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)myClassFlags << " && " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassFlags > 0 AND and ALL_FLAGS > 0\r\n";
    }
    else
    {
        cout << (int)myClassFlags << " && " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassFlags = 0 OR ALL_FLAGS = 0\r\n";
    }
    if (myClassFlags && myClass::enumClassFlags::NO_FLAGS)
    {
        cout << (int)myClassFlags << " && " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassFlags > 0 AND and NO_FLAGS > 0\r\n";
    }
    else
    {
        cout << (int)myClassFlags << " && " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassFlags = 0 OR NO_FLAGS = 0\r\n";
    }

    // LOGICAL OR(||)
    if (myClassFlags || myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)myClassFlags << " || " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassFlags > 0 OR ALL_FLAGS > 0\r\n";
    }
    else
    {
        cout << (int)myClassFlags << " || " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassFlags = 0 AND ALL_FLAGS = 0\r\n";
    }
    if (myClass::enumClassFlags::FLAG_A || myClass::enumClassFlags::NO_FLAGS)
    {
        cout << (int)myClass::enumClassFlags::FLAG_A << " || " << (int)myClass::enumClassFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0\r\n";
    }
    else
    {
        cout << (int)myClass::enumClassFlags::FLAG_A << " || " << (int)myClass::enumClassFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0\r\n";
    }
    if (~myClass::enumClassFlags::NO_FLAGS || ~myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)~myClass::enumClassFlags::NO_FLAGS << " || " << (int)~myClass::enumClassFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0\r\n";
    }
    else
    {
        cout << (int)~myClass::enumClassFlags::NO_FLAGS << " || " << (int)~myClass::enumClassFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0\r\n";
    }

    // Bitwise NOT (~)
    if ((myClassFlags & myClass::enumClassFlags::FLAG_A) == ~myClass::enumClassFlags::FLAG_A)
    {
        cout << "(" << (int)myClassFlags << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)~myClass::enumClassFlags::FLAG_A << ": All bits set in MyClassFlags except Flag A\r\n";
    }
    else
    {
        cout << "(" << (int)myClassFlags << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)~myClass::enumClassFlags::FLAG_A << ": All bits set in MyClassFlags except Flag A is not true\r\n";
    }

    myClassFlags = ~myClass::enumClassFlags::FLAG_A;
    myClassFlags = ~myClass::enumClassFlags::FLAG_B;
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE AND (&)
    if ((myClassFlags & myClass::enumClassFlags::FLAG_A) == myClass::enumClassFlags::FLAG_A)
    {
        cout << "(" << (int)myClassFlags << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClasslesFlags\r\n";
    }
    else
    {
        cout << "(" << (int)myClassFlags << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is not in myClasslesFlags\r\n";
    }
    if ((myClassFlags & myClass::enumClassFlags::FLAG_A) != myClass::enumClassFlags::FLAG_A)
    {
        cout << "(" << (int)myClassFlags << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is not set in myClasslesFlags\r\n";
    }
    else
    {
        cout << "(" << (int)myClassFlags << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClasslesFlags\r\n";
    }

    //BITWISE OR (|)
    myClassFlags = myClass::enumClassFlags::FLAG_A | myClass::enumClassFlags::FLAG_C;
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myClassFlags ^ myClass::enumClassFlags::FLAG_TEST1) == myClass::enumClassFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClassFlags << " ^ " << (int)myClass::enumClassFlags::FLAG_TEST1 << ") == " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassFlags AND FLAG_TEST1 MATCH\r\n";
    }

    if ((myClassFlags ^ myClass::enumClassFlags::FLAG_TEST2) != myClass::enumClassFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClassFlags << " ^ " << (int)myClass::enumClassFlags::FLAG_TEST2 << ") != " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassFlags AND FLAG_TEST2 DOES NOT MATCH\r\n";
    }

    //BITWISE AND ASSIGN (&=)
    myClassFlags &= myClass::enumClassFlags::FLAG_B; // => 0x00 since B is not set
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1;
    myClassFlags &= myClass::enumClassFlags::FLAG_A; // => 0x01 since A is set
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE OR ASSIGN (|=)
    myClassFlags |= myClass::enumClassFlags::FLAG_B; // => BIT B becomes set (0x57)
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myClassFlags ^= myClass::enumClassFlags::FLAG_TEST1; // =>0x00 Since falgs and flag_test1 match 
    myClassFlags = myClass::enumClassFlags::FLAG_TEST1;  // 
    myClassFlags ^= myClass::enumClassFlags::FLAG_TEST2; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL

    return;

}

/*
    Function used to test enumBitFlag Templated Classless Enum Class
    STATUS: OK, TESTED
*/
void testEnumBitFlagClassClasslessEnum()
{
    cppEnumBitFlag<enumClasslessFlags, int> myClasslessBitFlag(enumClasslessFlags::FLAG_A |
        enumClasslessFlags::FLAG_C |
        enumClasslessFlags::FLAG_E |
        enumClasslessFlags::FLAG_G); // 0x55

    cppEnumBitFlag<enumClasslessFlags, int> myDummyBitFlag(enumClasslessFlags::FLAG_TEST2);

    cout << "\r\n" << "testEnumBitFlagClassClasslessEnum():\r\n";

    // Test Assignemnt
    myClasslessBitFlag = myDummyBitFlag;
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;

    myClasslessBitFlag.setBits(enumClasslessFlags::FLAG_B); // 0x57
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    myClasslessBitFlag.setBit(1); // 0x57
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    myClasslessBitFlag.configBits(0x19, 0xA6); // 0x1D
    myClasslessBitFlag.configBits(0x55, 0xA2); // 0x55
    myClasslessBitFlag.clearBits(0x05); // 0x50
    myClasslessBitFlag.clearBit(4); // clear bit 4 => 0x40
    myClasslessBitFlag.toggleBits(0x01); // 0x41
    myClasslessBitFlag.toggleBit(); // Toggle bit 0 => 0x40

    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST2; // ~0x55 (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    bool boolResult = false;


    // COMPARIASON
    if (myClasslessBitFlag == enumClasslessFlags::FLAG_TEST1)
    {
        cout << (int)myClasslessBitFlag.get() << " == " << (int)enumClasslessFlags::FLAG_TEST1 << ": myClasslessBitFlag matches the FLAG TEST 1 Pattern [OK]\r\n"; // OK
    }
    if (myClasslessBitFlag != enumClasslessFlags::FLAG_TEST2)
    {
        cout << (int)myClasslessBitFlag.get() << " != " << (int)enumClasslessFlags::FLAG_TEST2 << ": myClasslessBitFlag does not match FLAG TEST 2 Pattern [OK]\r\n"; // OK
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myClasslessBitFlag;
    boolResult = !enumClasslessFlags::FLAG_TEST1;
    boolResult = !enumClasslessFlags::NO_FLAGS;

    // LOGICAL AND(&&)
    if (myClasslessBitFlag && enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag > 0 AND and ALL_FLAGS > 0 [OK]\r\n"; // (OK)
    }
    else
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag = 0 OR ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClasslessBitFlag && enumClasslessFlags::NO_FLAGS)
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag > 0 AND and NO_FLAGS > 0 [FAIL]\r\n";
    }
    else
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag = 0 OR NO_FLAGS = 0 [OK]\r\n"; // OK
    }

    // LOGICAL OR(||)
    if (myClasslessBitFlag || enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)myClasslessBitFlag.get() << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag > 0 OR ALL_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClasslessBitFlag.get() << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag = 0 AND ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (enumClasslessFlags::FLAG_A || enumClasslessFlags::NO_FLAGS)
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0 [FAIL]\r\n";
    }
    if (~enumClasslessFlags::NO_FLAGS || ~enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0 [OK]\r\n"; //OK
    }
    else
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0 [FAIL]\r\n";
    }

    // Bitwise NOT (~)
    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_A) == ~enumClasslessFlags::FLAG_A)
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in myClasslessBitFlag except Flag A [FAIL]\r\n";
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in myClasslessBitFlag except Flag A is not true [OK]\r\n"; // OK
    }

    myClasslessBitFlag = ~enumClasslessFlags::FLAG_A; // OK
    myClasslessBitFlag = ~enumClasslessFlags::FLAG_B; // OK
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // OK

    //BITWISE AND (&) "BIT CHECK"
    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_A) == enumClasslessFlags::FLAG_A)
    {
        if (myClasslessBitFlag.isSet(enumClasslessFlags::FLAG_A))
        {
            if (myClasslessBitFlag.isSet(0))
            {
                if (myClasslessBitFlag.isSetHex(0x01))
                {
                    cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslessBitFlag [OK]\r\n"; // OK
                }
            }
        }
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not in myClasslessBitFlag [FAIL]\r\n";
    }
    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_A) != enumClasslessFlags::FLAG_A)
    {
        if (myClasslessBitFlag.isClear(enumClasslessFlags::FLAG_A))
        {
            if (myClasslessBitFlag.isClear(0))
            {
                if (myClasslessBitFlag.isClearHex(0x01))
                {
                    cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not set in myClasslessBitFlag [FAIL] \r\n";
                }
            }
        }
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslessBitFlag [OK]\r\n"; // OK
    }

    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_B) != enumClasslessFlags::FLAG_B)
    {
        if (myClasslessBitFlag.isClear(enumClasslessFlags::FLAG_B))
        {
            if (myClasslessBitFlag.isClear(1))
            {
                if (myClasslessBitFlag.isClearHex(0x02))
                {
                    cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_B << ") != " << (int)enumClasslessFlags::FLAG_B << ": Flag B is not set in myClasslessBitFlag [OK] \r\n";
                }
            }
        }
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslessBitFlag [OK]\r\n"; // OK
    }

    //BITWISE OR (|)
    myClasslessBitFlag = enumClasslessFlags::FLAG_A | enumClasslessFlags::FLAG_C; // OK
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // OK

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myClasslessBitFlag ^ enumClasslessFlags::FLAG_TEST1) == enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " ^ " << (int)enumClasslessFlags::FLAG_TEST1 << ") == " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag AND FLAG_TEST1 MATCH [OK]\r\n"; //OK
    }

    if ((myClasslessBitFlag ^ enumClasslessFlags::FLAG_TEST2) != enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " ^ " << (int)enumClasslessFlags::FLAG_TEST2 << ") != " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag AND FLAG_TEST2 DOES NOT MATCH [OK]\r\n"; //OK
    }

    //BITWISE AND ASSIGN (&=)
    myClasslessBitFlag &= enumClasslessFlags::FLAG_B; // => 0x00 since B is not set (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;
    myClasslessBitFlag &= enumClasslessFlags::FLAG_A; // => 0x01 since A is set (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;

    //BITWISE OR ASSIGN (|=)
    myClasslessBitFlag |= enumClasslessFlags::FLAG_B; // => BIT B becomes set (0x57) (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myClasslessBitFlag ^= enumClasslessFlags::FLAG_TEST1; // =>0x00 Since flags and flag_test1 match  (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;  // 
    myClasslessBitFlag ^= enumClasslessFlags::FLAG_TEST2; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL (OK)

    return;
}

/*
    Function used to test cppEnumBitFlag Templated Class Enum class
    STATUS: OK, TESTED
*/
void testEnumBitFlagClassClassEnum()
{
    cppEnumBitFlag<myClass::enumClassFlags, int> myClassBitFlag(myClass::enumClassFlags::FLAG_A |
        myClass::enumClassFlags::FLAG_C |
        myClass::enumClassFlags::FLAG_E |
        myClass::enumClassFlags::FLAG_G); // 0x55

    cppEnumBitFlag<myClass::enumClassFlags, int> myDummyBitFlag(myClass::enumClassFlags::FLAG_TEST2);

    cout << "\r\n" << "testEnumBitFlagClassClassEnum():\r\n";

    // Test Assignemnt
    myClassBitFlag = myDummyBitFlag;
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;

    myClassBitFlag.setBits(myClass::enumClassFlags::FLAG_B); // 0x57
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // 0x55 (OK)
    myClassBitFlag.setBit(1); // 0x57
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // 0x55 (OK)
    myClassBitFlag.configBits(0x19, 0xA6); // 0x1D
    myClassBitFlag.configBits(0x55, 0xA2); // 0x55
    myClassBitFlag.clearBits(0x05); // 0x50
    myClassBitFlag.clearBit(4); // clear bit 4 => 0x40
    myClassBitFlag.toggleBits(0x01); // 0x41
    myClassBitFlag.toggleBit(); // Toggle bit 0 => 0x40

    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST2; // ~0x55 (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // 0x55 (OK)
    bool boolResult = false;


    // COMPARIASON
    if (myClassBitFlag == myClass::enumClassFlags::FLAG_TEST1)
    {
        cout << (int)myClassBitFlag.get() << " == " << (int)myClass::enumClassFlags::FLAG_TEST1 << ": myClassBitFlag matches the FLAG TEST 1 Pattern [OK]\r\n"; // OK
    }
    if (myClassBitFlag != myClass::enumClassFlags::FLAG_TEST2)
    {
        cout << (int)myClassBitFlag.get() << " != " << (int)myClass::enumClassFlags::FLAG_TEST2 << ": myClassBitFlag does not match FLAG TEST 2 Pattern [OK]\r\n"; // OK
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myClassBitFlag;
    boolResult = !myClass::enumClassFlags::FLAG_TEST1;
    boolResult = !myClass::enumClassFlags::NO_FLAGS;

    // LOGICAL AND(&&)
    if (myClassBitFlag && myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag > 0 AND and ALL_FLAGS > 0 [OK]\r\n"; // (OK)
    }
    else
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag = 0 OR ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClassBitFlag && myClass::enumClassFlags::NO_FLAGS)
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag > 0 AND and NO_FLAGS > 0 [FAIL]\r\n";
    }
    else
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag = 0 OR NO_FLAGS = 0 [OK]\r\n"; // OK
    }

    // LOGICAL OR(||)
    if (myClassBitFlag || myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)myClassBitFlag.get() << " || " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag > 0 OR ALL_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClassBitFlag.get() << " || " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag = 0 AND ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClass::enumClassFlags::FLAG_A || myClass::enumClassFlags::NO_FLAGS)
    {
        cout << (int)myClass::enumClassFlags::FLAG_A << " || " << (int)myClass::enumClassFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClass::enumClassFlags::FLAG_A << " || " << (int)myClass::enumClassFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0 [FAIL]\r\n";
    }
    if (~myClass::enumClassFlags::NO_FLAGS || ~myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)~myClass::enumClassFlags::NO_FLAGS << " || " << (int)~myClass::enumClassFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0 [OK]\r\n"; //OK
    }
    else
    {
        cout << (int)~myClass::enumClassFlags::NO_FLAGS << " || " << (int)~myClass::enumClassFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0 [FAIL]\r\n";
    }

    // Bitwise NOT (~)
    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_A) == ~myClass::enumClassFlags::FLAG_A)
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)~myClass::enumClassFlags::FLAG_A << ": All bits set in myClassBitFlag except Flag A [FAIL]\r\n";
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)~myClass::enumClassFlags::FLAG_A << ": All bits set in myClassBitFlag except Flag A is not true [OK]\r\n"; // OK
    }

    myClassBitFlag = ~myClass::enumClassFlags::FLAG_A; // OK
    myClassBitFlag = ~myClass::enumClassFlags::FLAG_B; // OK
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // OK

    //BITWISE AND (&) "BIT CHECK"
    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_A) == myClass::enumClassFlags::FLAG_A)
    {
        if (myClassBitFlag.isSet(myClass::enumClassFlags::FLAG_A))
        {
            if (myClassBitFlag.isSet(0))
            {
                if (myClassBitFlag.isSetHex(0x01))
                {
                    cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClassBitFlag [OK]\r\n"; // OK
                }
            }
        }
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is not in myClassBitFlag [FAIL]\r\n";
    }
    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_A) != myClass::enumClassFlags::FLAG_A)
    {
        if (myClassBitFlag.isClear(myClass::enumClassFlags::FLAG_A))
        {
            if (myClassBitFlag.isClear(0))
            {
                if (myClassBitFlag.isClearHex(0x01))
                {
                    cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is not set in myClassBitFlag [FAIL] \r\n";
                }
            }
        }
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClassBitFlag [OK]\r\n"; // OK
    }

    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_B) != myClass::enumClassFlags::FLAG_B)
    {
        if (myClassBitFlag.isClear(myClass::enumClassFlags::FLAG_B))
        {
            if (myClassBitFlag.isClear(1))
            {
                if (myClassBitFlag.isClearHex(0x02))
                {
                    cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_B << ") != " << (int)myClass::enumClassFlags::FLAG_B << ": Flag B is not set in myClassBitFlag [OK] \r\n";
                }
            }
        }
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClassBitFlag [OK]\r\n"; // OK
    }

    //BITWISE OR (|)
    myClassBitFlag = myClass::enumClassFlags::FLAG_A | myClass::enumClassFlags::FLAG_C; // OK
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // OK

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myClassBitFlag ^ myClass::enumClassFlags::FLAG_TEST1) == myClass::enumClassFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClassBitFlag.get() << " ^ " << (int)myClass::enumClassFlags::FLAG_TEST1 << ") == " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag AND FLAG_TEST1 MATCH [OK]\r\n"; //OK
    }

    if ((myClassBitFlag ^ myClass::enumClassFlags::FLAG_TEST2) != myClass::enumClassFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClassBitFlag.get() << " ^ " << (int)myClass::enumClassFlags::FLAG_TEST2 << ") != " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag AND FLAG_TEST2 DOES NOT MATCH [OK]\r\n"; //OK
    }

    //BITWISE AND ASSIGN (&=)
    myClassBitFlag &= myClass::enumClassFlags::FLAG_B; // => 0x00 since B is not set (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;
    myClassBitFlag &= myClass::enumClassFlags::FLAG_A; // => 0x01 since A is set (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE OR ASSIGN (|=)
    myClassBitFlag |= myClass::enumClassFlags::FLAG_B; // => BIT B becomes set (0x57) (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myClassBitFlag ^= myClass::enumClassFlags::FLAG_TEST1; // =>0x00 Since flags and flag_test1 match  (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;  // 
    myClassBitFlag ^= myClass::enumClassFlags::FLAG_TEST2; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL (OK)

    return;

}

/*
    Function used to test cppBitFlag Templated Classless Enum Class
    STATUS: OK, TESTED
*/
void testBitFlagClassClasslessEnum()
{
    cppBitFlag<enumClasslessFlags, int> myClasslessBitFlag(enumClasslessFlags::FLAG_A |
        enumClasslessFlags::FLAG_C |
        enumClasslessFlags::FLAG_E |
        enumClasslessFlags::FLAG_G); // 0x55

    cppBitFlag<enumClasslessFlags, int> myDummyBitFlag(enumClasslessFlags::FLAG_TEST2);

    cout << "\r\n" << "testBitFlagClassClasslessEnum():\r\n";

    // Test Assignemnt
    myClasslessBitFlag = myDummyBitFlag;
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;

    myClasslessBitFlag.setBits(enumClasslessFlags::FLAG_B); // 0x57
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    myClasslessBitFlag.setBit((enumClasslessFlags)1); // 0x57
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    myClasslessBitFlag.configBits((enumClasslessFlags)0x19, (enumClasslessFlags)0xA6); // 0x1D
    myClasslessBitFlag.configBits((enumClasslessFlags)0x55, (enumClasslessFlags)0xA2); // 0x55
    myClasslessBitFlag.clearBits((enumClasslessFlags)0x05); // 0x50
    myClasslessBitFlag.clearBit((enumClasslessFlags)4); // clear bit 4 => 0x40
    myClasslessBitFlag.toggleBits((enumClasslessFlags)0x01); // 0x41
    //**myClasslessBitFlag.toggleBit(); // Toggle bit 0 => 0x40

    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST2; // ~0x55 (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // 0x55 (OK)
    bool boolResult = false;


    // COMPARIASON
    if (myClasslessBitFlag == enumClasslessFlags::FLAG_TEST1)
    {
        cout << (int)myClasslessBitFlag.get() << " == " << (int)enumClasslessFlags::FLAG_TEST1 << ": myClasslessBitFlag matches the FLAG TEST 1 Pattern [OK]\r\n"; // OK
    }
    if (myClasslessBitFlag != enumClasslessFlags::FLAG_TEST2)
    {
        cout << (int)myClasslessBitFlag.get() << " != " << (int)enumClasslessFlags::FLAG_TEST2 << ": myClasslessBitFlag does not match FLAG TEST 2 Pattern [OK]\r\n"; // OK
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myClasslessBitFlag;
    boolResult = !enumClasslessFlags::FLAG_TEST1;
    boolResult = !enumClasslessFlags::NO_FLAGS;

    // LOGICAL AND(&&)
    if (myClasslessBitFlag && enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag > 0 AND and ALL_FLAGS > 0 [OK]\r\n"; // (OK)
    }
    else
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag = 0 OR ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClasslessBitFlag && enumClasslessFlags::NO_FLAGS)
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag > 0 AND and NO_FLAGS > 0 [FAIL]\r\n";
    }
    else
    {
        cout << (int)myClasslessBitFlag.get() << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag = 0 OR NO_FLAGS = 0 [OK]\r\n"; // OK
    }

    // LOGICAL OR(||)
    if (myClasslessBitFlag || enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)myClasslessBitFlag.get() << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag > 0 OR ALL_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClasslessBitFlag.get() << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myClasslessBitFlag = 0 AND ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (enumClasslessFlags::FLAG_A || enumClasslessFlags::NO_FLAGS)
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0 [FAIL]\r\n";
    }
    if (~enumClasslessFlags::NO_FLAGS || ~enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0 [OK]\r\n"; //OK
    }
    else
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0 [FAIL]\r\n";
    }

    // Bitwise NOT (~)
    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_A) == ~enumClasslessFlags::FLAG_A)
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in myClasslessBitFlag except Flag A [FAIL]\r\n";
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in myClasslessBitFlag except Flag A is not true [OK]\r\n"; // OK
    }

    myClasslessBitFlag = ~enumClasslessFlags::FLAG_A; // OK
    myClasslessBitFlag = ~enumClasslessFlags::FLAG_B; // OK
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // OK

    //BITWISE AND (&) "BIT CHECK"
    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_A) == enumClasslessFlags::FLAG_A)
    {
        if (myClasslessBitFlag.isSet(enumClasslessFlags::FLAG_A))
        {
            if (myClasslessBitFlag.isSetAtIx((enumClasslessFlags)0))
            {
                cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslessBitFlag [OK]\r\n"; // OK
            }
        }
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not in myClasslessBitFlag [FAIL]\r\n";
    }
    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_A) != enumClasslessFlags::FLAG_A)
    {
        if (myClasslessBitFlag.isClear(enumClasslessFlags::FLAG_A))
        {
            if (myClasslessBitFlag.isClear((enumClasslessFlags)0))
            {
                cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not set in myClasslessBitFlag [FAIL] \r\n";
            }
        }
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslessBitFlag [OK]\r\n"; // OK
    }

    if ((myClasslessBitFlag & enumClasslessFlags::FLAG_B) != enumClasslessFlags::FLAG_B)
    {
        if (myClasslessBitFlag.isClear(enumClasslessFlags::FLAG_B))
        {
            if (myClasslessBitFlag.isClearAtIx((enumClasslessFlags)1))
            {
                cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_B << ") != " << (int)enumClasslessFlags::FLAG_B << ": Flag B is not set in myClasslessBitFlag [OK] \r\n";
            }
        }
    }
    else
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myClasslessBitFlag [OK]\r\n"; // OK
    }

    //BITWISE OR (|)
    myClasslessBitFlag = enumClasslessFlags::FLAG_A | enumClasslessFlags::FLAG_C; // OK
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1; // OK

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myClasslessBitFlag ^ enumClasslessFlags::FLAG_TEST1) == enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " ^ " << (int)enumClasslessFlags::FLAG_TEST1 << ") == " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag AND FLAG_TEST1 MATCH [OK]\r\n"; //OK
    }

    if ((myClasslessBitFlag ^ enumClasslessFlags::FLAG_TEST2) != enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClasslessBitFlag.get() << " ^ " << (int)enumClasslessFlags::FLAG_TEST2 << ") != " << (int)enumClasslessFlags::NO_FLAGS << ": myClasslessBitFlag AND FLAG_TEST2 DOES NOT MATCH [OK]\r\n"; //OK
    }

    //BITWISE AND ASSIGN (&=)
    myClasslessBitFlag &= enumClasslessFlags::FLAG_B; // => 0x00 since B is not set (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;
    myClasslessBitFlag &= enumClasslessFlags::FLAG_A; // => 0x01 since A is set (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;

    //BITWISE OR ASSIGN (|=)
    myClasslessBitFlag |= enumClasslessFlags::FLAG_B; // => BIT B becomes set (0x57) (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myClasslessBitFlag ^= enumClasslessFlags::FLAG_TEST1; // =>0x00 Since flags and flag_test1 match  (OK)
    myClasslessBitFlag = enumClasslessFlags::FLAG_TEST1;  // 
    myClasslessBitFlag ^= enumClasslessFlags::FLAG_TEST2; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL (OK)

    return;
}

/*
    Function used to test cppBitFlag Templated Class Enum Class
    STATUS: OK, TESTED
*/
void testBitFlagClassClassEnum()
{
    cppBitFlag<myClass::enumClassFlags, int> myClassBitFlag(myClass::enumClassFlags::FLAG_A |
        myClass::enumClassFlags::FLAG_C |
        myClass::enumClassFlags::FLAG_E |
        myClass::enumClassFlags::FLAG_G); // 0x55

    cppBitFlag<myClass::enumClassFlags, int> myDummyBitFlag(myClass::enumClassFlags::FLAG_TEST2);

    cout << "\r\n" << "testBitFlagClassClassEnum():\r\n";

    // Test Assignemnt
    myClassBitFlag = myDummyBitFlag;
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;

    myClassBitFlag.setBits(myClass::enumClassFlags::FLAG_B); // 0x57
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // 0x55 (OK)
    myClassBitFlag.setBit((myClass::enumClassFlags)1); // 0x57
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // 0x55 (OK)
    myClassBitFlag.configBits((myClass::enumClassFlags)0x19, (myClass::enumClassFlags)0xA6); // 0x1D
    myClassBitFlag.configBits((myClass::enumClassFlags)0x55, (myClass::enumClassFlags)0xA2); // 0x55
    myClassBitFlag.clearBits((myClass::enumClassFlags)0x05); // 0x50
    myClassBitFlag.clearBit((myClass::enumClassFlags)4); // clear bit 4 => 0x40

    myClassBitFlag.toggleBits((myClass::enumClassFlags)0x01); // 0x41
    myClassBitFlag.toggleBit((myClass::enumClassFlags)0); // Toggle bit 0 => 0x40

    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST2; // ~0x55 (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // 0x55 (OK)
    bool boolResult = false;

    // COMPARIASON
    if (myClassBitFlag == myClass::enumClassFlags::FLAG_TEST1)
    {
        cout << (int)myClassBitFlag.get() << " == " << (int)myClass::enumClassFlags::FLAG_TEST1 << ": myClassBitFlag matches the FLAG TEST 1 Pattern [OK]\r\n"; // OK
    }
    if (myClassBitFlag != myClass::enumClassFlags::FLAG_TEST2)
    {
        cout << (int)myClassBitFlag.get() << " != " << (int)myClass::enumClassFlags::FLAG_TEST2 << ": myClassBitFlag does not match FLAG TEST 2 Pattern [OK]\r\n"; // OK
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myClassBitFlag;
    boolResult = !myClass::enumClassFlags::FLAG_TEST1;
    boolResult = !myClass::enumClassFlags::NO_FLAGS;

    // LOGICAL AND(&&)
    if (myClassBitFlag && myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag > 0 AND and ALL_FLAGS > 0 [OK]\r\n"; // (OK)
    }
    else
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag = 0 OR ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClassBitFlag && myClass::enumClassFlags::NO_FLAGS)
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag > 0 AND and NO_FLAGS > 0 [FAIL]\r\n";
    }
    else
    {
        cout << (int)myClassBitFlag.get() << " && " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag = 0 OR NO_FLAGS = 0 [OK]\r\n"; // OK
    }

    // LOGICAL OR(||)
    if (myClassBitFlag || myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)myClassBitFlag.get() << " || " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag > 0 OR ALL_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClassBitFlag.get() << " || " << (int)myClass::enumClassFlags::ALL_FLAGS << ": myClassBitFlag = 0 AND ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myClass::enumClassFlags::FLAG_A || myClass::enumClassFlags::NO_FLAGS)
    {
        cout << (int)myClass::enumClassFlags::FLAG_A << " || " << (int)myClass::enumClassFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)myClass::enumClassFlags::FLAG_A << " || " << (int)myClass::enumClassFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0 [FAIL]\r\n";
    }
    if (~myClass::enumClassFlags::NO_FLAGS || ~myClass::enumClassFlags::ALL_FLAGS)
    {
        cout << (int)~myClass::enumClassFlags::NO_FLAGS << " || " << (int)~myClass::enumClassFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0 [OK]\r\n"; //OK
    }
    else
    {
        cout << (int)~myClass::enumClassFlags::NO_FLAGS << " || " << (int)~myClass::enumClassFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0 [FAIL]\r\n";
    }

    // Bitwise NOT (~)
    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_A) == ~myClass::enumClassFlags::FLAG_A)
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)~myClass::enumClassFlags::FLAG_A << ": All bits set in myClassBitFlag except Flag A [FAIL]\r\n";
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)~myClass::enumClassFlags::FLAG_A << ": All bits set in myClassBitFlag except Flag A is not true [OK]\r\n"; // OK
    }

    myClassBitFlag = ~myClass::enumClassFlags::FLAG_A; // OK
    myClassBitFlag = ~myClass::enumClassFlags::FLAG_B; // OK
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // OK

    //BITWISE AND (&) "BIT CHECK"
    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_A) == myClass::enumClassFlags::FLAG_A)
    {
        if (myClassBitFlag.isSet(myClass::enumClassFlags::FLAG_A))
        {
            if (myClassBitFlag.isSetAtIx((myClass::enumClassFlags)0))
            {
                cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClassBitFlag [OK]\r\n"; // OK
            }
        }
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") == " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is not in myClassBitFlag [FAIL]\r\n";
    }
    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_A) != myClass::enumClassFlags::FLAG_A)
    {
        if (myClassBitFlag.isClear(myClass::enumClassFlags::FLAG_A))
        {
            if (myClassBitFlag.isClear((myClass::enumClassFlags)0))
            {
                cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is not set in myClassBitFlag [FAIL] \r\n";
            }
        }
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClassBitFlag [OK]\r\n"; // OK
    }

    if ((myClassBitFlag & myClass::enumClassFlags::FLAG_B) != myClass::enumClassFlags::FLAG_B)
    {
        if (myClassBitFlag.isClear(myClass::enumClassFlags::FLAG_B))
        {
            if (myClassBitFlag.isClearAtIx((myClass::enumClassFlags)1))
            {
                cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_B << ") != " << (int)myClass::enumClassFlags::FLAG_B << ": Flag B is not set in myClassBitFlag [OK] \r\n";
            }
        }
    }
    else
    {
        cout << "(" << (int)myClassBitFlag.get() << " & " << (int)myClass::enumClassFlags::FLAG_A << ") != " << (int)myClass::enumClassFlags::FLAG_A << ": Flag A is set in myClassBitFlag [OK]\r\n"; // OK
    }

    //BITWISE OR (|)
    myClassBitFlag = myClass::enumClassFlags::FLAG_A | myClass::enumClassFlags::FLAG_C; // OK
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1; // OK

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myClassBitFlag ^ myClass::enumClassFlags::FLAG_TEST1) == myClass::enumClassFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClassBitFlag.get() << " ^ " << (int)myClass::enumClassFlags::FLAG_TEST1 << ") == " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag AND FLAG_TEST1 MATCH [OK]\r\n"; //OK
    }

    if ((myClassBitFlag ^ myClass::enumClassFlags::FLAG_TEST2) != myClass::enumClassFlags::NO_FLAGS)
    {
        cout << "(" << (int)myClassBitFlag.get() << " ^ " << (int)myClass::enumClassFlags::FLAG_TEST2 << ") != " << (int)myClass::enumClassFlags::NO_FLAGS << ": myClassBitFlag AND FLAG_TEST2 DOES NOT MATCH [OK]\r\n"; //OK
    }

    //BITWISE AND ASSIGN (&=)
    myClassBitFlag &= myClass::enumClassFlags::FLAG_B; // => 0x00 since B is not set (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;
    myClassBitFlag &= myClass::enumClassFlags::FLAG_A; // => 0x01 since A is set (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE OR ASSIGN (|=)
    myClassBitFlag |= myClass::enumClassFlags::FLAG_B; // => BIT B becomes set (0x57) (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myClassBitFlag ^= myClass::enumClassFlags::FLAG_TEST1; // =>0x00 Since flags and flag_test1 match  (OK)
    myClassBitFlag = myClass::enumClassFlags::FLAG_TEST1;  // 
    myClassBitFlag ^= myClass::enumClassFlags::FLAG_TEST2; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL (OK)

    return;

}

/*
    Function used to test cppBitFlag Templated DataType
    STATUS: OK, TESTED
*/
void testBitFlagClassDataType()
{
    cppBitFlag<int, int> myBitFlag(0x01 | 0x04 | 0x10 | 0x40); // 0x55 (FALG_TEST1)

    cppBitFlag<int, int> myDummyBitFlag(~0x55); // FLAG_TEST2

    cout << "\r\n" << "testBitFlagClassDataType():\r\n";

    // Test Assignemnt
    myBitFlag = myDummyBitFlag;
    myBitFlag = 0x55;

    myBitFlag.setBits(0x02); // 0x57
    myBitFlag = 0x55; // 0x55 (OK)
    myBitFlag.setBit(1); // 0x57
    myBitFlag = 0x55; // 0x55 (OK)
    myBitFlag.configBits(0x19, 0xA6); // 0x1D
    myBitFlag.configBits(0x55, 0xA2); // 0x55
    myBitFlag.clearBits(0x05); // 0x50
    myBitFlag.clearBit(4); // clear bit 4 => 0x40
    myBitFlag.toggleBits(0x01); // 0x41
    myBitFlag.toggleBit(); // Toggle bit 0 => 0x40

    myBitFlag = ~0x55; // ~0x55 (OK)
    myBitFlag = 0x55; // 0x55 (OK)
    bool boolResult = false;


    // COMPARIASON
    if (myBitFlag == 0x55)
    {
        cout << myBitFlag.get() << " == " << (int)enumClasslessFlags::FLAG_TEST1 << ": myBitFlag matches the FLAG TEST 1 Pattern [OK]\r\n"; // OK
    }
    if (myBitFlag != (int)enumClasslessFlags::FLAG_TEST2)
    {
        cout << myBitFlag.get() << " != " << (int)enumClasslessFlags::FLAG_TEST2 << ": myBitFlag does not match FLAG TEST 2 Pattern [OK]\r\n"; // OK
    }

    //LOGICAL NEAGTION(!)
    boolResult = !myBitFlag;
    boolResult = !0x55;
    boolResult = !0x00;

    // LOGICAL AND(&&)
    if (myBitFlag && 0xFF)
    {
        cout << myBitFlag.get() << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myBitFlag > 0 AND and ALL_FLAGS > 0 [OK]\r\n"; // (OK)
    }
    else
    {
        cout << myBitFlag.get() << " && " << (int)enumClasslessFlags::ALL_FLAGS << ": myBitFlag = 0 OR ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (myBitFlag && 0x00)
    {
        cout << myBitFlag.get() << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myBitFlag > 0 AND and NO_FLAGS > 0 [FAIL]\r\n";
    }
    else
    {
        cout << myBitFlag.get() << " && " << (int)enumClasslessFlags::NO_FLAGS << ": myBitFlag = 0 OR NO_FLAGS = 0 [OK]\r\n"; // OK
    }

    // LOGICAL OR(||)
    if (myBitFlag || 0xFF)
    {
        cout << myBitFlag.get() << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myBitFlag > 0 OR ALL_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << myBitFlag.get() << " || " << (int)enumClasslessFlags::ALL_FLAGS << ": myBitFlag = 0 AND ALL_FLAGS = 0 [FAIL]\r\n";
    }
    if (0x01 || 0x00)
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A > 0 OR NO_FLAGS > 0 [OK]\r\n"; // OK
    }
    else
    {
        cout << (int)enumClasslessFlags::FLAG_A << " || " << (int)enumClasslessFlags::NO_FLAGS << ": FLAG A = 0 AND NO_FLAGS = 0 [FAIL]\r\n";
    }
    if (~enumClasslessFlags::NO_FLAGS || ~enumClasslessFlags::ALL_FLAGS)
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS > 0 OR ~ALL_FLAGS > 0 [OK]\r\n"; //OK
    }
    else
    {
        cout << (int)~enumClasslessFlags::NO_FLAGS << " || " << (int)~enumClasslessFlags::ALL_FLAGS << ": ~NO FLAGS = 0 AND ~ALL_FLAGS = 0 [FAIL]\r\n";
    }

    // Bitwise NOT (~)
    if ((myBitFlag & 0x01) == ~0x01)
    {
        cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in myBitFlag except Flag A [FAIL]\r\n";
    }
    else
    {
        cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)~enumClasslessFlags::FLAG_A << ": All bits set in myBitFlag except Flag A is not true [OK]\r\n"; // OK
    }

    myBitFlag = ~0x01; // OK
    myBitFlag = ~0x02; // OK
    myBitFlag = 0x55; // OK

    //BITWISE AND (&) "BIT CHECK"
    if ((myBitFlag & 0x01) == 0x01)
    {
        if (myBitFlag.isSet(0x01))
        {
            if (myBitFlag.isSetAtIx(0))
            {
                cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myBitFlag [OK]\r\n"; // OK
            }
        }
    }
    else
    {
        cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") == " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not in myBitFlag [FAIL]\r\n";
    }
    if ((myBitFlag & 0x01) != 0x01)
    {
        if (myBitFlag.isClear(0x01))
        {
            if (myBitFlag.isClear(0))
            {
                cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is not set in myBitFlag [FAIL] \r\n";
            }
        }
    }
    else
    {
        cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myBitFlag [OK]\r\n"; // OK
    }

    if ((myBitFlag & 0x02) != 0x02)
    {
        if (myBitFlag.isClear(0x02))
        {
            if (myBitFlag.isClearAtIx(1))
            {
                cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_B << ") != " << (int)enumClasslessFlags::FLAG_B << ": Flag B is not set in myBitFlag [OK] \r\n";
            }
        }
    }
    else
    {
        cout << "(" << myBitFlag.get() << " & " << (int)enumClasslessFlags::FLAG_A << ") != " << (int)enumClasslessFlags::FLAG_A << ": Flag A is set in myBitFlag [OK]\r\n"; // OK
    }

    //BITWISE OR (|)
    myBitFlag = 0x01 | 0x04; // 0x05 (OK)
    myBitFlag = 0x55; // OK

    //BITWISE XOR (^) "UNEQUAL DETECTOR"
    if ((myBitFlag ^ 0x55) == 0x00)
    {
        cout << "(" << myBitFlag.get() << " ^ " << (int)enumClasslessFlags::FLAG_TEST1 << ") == " << (int)enumClasslessFlags::NO_FLAGS << ": myBitFlag AND FLAG_TEST1 MATCH [OK]\r\n"; //OK
    }

    if ((myBitFlag ^ (int)enumClasslessFlags::FLAG_TEST2) != (int)enumClasslessFlags::NO_FLAGS)
    {
        cout << "(" << myBitFlag.get() << " ^ " << (int)enumClasslessFlags::FLAG_TEST2 << ") != " << (int)enumClasslessFlags::NO_FLAGS << ": myBitFlag AND FLAG_TEST2 DOES NOT MATCH [OK]\r\n"; //OK
    }

    //BITWISE AND ASSIGN (&=)
    myBitFlag &= 0x02; // => 0x00 since B is not set (OK)
    myBitFlag = 0x55;
    myBitFlag &= 0x01; // => 0x01 since A is set (OK)
    myBitFlag = 0x55;

    //BITWISE OR ASSIGN (|=)
    myBitFlag |= 0x02; // => BIT B becomes set (0x57) (OK)
    myBitFlag = 0x55;

    //BITWISE XOR ASSIGN (^=) (TOGGLE BIT) (OR AND THE NOT)
    myBitFlag ^= 0x55; // =>0x00 Since flags and flag_test1 match  (OK)
    myBitFlag = 0x55;  // 
    myBitFlag ^= ~0x55; // / => 0xFF, SINCE ALL BITS ARE UNEQUAL (OK)

    return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
