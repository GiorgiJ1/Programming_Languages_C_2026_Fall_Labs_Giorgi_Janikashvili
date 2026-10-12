// Giorgi Janikashvili, Student ID: 251ADB123

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

int save_student(const Student* s, const char* filename) {
  if (s == NULL || filename == NULL) {
    return -1;
  }

  FILE* roxy = fopen(filename, "w");
  if (roxy == NULL) {
    perror("Error opening file for writing");
    return -1;
  }

  if (fprintf(roxy, "%s %d %.2f\n", s->name, s->age, s->gpa) < 0) {
    fclose(roxy);
    return -1;
  }

  fclose(roxy);
  return 0;
}

int load_student(const char* filename, Student* out) {
  if (filename == NULL || out == NULL) {
    return -1;
  }

  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return -1;
  }

  int just_variable = fscanf(fp, "%49s %d %f", out->name, &out->age, &out->gpa);
  fclose(fp);

  if (just_variable != 3) {
    return -1;
  }

  return 0;
}

int main(void) {
  Student original_student = {"Alice", 21, 3.75f};
  Student loaded_student;
  const char* filename = "student.txt";

  printf("Saving student to file...\n");
  if (save_student(&original_student, filename) != 0) {
    fprintf(stderr, "Failed to save student record.\n");
    return EXIT_FAILURE;
  }

  printf("Loading student from file...\n");
  if (load_student(filename, &loaded_student) != 0) {
    fprintf(stderr, "Failed to load student record.\n");
    return EXIT_FAILURE;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded_student.name,
         loaded_student.age, loaded_student.gpa);

  return EXIT_SUCCESS;
}