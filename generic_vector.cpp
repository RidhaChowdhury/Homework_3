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

void constructingVectorsTest() {
    TemplateVector<int> vector1(20);
    unitTest(vector1.getCapacity(), 32, "vector1.getCapacity()");
    unitTest(vector1.getSize(), 0, "vector1.getSize()");

    TemplateVector<int> vector2(100);
    unitTest(vector2.getCapacity(), 128, "vector2.getCapacity()");
    unitTest(vector2.getSize(), 0, "vector2.getSize()");

    TemplateVector<int> vector3(10);
    unitTest(vector3.getCapacity(), 16, "vector3.getCapacity()");
    unitTest(vector3.getSize(), 0, "vector3.getSize()");
}

void pushingAndAccessingElementsTest() {
    TemplateVector<int> vector(10);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    unitTest(vector[0], 1, "vector[0]");
    unitTest(vector[1], 2, "vector[1]");
    unitTest(vector[2], 3, "vector[2]");
    unitTest(vector[3], 4, "vector[3]");
    unitTest(vector[4], 5, "vector[4]");

    unitTest(vector.at(0), 1, "vector.at(0)");
    unitTest(vector.at(1), 2, "vector.at(1)");
    unitTest(vector.at(2), 3, "vector.at(2)");
    unitTest(vector.at(3), 4, "vector.at(3)");
    unitTest(vector.at(4), 5, "vector.at(4)");

    unitTest(vector.front(), 1, "vector.front()");
    unitTest(vector.back(), 5, "vector.back()");

    // write a unit test that forces the vector to resize
    TemplateVector<int> vector2(1);
    for(int i = 0; i < 20; i++)
        vector2.push_back(i);
    unitTest(vector2.getSize(), 20, "vector2.getSize()");
    for(int i = 0; i < 20; i++)
        unitTest(vector2[i], i, "vector2[" + to_string(i) + "]");
}

void insertingElementsTest() {
    TemplateVector<int> vector(10);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    vector.insert(0, 10);
    unitTest(vector[0], 10, "vector[0]");
    unitTest(vector[1], 1, "vector[1]");
    unitTest(vector[2], 2, "vector[2]");
    unitTest(vector[3], 3, "vector[3]");
    string indexOutOfBounds = "Index out of bounds";
    string error = "Error: ";
    unitTest(vector[4], 4, "vector[4]");
    unitTest(vector[5], 5, "vector[5]");

    vector.insert(2, 20);
    unitTest(vector[0], 10, "vector[0]");
    unitTest(vector[1], 1, "vector[1]");
    unitTest(vector[2], 20, "vector[2]");
    unitTest(vector[3], 2, "vector[3]");
    unitTest(vector[4], 3, "vector[4]");
    unitTest(vector[5], 4, "vector[5]");
    unitTest(vector[6], 5, "vector[6]");
}

void popBackTest() {
    TemplateVector<int> vector(10);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    vector.pop_back();
    unitTest(vector.back(), 4, "vector.back()");
}


#pragma endregion

enum commands {
    at = 1,
    push_back = 2,
    insert = 3,
    pop_back = 4,
    print = 5,
    get_size = 6,
    get_capacity = 7,
    unit_tests = 8,
    help = 9,
    quit = 10,

    //settings
    auto_print = 11
};

void helpText() {
    cout << "Commands: " << endl;
    cout << "1. at (index) returns value" << endl;
    cout << "2. push_back (value)" << endl;
    cout << "3. insert (index, value)" << endl;
    cout << "4. pop_back" << endl;
    cout << "5. print" << endl;
    cout << "6. get_size" << endl;
    cout << "7. get_capacity" << endl;
    cout << "8. Run my development unit tests" << endl;
    cout << "9. help" << endl;
    cout << "10. quit" << endl;
    cout << "11. toggle auto_print" << endl;
}

/*
template <typename T>
*TemplateVector<T> createVector() {
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;
    /*
     * Before asking for the starting capacity, prompt the user to specify what data type they
        want the vector to store in data
        o 1 for int
        o 2 for float
        o 3 for double
        o 4 for string
        o 5 for bool

        Expected prompt/input with sample output

        Specify what data type to store in vector:
        1) int
        2) float
        3) double
        4) string
        5) bool

    int dataType;
    cout << "Specify what data type to store in vector: " << endl;
    cout << "1) int" << endl;
    cout << "2) float" << endl;
    cout << "3) double" << endl;
    cout << "4) string" << endl;
    cout << "5) bool" << endl;
    cin >> dataType;
}
*/
int main()
{
    int capacity;
    cout << "Enter starting capacity of vector: ";
    cin >> capacity;

    // Declare a TemplateVector with an int type argument
    TemplateVector<int> vector(capacity);

    cout << "Initialized vector with capacity " << vector.getCapacity() << endl << endl;

    bool autoPrint = false;

    // Implement command prompt loop
    bool isRunning = true;
    helpText();
    while(isRunning)
    {
        int command, index, value;
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
                cout << "Element at index " << index << ": " << vector.at(index);
                break;

            case push_back:
                // implement push_back command
                cin >> value;
                vector.push_back(value);
                break;

            case insert:
                // implement insert command
                cin >> index >> value;
                vector.insert(index, value);
                break;

            case pop_back:
                // implement pop_back command
                vector.pop_back();
                break;

            case print:
                // implement print command
                vector.print();
                break;

            case get_size:
                // implement get_size command
                cout << "Size: " << vector.getSize();
                break;

            case get_capacity:
                // implement get_capacity command
                cout << "Capacity: " << vector.getCapacity();
                break;

            case unit_tests:
                cout << "Running constructing vectors test" << endl;
                constructingVectorsTest();
                cout << "Running pushing and accessing elements test" << endl;
                pushingAndAccessingElementsTest();
                // run the rest of the tests with a cout before
                cout << "Running inserting elements test" << endl;
                insertingElementsTest();
                cout << "Running the pop back test" << endl;
                popBackTest();
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
        if(command != print && autoPrint)
            vector.print();

        cout << endl;
    }

    return 0;

}