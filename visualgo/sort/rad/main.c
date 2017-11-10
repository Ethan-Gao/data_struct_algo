#include<stdio.h>
#define MAX 20
//#define SHOWPASS
#define BASE 10

void print_arr(int *arr, int n) {
	int i;
	printf("%d", arr[0]);
	for (i = 1; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

/*
** 参考:
** https://zh.wikipedia.org/wiki/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F
** https://visualgo.net/en/sorting COU_SORT
*/
void radixsort(int *a, int n) {
  int i, b[MAX], m = a[0], exp = 1;

  for (i = 1; i < n; i++) {
    if (a[i] > m) {
      m = a[i];
    }
  }

  while (m / exp > 0) {
    int bucket[BASE] = { 0 };

    for (i = 0; i < n; i++) {
      bucket[(a[i] / exp) % BASE]++;
    }

    for (i = 1; i < BASE; i++) {
      bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
      b[--bucket[(a[i] / exp) % BASE]] = a[i];
    }

    for (i = 0; i < n; i++) {
      a[i] = b[i];
    }

    exp *= BASE;

#ifdef SHOWPASS
    printf("\nPASS   : ");
    print(a, n);
#endif
  }
}

int main() {
	int arr[MAX];
	int i, n;
	
	printf("Enter total elements (n <= %d) : ", MAX);
	scanf("%d", &n);
	n = n < MAX ? n : MAX;
	
	srand(time(0));
	for (i = 0; i < n; i++)
	arr[i] = rand() % 100;
	printf("ini_array: ");
	print_arr(arr, n);

	radixsort(&arr[0], n);
	printf("sorted_array: ");
	print_arr(&arr[0], n);
	printf("\n");

	return 0;
}
