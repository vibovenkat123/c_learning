#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool grep_line(char line[], char dest[]) {
  if (strstr(line, dest) != NULL) {
    return true;
  }
  return false;
}

void grep(char find[], char filepath[], int line_number) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int found = 0;
  int line_num = 0;
  fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filepath);
    exit(1);
  }
  while ((read = getline(&line, &len, fp)) != -1) {
    line_num++;
    if (grep_line(line, find)) {
      if (line_number == 0) {
        printf("%d. %s", line_num, line);
      } else {
        printf("%s", line);
      }
      found++;
    }
  }
  if (line) {
    free(line);
  }
  if (found == 0) {
    exit(1);
  }
  fclose(fp);
}

int main(int argc, char **argv) {
  char line_number_flag[] = "--line-number";
  if (argc < 3) {
    printf("Two arguments are required\n");
    return 1;
  } else if (argc > 3) {
    if (argc > 4) {
      printf("Too much arguments\n");
      return 1;
    } else if (strcmp(argv[1], line_number_flag) == 1) {
      printf("Too much arguments\n");
      return 1;
    }
  }
  if (strlen(argv[2]) == 0) {
    return 1;
  }
  if (argc == 4) {
    if (strcmp(argv[1], line_number_flag) != 0) {
      printf("Incorrect flag name\n");
      return 1;
    }
    grep(argv[2], argv[3], 0);
  } else {
    grep(argv[1], argv[2], 1);
  }
  return 0;
}
