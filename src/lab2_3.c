#include <stdio.h>

<<<<<<< HEAD
int is_prime(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  printf("Enter the number n: ");
  scanf("%d", &n);
  if (n < 2) {
    printf("Error n must be more or equal to 2");
  } else {
    printf("The number you entered is: %d\n", is_prime(n));
  }
}
=======
/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n) {
    // TODO: check if n is prime using loop up to sqrt(n)
    return 0; // placeholder
}

int main(void) {
    int n;

    printf("Enter an integer n (>= 2): ");
    scanf("%d", &n);

    // TODO: validate input and print all primes up to n

    return 0;
}
>>>>>>> 9f7a6eae168a989a03bb86124868f72ba8036208
