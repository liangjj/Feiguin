#include "test_class.hpp"
#include <cstdlib>

Test::Test() {
  bar = 1;
};

Test::~Test() {};

unsigned int Test::foo() {
  return 5;
};

extern "C" {
  Test* Test_new(){ return new Test(); printf("2");}
  unsigned int Test_foo(Test* test) { return test->foo(); }
  int* Test_array() { int * i = (int*)malloc(sizeof(int)*5); return i; }
};
