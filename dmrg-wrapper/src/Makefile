# System-specific parameters
# --------------- ----------
  # Automatic platform identification.
  PLATFORM = $(shell uname)

  # C and C++ compilers, respectively.
  GCC = gcc
  CXX = g++

  # Extra compiler flags to use.
  GCCEXTRA = -pthread -D WITH_LAPACK -D WITH_COMPLEX -funroll-loops -O3 -fstrict-aliasing
  GXXEXTRA = -pthread -ftemplate-depth-150 -D WITH_LAPACK -D WITH_COMPLEX -funroll-loops -O3 -fstrict-aliasing

  # Library directors and libraries to use.
  LIBDIRS = ./ /usr/lib/
  LIBS = blas lapack m c

  # Source directors to use.
  INCDIRS = ./ /usr/include/ ../

  # Output name for the shared object.
  SONAME = lib1.so

  # Clean-up command.
  RM = rm -Rf


# Targets
# -------
  # C targets:
  CHEADERS =
  CSOURCES = cprint.c cprint2.c
  COBJECTS = $(patsubst %.c,%.o,$(CSOURCES)) $(patsubst %.h,%.o,$(CHEADERS))

  # C++ targets:
  CPPHEADERS = 
  CPPSOURCES = test_class.cpp dmtk-wrapper.cpp
  CPPOBJECTS = $(patsubst %.cpp,%.o,$(CPPSOURCES)) $(patsubst %.hpp,%.o,$(CPPHEADERS))

  OBJECTS = $(COBJECTS) $(CPPOBJECTS)


# Compiler / linker / loader flags
# -------- - ------ - ------ -----
LDFLAGS = $(patsubst %,-L%,$(LIBDIRS)) $(patsubst %,-l%,$(LIBS))
INCLUDE = $(patsubst %,-I%,$(INCDIRS))

GCCFLAGS = $(INCLUDE) -fPIC -Wall
CXXFLAGS = $(INCLUDE) -fPIC -Wall

ifeq ($(PLATFORM),Linux)
SYSFLAGS = -shared
endif

ifeq ($(PLATFORM),Darwin)
SYSFLAGS = -dynamiclib -Wl,-undefined,dynamic_lookup
endif

# Commands
all: $(SONAME)

$(SONAME): $(OBJECTS)
	$(CXX) $(SYSFLAGS) $(LDFLAGS) -o $(LIBNAME) $(OBJECTS)

%.o: %.c
	$(GCC) $(GCCFLAGS) $(GCCEXTRA) -g -c $< -o $@

%.o: %.h
	$(GCC) $(GCCFLAGS) $(GCCEXTRA) -g -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -g -c $< -o $@

%.o: %.hpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -g -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(LIBNAME)


