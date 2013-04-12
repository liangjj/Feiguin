#ifndef __DMTK_WRAPPER_HPP__
#define __DMTK_WRAPPER_HPP__

#include "dmtk/dmtk.h"

extern "C" {
  int Left(){ return dmtk::LEFT; }
  int Right(){ return dmtk::RIGHT; }
  int Center(){ return dmtk::CENTER; }
};

#endif//__DMTK_WRAPPER_HPP__
