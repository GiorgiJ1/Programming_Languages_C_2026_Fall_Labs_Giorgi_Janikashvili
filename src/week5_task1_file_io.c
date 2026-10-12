// Giorgi Janikashvili, Student ID: 251ADB123

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  const char* filename = "data.txt";
  if (argc > 1) {
    filename = argv[1];
  }

  printf("writing lines to %s...\n", filename);
  FILE* roxy = fopen(filename, "w");
  if (roxy == NULL) {
    perror("error opening file for writing");
    return EXIT_FAILURE;
  }

  fprintf(roxy, "hello, file I/O in c!\n");
  fprintf(roxy, "this is another line\n");

  fclose(roxy);

  printf("reading contents:\n");
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("error opening file for reading");
    return EXIT_FAILURE;
  }

  char buffer[256];
  int just_variable = 0;

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
    just_variable++;
  }

  fclose(fp);

  printf("lines read: %d\n", just_variable);

  return EXIT_SUCCESS;
}