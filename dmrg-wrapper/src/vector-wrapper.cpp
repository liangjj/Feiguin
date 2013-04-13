#ifndef __VECTOR_WRAPPER_CPP__
#define __VECTOR_WRAPPER_CPP__

#include "dmtk/vector.h"

using namespace dmtk;

extern "C" {
  #define TYPE double
  Vector<TYPE>* Vector_new() { return new Vector<TYPE>(); }
  Vector<TYPE>* Vector_new_sized(size_t s) { return new Vector<TYPE>(s); }
  size_t Vector_size(Vector<TYPE>* v) { return v->size2(); }
};

#endif//__VECTOR_WRAPPER_CPP__
