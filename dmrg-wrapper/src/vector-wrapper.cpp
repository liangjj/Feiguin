#ifndef __VECTOR_WRAPPER_CPP__
#define __VECTOR_WRAPPER_CPP__

#include "dmtk/vector.h"

using namespace dmtk;

struct PYVector {
  void * vec;
};

extern "C" {
  void Vector_new(struct PYVector * v) { v->vec = (void*)new Vector<double>(); }
  void Vector_new_sized(struct PYVector * v, size_t s) { v->vec = (void*)new Vector<double>(s); }
  void Vector_del(struct PYVector * v) { free(v->vec); }

  size_t Vector_size(struct PYVector * v) { return (*(Vector<double>*)(v->vec)).size2(); }
  void Vector_accessor(const struct PYVector * v, size_t i, double * d) { d = &(*(Vector<double>*)(v->vec))(i); }
};

#endif//__VECTOR_WRAPPER_CPP__
