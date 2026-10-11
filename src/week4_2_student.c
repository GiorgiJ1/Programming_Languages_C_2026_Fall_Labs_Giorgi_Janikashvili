#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student someguy1;
  struct Student someguy2;

  strcpy(someguy1.name, "Allice Johnson");
  someguy1.id = 1001;
  someguy1.grade = 9.1f;

  strcpy(someguy2.name, "Bobby Smith");
  someguy2.id = 1002;
  someguy2.grade = 8.7f;

  printf("student 1: %s, ID: %d, Grade: %.1f\n", someguy1.name, someguy1.id,
         someguy1.grade);

  printf("student 2: %s, ID: %d, Grade: %.1f\n", someguy2.name, someguy2.id,
         someguy2.grade);

  return 0;
}