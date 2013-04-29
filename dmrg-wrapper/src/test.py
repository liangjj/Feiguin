#!/usr/bin/env python

import ctypes

class Vector(ctypes.Structure):
  """
  Test class wrapper.
  """
  _fields_ = [
    #("vec",ctypes.POINTER(ctypes.c_double)),#For test function array
    ("vec",ctypes.c_void_p),
  ]

v = Vector()
vnew = Vector()

lib = ctypes.cdll.LoadLibrary('dmtk.so')
#lib.get_array(ctypes.byref(v),5)
lib.Vector_new_sized(ctypes.byref(v),5)
lib.Vector_new_from_sized(ctypes.byref(vnew),5,ctypes.byref(v))
for i in xrange(lib.Vector_size(ctypes.byref(v))):
  print "v",
  print lib.Vector_accessor(ctypes.byref(v),i)
for i in xrange(lib.Vector_size(ctypes.byref(vnew))):
  print "vnew",
  print lib.Vector_accessor(ctypes.byref(vnew),i)
lib.Vector_del(ctypes.byref(v));
#for i in xrange(6): print v.vec[i]
#lib.free_array(ctypes.byref(v))

print "EOL"
