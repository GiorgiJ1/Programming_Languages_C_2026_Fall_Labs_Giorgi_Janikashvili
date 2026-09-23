#include <stdio.h>

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