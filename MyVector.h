#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector {

private:
  // default initial capacity
  static int DEFAULT_CAPACITY;
  // current size, capacity, and data pointer
  int msize;
  int mcapacity;
  int *data;
  // doubles the capacity of the underlying array
  void doubleCapacity();

public:
  // constructs the vector with default capacity
  MyVector();
  // copy constructor
  MyVector(const MyVector &other);
  // assignment operator
  MyVector &operator=(const MyVector &other);
  // destructor
  ~MyVector();
  // returns the number of elements
  int size() const;
  // returns the current capacity
  int capacity() const;
  // adds an element to the end
  void push_back(int x);
  // access specified element
  int &operator[](int index) const;
  // removes the last element
  void pop_back();
};

#endif