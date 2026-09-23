#include <stdio.h>

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