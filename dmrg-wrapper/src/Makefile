# System-specific parameters
# --------------- ----------
CXX = g++

LIBNAME = libprint.so
EXENAME = exe

# Python source directory.
PYTHON = /Users/mark/Src/Python-2.7.3/Include

# Targets
# -------
HEADERS =
SOURCES = cprint.c cprint2.c main.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES)) $(patsubst %.h,%.o,$(HEADERS))
RM = rm -f

# Compiler / linker / loader flags
# -------- - ------ - ------ -----
LDFLAGS = -L./ -L/usr/lib
INCLUDE = -I./ -I/usr/include -I$(PYTHON)

CXXFLAGS = $(INCLUDE) -fPIC -Wall

# Commands
all: shared main

main: shared $(OBJECTS)
	$(CXX) -o $(EXENAME) *.o

shared: $(OBJECTS)
	$(CXX) -shared $(LDFLAGS) -o $(LIBNAME) $(OBJECTS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

%.o: %.h
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(LIBNAME) $(EXENAME)


