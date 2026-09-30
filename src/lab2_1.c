#include <stdio.h>

<<<<<<< HEAD
int sum_to_n(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
  int n;
  printf("Enter the number representic n: ");
  scanf("%d", &n);
  if (n < 1) {
    printf("ERROR, the number you entered should be more or equal to 1");
  } else {
    printf("The sum to n is: %d\n", sum_to_n(n));
  }

  return 0;
}
=======
/*
    Task:
    Write a function `int sum_to_n(int n)` that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int sum_to_n(int n) {
    // TODO: implement sum with a for loop
    return 0; // placeholder
}

int main(void) {
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // TODO: validate input, call function, and print result

    return 0;
}
>>>>>>> 9f7a6eae168a989a03bb86124868f72ba8036208
