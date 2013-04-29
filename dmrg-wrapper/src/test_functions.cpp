#ifndef __TEST_FUNCTIONS_CPP__
#define __TEST_FUNCTIONS_CPP__

#include <cstdlib>
#include <cstdio>

using namespace std;

struct PYVector {
  double * vec;
};

extern "C" {
  void get_array(struct PYVector * v, unsigned int s) {
    v->vec = new double[s];
  }
  void free_array(struct PYVector * v) {
    free(v->vec);
  }
};

#endif//__TEST_FUNCTIONS_CPP__
