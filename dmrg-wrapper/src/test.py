#!/usr/bin/env python

import ctypes
import numpy

lib = ctypes.cdll.LoadLibrary('dmtk.so')
#lib.get_array.restype = numpy.ctypeslib.ndpointer(dtype=numpy.float64,ndim=1,shape=(5,))
a = lib.get_array(5)
#for i in a: print i
lib.free_array(a)
