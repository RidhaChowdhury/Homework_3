//---------------------------------------------------------------------
// Name: Michael Melusky
// Email: mcm297@psu.edu
// Class: CMPSC 122, Section 3
// Program 3.2
// Due Date: March 19 2020, 11:59 PM
//
// Description: This program implements a basic integer vector
// and provides the user with an interactive prompting system
// to issue commands over an instance of our BasicVector class.
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

using namespace std;

#pragma region vector-class

string error = "Error: ";
string indexOutOfBounds = "Index out of bounds";

class BasicVector
{
private:
	int size = 0;
	int capacity;
	int* data;

	void resize();

public:
	explicit BasicVector(int);
	~BasicVector();

	int& at(int);
	int& operator[](int);
	int& front() const;
	int& back() const;

	void push_back(int);
	void insert(int, int);
	void pop_back();

	int getSize() const;
	int getCapacity() const;

	void print() const;
};

void BasicVector::resize()
{
    int* newData = new int[this->capacity * 2];
    for(int index = 0; index < this->size; index++) {
        newData[index] = this->data[index];
    }
    delete []data;
    data = newData;
    capacity *= 2;
}

BasicVector::BasicVector(int capacity)
{
    if(capacity < 16)
        capacity = 16;
    else
        capacity = (int)pow(2, (int)log2(capacity) + 1);
    this->capacity = capacity;

    data = new int[this->capacity];
}

BasicVector::~BasicVector()
{
    for(int index = 0; index < this->size; index++) {
        data[index] = 0;
    }
    delete []data;
}

int& BasicVector::at(int index)
{
    if(index < 0 || index >= size) {
        cerr << "Error: Index out of bounds" << endl;
        exit(1);
    }
    return data[index];
}

int& BasicVector::operator[](int index)
{
    return at(index);
}

int &BasicVector::front() const {
    return data[0];
}

int &BasicVector::back() const {
    return data[size - 1];
}

void BasicVector::push_back(int value) {
    if(size == capacity)
        resize();
    data[size] = value;
    size++;
}

void BasicVector::insert(int index, int value) {
    if(index < 0 || index >= this->size) {
        cerr << "Error: Index out of bound " << index << endl;
        exit(1);
    }

    if(this->size == this->capacity)
        resize();

    for (int i = this->size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

void BasicVector::pop_back() {
    if(this->size == 0)
            return;
        data[this->size - 1] = 0;
        size--;
}

int BasicVector::getSize() const {
    return this->size;
}

int BasicVector::getCapacity() const {
    return this->capacity;
}

void BasicVector::print() const {
    cout << "elements(" << this->size << "/" << this->capacity << "): ";
    // Set console to bold
    cout << "\033[1m";
    for(int index = 0; index < this->size; index++) {
        cout << data[index];
        if(index < this->size - 1) cout << ", ";
    }
    cout << "\033[0m" << endl;
    cout << endl;
}
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
    BasicVector vector1(20);
    unitTest(vector1.getCapacity(), 32, "vector1.getCapacity()");
    unitTest(vector1.getSize(), 0, "vector1.getSize()");

    BasicVector vector2(100);
    unitTest(vector2.getCapacity(), 128, "vector2.getCapacity()");
    unitTest(vector2.getSize(), 0, "vector2.getSize()");

    BasicVector vector3(10);
    unitTest(vector3.getCapacity(), 16, "vector3.getCapacity()");
    unitTest(vector3.getSize(), 0, "vector3.getSize()");
}

void pushingAndAccessingElementsTest() {
    BasicVector vector(10);
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
    BasicVector vector2(1);
    for(int i = 0; i < 20; i++)
        vector2.push_back(i);
    unitTest(vector2.getSize(), 20, "vector2.getSize()");
    for(int i = 0; i < 20; i++)
        unitTest(vector2[i], i, "vector2[" + to_string(i) + "]");
}

void insertingElementsTest() {
    BasicVector vector(10);
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
    BasicVector vector(10);
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

int main()
{
	int capacity;
	cout << "Enter starting capacity of vector: ";
	cin >> capacity;

    BasicVector vector(capacity);

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

            case push:
                // implement push_back command
                cin >> value;
                vector.push_back(value);
                break;

            case insert:
                // implement insert command
                cin >> index >> value;
                vector.insert(index, value);
                break;

            case pop:
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