#!/usr/bin/env python
import ctypes

libprint = ctypes.cdll.LoadLibrary('src/libprint.so')
libprint['cprint']('Hello, world!')
