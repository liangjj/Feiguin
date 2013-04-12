#ifndef __DMTK_WRAPPER_HPP__
#define __DMTK_WRAPPER_HPP__

#include "dmtk/dmtk.h"

extern "C" {
  int Left(){ return 1; }
  int Right(){ return 2; }
  int Center(){ return 3; }
};

#endif//__DMTK_WRAPPER_HPP__
