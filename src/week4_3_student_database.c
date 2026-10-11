
#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int just_a_var;

  printf("enter number of students: ");
  if (scanf("%d", &just_a_var) != 1 || just_a_var <= 0) {
    printf("invalid number.\n");
    return 1;
  }

  struct Student* roxy = malloc(just_a_var * sizeof(struct Student));

  if (roxy == NULL) {
    printf("memory allocation failed.\n");
    return 1;
  }

  for (int someguy1 = 0; someguy1 < just_a_var; someguy1++) {
    printf("enter data for student %d: ", someguy1 + 1);

    if (scanf("%49s %d %f", roxy[someguy1].name, &roxy[someguy1].id,
              &roxy[someguy1].grade) != 3) {
      printf("invalid input.\n");
      free(roxy);
      return 1;
    }
  }

  printf("\n");
  printf("%-6s %-11s %s\n", "ID", "Name", "Grade");

  for (int someguy2 = 0; someguy2 < just_a_var; someguy2++) {
    printf("%-6d %-11s %.1f\n", roxy[someguy2].id, roxy[someguy2].name,
           roxy[someguy2].grade);
  }

  free(roxy);

  return 0;
}
