//---------------------------------------------------------------------
// Name: Michael Melusky
// Email: mcm297@psu.edu
// Class: CMPSC 122, Section 3
// Program 3.2
// Due Date: March 19 2020, 11:59 PM
//
// Description: This program implements a basic integer vector
// and provides the user with an interactive prompting system
// to issue commands over an instance of our TemplateVector class.
//
// Acknowledgements:
// 1. Please use this portion of the banner comment to list
// any resources or individuals you consulted on the creation
// of this program.

// 1. Used github copilot to write unit tests and the
//    main function with looping menu of commands.
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include "TemplateVector.h"
#include <string>

using namespace std;

#pragma region vector-class


#pragma endregion

#pragma region unit-tests

template <typename T>
bool unitTest(T returned, T expected, const string& testName)
{
    if (returned == expected) {
        cout << "\u2705";
        cout << "\033[1;32m";
        cout << "PASSED: " << testName << endl;
        return true;
    }
    else {
        cout << "\u274C";
        cout << "\033[31m";
        cout << "FAILED: " << testName << " (returned " << returned << ", expected " << expected << ")" << endl;
        return false;
    }
}

#pragma endregion

enum commands {
    at,
    get,
    front,
    back,
    insert,
    push,
    pop,
    get_size,
    get_capacity,
    print,
    help,
    quit,

    //settings
    auto_print
};

void helpText() {
    cout << "Commands: " << endl;
    cout << at <<           ": at       <index>         - Invoke the at function, passing the index as its parameter, print result" << endl;
    cout << get <<          ": get      <index>         - Invoke the operator[] function, passing index its parameter, print result" << endl;
    cout << front <<        ": front                    - Invoke the front function, print the result" << endl;
    cout << back <<         ": back                     - Invoke the back function, print the result" << endl;
    cout << insert <<       ": insert   <index> <value> - Invoke the insert function, passing index and value as its two parameters" << endl;
    cout << push <<         ": push     <value>         - Invoke the push_back function, passing value its parameter" << endl;
    cout << pop <<          ": pop                      - Invoke the pop_back function." << endl;
    cout << get_size <<     ": size                     - Invoke the size function, print the returned value" << endl;
    cout << get_capacity << ": capacity                 - Invoke the capacity function, print the returned value" << endl;
    cout << print <<        ": print                    - Invoke the print command" << endl;
    cout << help <<         ": help                    - prints the list of commands and the inputs." << endl;
    cout << quit <<         ": quit                    - Break out of loop, exit program normally." << endl;
    cout << auto_print <<   ": auto_print              - Toggle auto print on/off" << endl;
}

template <typename T>
void menu(TemplateVector<T> templateVector) {
    // Implement command prompt loop
    cout << "Initialized vector with capacity " << templateVector.getCapacity() << endl << endl;

    bool isRunning = true;
    bool autoPrint = false;

    helpText();

    while(isRunning)
    {
        int command, index;
        T value;
        cout << "(" << help << ". for help)";
        cout << "\033[1m";
        cout << "\033[4m";
        cout << "Enter command #: ";
        cout << "\033[0m";
        cin >> command;
        switch(command) {
            case at:
                // implement at command
                cin >> index;
                cout << "Element at index " << index << ": " << templateVector.at(index);
                break;

            case push:
                // implement push_back command
                cin >> value;
                templateVector.push_back(value);
                break;

            case insert:
                // implement insert command
                cin >> index >> value;
                templateVector.insert(index, value);
                break;

            case pop:
                // implement pop_back command
                templateVector.pop_back();
                break;

            case print:
                // implement print command
                templateVector.print();
                break;

            case get_size:
                // implement get_size command
                cout << "Size: " << templateVector.getSize();
                break;

            case get_capacity:
                cout << "Capacity: " << templateVector.getCapacity();
                break;

            case help:
                helpText();
                break;

            case quit:
                isRunning = false;
                break;


            case auto_print:
                // implement auto print command
                autoPrint = !autoPrint;
                break;

            default:
                cout << "Invalid command" << endl;
                break;
        }
        if(command != print && autoPrint) {
            cout << endl;
            templateVector.print();
        }

        cout << endl;
    }
}

int main()
{
    int capacity;
    cout << "Enter starting capacity of vector: ";
    cin >> capacity;


    int type = 0;
    cout << "Specify what data type to store in vector: " << endl;
    cout << "1) int" << endl;
    cout << "2) float" << endl;
    cout << "3) double" << endl;
    cout << "4) string" << endl;
    cout << "5) bool" << endl;
    cin >> type;
    switch (type) {
        case 1:
            menu(TemplateVector<int>(capacity));
            break;
        case 2:
            menu(TemplateVector<float>(capacity));
            break;
        case 3:
            menu(TemplateVector<double>(capacity));
            break;
        case 4:
            menu(TemplateVector<string>(capacity));
            break;
        case 5:
            menu(TemplateVector<bool>(capacity));
            break;
        default:
            cout << "Invalid type" << endl;
            break;
    }

    return 0;
}