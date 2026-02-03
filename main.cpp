#include "MyVector.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Basic functionality test
void test1() {
  MyVector v;
  assert(v.size() == 0);
  v.push_back(10);
  v.push_back(7);
  assert(v.size() == 2 && v.capacity() == 3);
  assert(v[0] == 10 && v[1] == 7);
  v.push_back(20);
  assert(v.size() == 3 && v.capacity() == 3);
  v.push_back(30);
  assert(v.size() == 4 && v.capacity() == 6);
  assert(v[0] == 10);
  assert(v[3] == 30);
  v[3] = 50;
  assert(v[3] == 50);
}

// Test copy constructor
void test2() {
  MyVector v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i * 5);
  }
  MyVector v2(v);
  v.push_back(60);
  assert(v.size() == 11 && v.capacity() == 12);
  assert(v2.size() == 10 && v2.capacity() == 12);
}

// Test assignment operator
void test3() {
  MyVector v;
  for (int i = 0; i < 5; i++) {
    v.push_back(i * 10);
  }
  MyVector v2;
  v2.push_back(100);
  v2 = v;
  assert(v2.size() == 5 && v2.capacity() == 6);
  v.push_back(60);
  assert(v.size() == 6 && v.capacity() == 6);
  assert(v2.size() == 5 && v2.capacity() == 6);
  v2 = v2; // Self-assignment
  assert(v2.size() == 5 && v2.capacity() == 6);
  v2 = v;
  assert(v2.size() == 6 && v2.capacity() == 6);
  v.push_back(70);
  assert(v.size() == 7 && v.capacity() == 12);
  assert(v2.size() == 6 && v2.capacity() == 6);
}

int main() {
  test1();
  test2();
  test3();
  cout << "All tests passed!" << endl;
}