#include <stdio.h>
#include <string.h>

#include "jwm.h"

void run() {}
void version() { printf("jwm version is %s\n", VERSION); }

int main(int argc, char *argv[]) {

  if (argc == 2 && !strcmp("-v", argv[1])) {
    version();
  }
  return 0;
}
