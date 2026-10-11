
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  printf("enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("invalid size.\n");
    return 1;
  }

  int* roxy = malloc(n * sizeof(int));

  if (roxy == NULL) {
    printf("memory allocation failed.\n");
    return 1;
  }

  printf("enter %d integers: ", n);

  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &roxy[i]) != 1) {
      printf("invalid input.\n");
      free(roxy);
      return 1;
    }

    sum += roxy[i];
  }

  double average = (double)sum / n;

  printf("sum = %d\n", sum);
  printf("average = %.2f\n", average);

  free(roxy);

  return 0;
}
