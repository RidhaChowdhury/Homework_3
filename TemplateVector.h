//
// Created by Ridha on 11/2/2022.
//

#ifndef HOMEWORK_3_TEMPLATEVECTOR_H
#define HOMEWORK_3_TEMPLATEVECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class TemplateVector {
private:
    int size = 0;
    int capacity{};
    T* data;

    void resize();

public:
    explicit TemplateVector(int);
    ~TemplateVector();

    T& at(int);
    T& operator[](int);
    T& front() const;
    T& back() const;

    void push_back(T);
    void insert(int, T);
    void pop_back();

    int getSize() const;
    int getCapacity() const;

    void print() const;
};

template <typename T>
void TemplateVector<T>::resize() {
    T* newData = new T[this->capacity * 2];
    for(int index = 0; index < this->size; index++) {
        newData[index] = this->data[index];
    }
    delete []data;
    data = newData;
    capacity *= 2;
}

template <typename T>
TemplateVector<T>::TemplateVector(int capacity) {
    if(capacity < 16)
        capacity = 16;
    else
        capacity = (int)pow(2, (int)log2(capacity) + 1);
    this->capacity = capacity;

    data = new T[this->capacity];
}

template <typename T>
TemplateVector<T>::~TemplateVector() {
    delete []data;
}

template <typename T>
T & TemplateVector<T>::at(int index) {
    if(index < 0 || index >= size) {
        cerr << "Error: Index out of bounds" << endl;
        exit(1);
    }
    return data[index];
}

template <typename T>
T & TemplateVector<T>::operator[] (int index) {
    return at(index);
}
template <typename T>
T & TemplateVector<T>::front() const {
    return data[0];
}

template <typename T>
T & TemplateVector<T>::back() const {
    return data[size - 1];
}

template <typename T>
void TemplateVector<T>::push_back(T value) {
    if(size == capacity)
        resize();
    data[size] = value;
    size++;
}

template <typename T>
void TemplateVector<T>::insert(int index, T value) {
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

template <typename T>
void TemplateVector<T>::pop_back() {
    if(this->size == 0)
        return;
    this->size--;
}

template <typename T>
int TemplateVector<T>::getSize() const {
    return this->size;
}

template <typename T>
int TemplateVector<T>::getCapacity() const {
    return this->capacity;
}

template <typename T>
void TemplateVector<T>::print() const {
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

#endif //HOMEWORK_3_TEMPLATEVECTOR_H
