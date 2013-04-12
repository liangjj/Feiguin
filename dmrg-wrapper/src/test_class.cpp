#include "test_class.hpp"

Test::Test() {
  bar = 1;
};

Test::~Test() {};

unsigned int Test::foo() {
  return 1;
};

extern "C" {
  Test* Test_new(){ return new Test(); }
  void Test_foo(Test* test) { test->foo(); }
};
