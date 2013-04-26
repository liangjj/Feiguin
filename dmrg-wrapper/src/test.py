#!/usr/bin/env python

import ctypes

class Vector(ctypes.Structure):
  """
  Test class wrapper.
  """
  _fields_ = [
    ("vec",ctypes.POINTER(ctypes.c_double)),
  ]

v = Vector()

lib = ctypes.cdll.LoadLibrary('dmtk.so')
lib.get_array(ctypes.byref(v),5)
for i in xrange(6): print v.vec[i]
lib.free_array(ctypes.byref(v))
