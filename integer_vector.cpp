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
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#pragma region vector-class
class BasicVector
{
private:
	int size;
	int capacity;
	int* data;

	void resize();

public:
	BasicVector(int);
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

}

BasicVector::BasicVector(int capacity)
{
    if(capacity < 16) this->capacity = 16;
    else this->capacity = (int)log2(capacity);
    this->size = 0;
    data = new int[this->capacity];
}

BasicVector::~BasicVector()
{

}

int& BasicVector::at(int index)
{

	exit(1);
}

int& BasicVector::operator[](int index)
{

	exit(1);
}

int &BasicVector::front() const {
    return data[0];
}

int &BasicVector::back() const {
    return data[size - 1];
}

void BasicVector::push_back(int) {

}

void BasicVector::insert(int, int) {

}

void BasicVector::pop_back() {

}

int BasicVector::getSize() const {
    return this->size;
}

int BasicVector::getCapacity() const {
    return this->capacity;
}

void BasicVector::print() const {
    for(int index = 0; index < this->size; index++) {
        cout << data[index];
        if(index < this->size - 1) cout << ", ";
    }
}
#pragma endregion

#pragma region unit-tests
template <typename T>
void unitTest(T returned, T expected, string testName)
{
    if (returned == expected)
        cout << "PASSED: " << testName << endl;
    else
        cout << "FAILED: " << testName << " (returned " << returned << ", expected " << expected << ")" << endl;
}

void contructingVectors() {
    BasicVector vector1(20);
    unitTest(vector1.getCapacity(), 32, "vector1.getCapacity()");
    unitTest(vector1.getSize(), 0, "vector1.getSize()");
}

#pragma endregion

int main()
{
	int capacity;
	cout << "Enter starting capacity of vector: ";
	cin >> capacity;

	BasicVector vector(capacity);

    cout << vector.getSize() << endl;
    cout << vector.getCapacity() << endl;

    // Implement command prompt loop
	//while(true)
	{
		
	}

	return 0;
}