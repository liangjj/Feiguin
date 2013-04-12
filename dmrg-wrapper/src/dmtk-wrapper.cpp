#ifndef __DMTK_WRAPPER_HPP__
#define __DMTK_WRAPPER_HPP__

#include "dmtk/dmtk.h"

extern "C" {
  #define GETENUM(id) unsigned int id() { return dmtk::id; }

  GETENUM(LEFT)
  GETENUM(RIGHT)
  GETENUM(CENTER)

  #undef GETENUM
};

#include "enums-wrapper.hpp"

#endif//__DMTK_WRAPPER_HPP__
