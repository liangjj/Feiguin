#!/usr/bin/env python
import ctypes

libprint = ctypes.cdll.LoadLibrary('src/lib1.so')
libprint['cprint']('Hello, world!')
