// Giorgi Janikashvili Student ID: 251ADB123
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
  char name[50];
  int id;
  float gpa;
} Student;

char* read_line(char* buffer, int size) {
  if (fgets(buffer, size, stdin) == NULL) return NULL;

  buffer[strcspn(buffer, "\n")] = '\0';
  return buffer;
}

int load_students(Student arr[], int max) {
  FILE* file = fopen("students.txt", "r");
  char line[256];
  int count = 0;

  if (file == NULL) return 0;

  while (fgets(line, sizeof(line), file) != NULL && count < max) {
    char name[50];
    int id;
    float gpa;
    char extra;

    if (line[strspn(line, " \t\r\n")] == '\0') continue;

    if (sscanf(line, "%49[^,],%d,%f %c", name, &id, &gpa, &extra) != 3)
      continue;

    if (strlen(name) == 0 || id <= 0 || gpa < 0 || gpa > 4) continue;

    strcpy(arr[count].name, name);
    arr[count].id = id;
    arr[count].gpa = gpa;
    count++;
  }

  fclose(file);
  return count;
}

int save_students(const Student arr[], int count) {
  FILE* file = fopen("students.txt", "w");

  if (file == NULL) return -1;

  for (int i = 0; i < count; i++) {
    fprintf(file, "%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
  }

  if (fclose(file) != 0) return -1;

  return 0;
}

void add_student(Student arr[], int* count) {
  char name[50];
  char id_text[50];
  char gpa_text[50];
  char* end;
  long id;
  float gpa;

  if (*count >= MAX_STUDENTS) {
    printf("cannot add more students (limit reached).\n");
    return;
  }

  printf("enter name: ");
  if (read_line(name, sizeof(name)) == NULL) return;

  printf("enter id: ");
  if (read_line(id_text, sizeof(id_text)) == NULL) return;

  printf("enter gpa: ");
  if (read_line(gpa_text, sizeof(gpa_text)) == NULL) return;

  if (name[0] == '\0' || strchr(name, ',') != NULL) {
    printf("invalid input. student not added.\n");
    return;
  }

  for (int i = 0; name[i] != '\0'; i++) {
    if ((unsigned char)name[i] < 32) {
      printf("invalid input. student not added.\n");
      return;
    }
  }

  id = strtol(id_text, &end, 10);

  while (isspace((unsigned char)*end)) end++;

  if (end == id_text || *end != '\0' || id <= 0 || id > 2147483647L) {
    printf("invalid input. student not added.\n");
    return;
  }

  gpa = strtof(gpa_text, &end);

  while (isspace((unsigned char)*end)) end++;

  if (end == gpa_text || *end != '\0' || gpa < 0 || gpa > 4) {
    printf("invalid input. student not added.\n");
    return;
  }

  strcpy(arr[*count].name, name);
  arr[*count].id = (int)id;
  arr[*count].gpa = gpa;
  *count = *count + 1;

  printf("student added successfully!\n");
}

void list_students(const Student arr[], int count) {
  if (count == 0) {
    printf("no students found.\n");
    return;
  }

  printf("%-5s %-20s %s\n", "id", "name", "gpa");

  int roxy = 0;
  while (roxy < count) {
    printf("%-5d %-20s %.2f\n", arr[roxy].id, arr[roxy].name, arr[roxy].gpa);
    roxy++;
  }
}

int main(void) {
  Student someguy[MAX_STUDENTS];
  int just_a_var = load_students(someguy, MAX_STUDENTS);
  char choice[50];

  printf("loaded %d student(s) from students.txt\n", just_a_var);

  while (1) {
    printf("\n=== student management system ===\n");
    printf("1. list students\n");
    printf("2. add student\n");
    printf("3. save and exit\n");
    printf("select an option: ");

    if (read_line(choice, sizeof(choice)) == NULL) {
      if (save_students(someguy, just_a_var) == 0) {
        printf("data saved. goodbye!\n");
        return 0;
      }
      printf("error saving data.\n");
      return 1;
    }

    if (strcmp(choice, "1") == 0) {
      list_students(someguy, just_a_var);
    } else if (strcmp(choice, "2") == 0) {
      add_student(someguy, &just_a_var);
    } else if (strcmp(choice, "3") == 0) {
      if (save_students(someguy, just_a_var) == 0) {
        printf("data saved. goodbye!\n");
        break;
      } else {
        printf("error saving data.\n");
        return 1;
      }
    } else {
      printf("invalid option.\n");
    }
  }

  return 0;
}
