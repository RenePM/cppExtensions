// cppTemplatesImplConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cppTemplateImplConsole.h"
#include "myTemplateClass.h"

using namespace std;
using namespace myNameSpace;

int main()
{
    std::cout << "Hello World!\n";

    myContainerTest();
    myDynamicContainerTest();
}

void myContainerTest()
{
    auto    containerA = myContainer<int>(5);
    auto    containerB = myContainer<int>(10);

    int retVal;
    string retStr;

    retVal = containerA.get();
    containerA.set(containerB);
    retVal = containerA.get();
    containerA.set(50);

    auto    containerC = myContainer<string>("5");
    auto    containerD = myContainer<string>("10");

    retStr = containerC.get();
    containerC.set(containerD);
    retStr = containerD.get();

}

void myDynamicContainerTest()
{
    auto    containerA = myDynamicContainer<int>(5);
    auto    containerB = myDynamicContainer<int>(10);

    int retVal;
    string retStr;

    retVal = containerA.get(0);
    containerA.set(containerB.get(0));
    retVal = containerA.get();
   
    auto    containerC = myDynamicContainer<string>("5");
    auto    containerD = myDynamicContainer<string>("10");

    retStr = containerC.get();
    containerC.set(containerD.get(0));
    retStr = containerD.get();
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
