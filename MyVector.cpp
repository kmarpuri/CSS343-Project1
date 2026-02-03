#include "MyVector.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Initialize static member
int MyVector::DEFAULT_CAPACITY = 3;

// Default constructor
MyVector::MyVector() {
  msize = 0;
  mcapacity = DEFAULT_CAPACITY;
  data = new int[mcapacity];
}

// Copy constructor
MyVector::MyVector(const MyVector &other) {
  msize = 0, mcapacity = 0;
  data = nullptr;
  *this = other;
}

// Assignment operator
MyVector &MyVector::operator=(const MyVector &other) {
  if (this != &other) {
    msize = other.msize;
    mcapacity = other.mcapacity;
    delete[] data;
    data = new int[mcapacity];
    for (int i = 0; i < msize; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

// Returns the current capacity
int MyVector::capacity() const { return mcapacity; }

// Returns the number of elements
int MyVector::size() const { return msize; }

// Adds an element to the end
void MyVector::push_back(const int x) {
  if (msize == mcapacity) {
    doubleCapacity();
  }
  data[msize++] = x;
}

// Removes the last element. Assumes size > 0.
void MyVector::pop_back() { msize--; }

// Access specified element
int &MyVector::operator[](const int index) const {
  assert(index >= 0 && index < msize);
  return data[index];
}

// Destructor
MyVector::~MyVector() { delete[] data; }

// Doubles the capacity of the underlying array
void MyVector::doubleCapacity() {
  mcapacity *= 2;
  int *temp = new int[mcapacity];
  for (int i = 0; i < msize; i++) {
    temp[i] = data[i];
  }
  delete[] data;
  data = temp;
}