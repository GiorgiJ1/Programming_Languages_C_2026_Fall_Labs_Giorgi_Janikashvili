#include <stdio.h>

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