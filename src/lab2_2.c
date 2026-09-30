#include <stdio.h>

<<<<<<< HEAD
long long factorial(int n) {
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

int main() {
  int n;
  printf("Enter the number for n: ");
  scanf("%d", &n);
  if (n < 0) {
    printf("Error n must be possitive number");
  } else {
    printf("The factorial of your number is: %lld\n", factorial(n));
  }

  return 0;
}
=======
/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    // TODO: compute factorial iteratively
    return 1; // placeholder
}

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);

    // TODO: validate input, call function, print result

    return 0;
}
>>>>>>> 9f7a6eae168a989a03bb86124868f72ba8036208
