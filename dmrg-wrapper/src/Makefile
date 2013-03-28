# System parameters
# ------ ----------
CXX = gcc

#ARCH = i386
ARCH = x86_64

LIBNAME = libprint.so

# Targets
# -------
SOURCES = cprint.c cprint2.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
RM = rm -f

# Compiler / linker / loader flags
# -------- - ------ - ------ -----
LDFLAGS = -L./ -L/usr/lib
INCLUDE = -I./ -I/usr/include

CXXFLAGS = $(INCLUDE) -arch $(ARCH) -fPIC -Wall

# Commands
all: shared

shared: $(OBJECTS)
	$(CXX) -shared $(LDFLAGS) -o $(LIBNAME) $(OBJECTS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -g -c $<

clean:
	$(RM) $(OBJECTS) $(LIBNAME)


