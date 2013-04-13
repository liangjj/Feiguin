#ifndef __TEST_FUNCTIONS_CPP__
#define __TEST_FUNCTIONS_CPP__

extern "C" {
  double * get_array(int s) { return new double[s]; }
};

#endif//__TEST_FUNCTIONS_CPP__
