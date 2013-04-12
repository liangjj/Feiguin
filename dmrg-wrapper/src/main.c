#include <Python.h>
#include "../dmtk/vector.h"
#include "cprint.h"

int main() {
  dmtk::Vector<int> vec (1);
  char * s = "5";
  cprint(s);
}

static PyObject * Vector(PyObject* self,PyObject* args) {
  char * string;
  if(!PyArg_ParseTuple(args,"s",&string)) return NULL;
  printf("%s\n",string);
}
