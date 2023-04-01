#include <stdio.h>
#include <string.h>
void echo(char msg[]) { printf("%s", msg); }

int main(int argc, char *argv[]) {
  if (argc == 2) {
    echo(argv[1]);
    if (strcmp(argv[1], "-n") != 0) {
      fputs("\n", stdout);
    }
  } else if (argc > 2) {
    int i = 1;
    if (strcmp(argv[1], "-n") == 0) {
      i = 2;
    }
    for (; i < argc; ++i) {
      echo(argv[i]);
      if (i != argc - 1) {
        fputs("\n", stdout);
      } else if (strcmp(argv[1], "-n") != 0) {
        fputs("\n", stdout);
      }
    }
  } else {
    fputs("\n", stdout);
  }
  return 0;
}
