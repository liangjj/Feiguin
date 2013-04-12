# System-specific parameters
# --------------- ----------
PLATFORM = $(shell uname)

GCC = gcc
CXX = g++

LIBNAME = lib1.so

# Targets
# -------
  # C targets:
  CHEADERS =
  CSOURCES = cprint.c cprint2.c
  COBJECTS = $(patsubst %.c,%.o,$(CSOURCES)) $(patsubst %.h,%.o,$(CHEADERS))
  # C++ targets:
  CPPHEADERS =
  CPPSOURCES = test_class.cpp
  CPPOBJECTS = $(patsubst %.cpp,%.o,$(CPPSOURCES)) $(patsubst %.hpp,%.o,$(CPPHEADERS))

  OBJECTS = $(COBJECTS) $(CPPOBJECTS)

RM = rm -f

# Compiler / linker / loader flags
# -------- - ------ - ------ -----
LDFLAGS = -L./ -L/usr/lib
INCLUDE = -I./ -I/usr/include

CXXFLAGS = $(INCLUDE) -fPIC -Wall -arch x86_64

ifeq ($(PLATFORM),Linux)
SYSFLAGS = -shared
endif

ifeq ($(PLATFORM),Darwin)
SYSFLAGS = -dynamiclib -Wl,-undefined,dynamic_lookup
endif

# Commands
all: shared

shared: $(OBJECTS)
	$(CXX) $(SYSFLAGS) $(LDFLAGS) -o $(LIBNAME) $(OBJECTS)

%.o: %.c
	$(GCC) $(CXXFLAGS) -g -c $< -o $@

%.o: %.h
	$(GCC) $(CXXFLAGS) -g -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

%.o: %.hpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(LIBNAME)


