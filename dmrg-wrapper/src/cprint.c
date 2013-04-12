#include <stdio.h>
#include <cprint2.h>

int cprint(char * string) {
  printf("%s\n",string);
  cprint2(string);
  return 1;
};
