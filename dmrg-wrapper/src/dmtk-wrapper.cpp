#ifndef __DMTK_WRAPPER_CPP__
#define __DMTK_WRAPPER_CPP__

#include "dmtk/dmtk.h"

extern "C" {
  #define GETENUM(id) unsigned int id() { return dmtk::id; }

  GETENUM(LEFT)
  GETENUM(RIGHT)
  GETENUM(CENTER)

  #undef GETENUM
};

#endif//__DMTK_WRAPPER_CPP__
