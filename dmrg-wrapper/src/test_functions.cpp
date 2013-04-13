#ifndef __TEST_FUNCTIONS_CPP__
#define __TEST_FUNCTIONS_CPP__

#include <cstdlib>

extern "C" {
  double * get_array(int s) { return new double[s]; }
  void free_array(void* a) { free(a); }
};

#endif//__TEST_FUNCTIONS_CPP__
