#!/usr/bin/env bash

gcc -arch x86_64 -fPIC -g -c -Wall print.c
#For linux...
gcc -arch x86_64 -shared -o libprint.so print.o
#For OSX...
#gcc -arch x86_64 -dynamiclib -o libprint.dylib print.o

