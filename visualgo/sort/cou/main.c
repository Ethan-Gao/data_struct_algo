#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int *arr, int n) {
	int i;
	printf("%d", arr[0]);
	for (i = 1; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

/*
** 参考:
** https://zh.wikipedia.org/wiki/%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F
** https://visualgo.net/en/sorting COU_SORT
*/
void counting_sort(int *ini_arr, int *sorted_arr, int n) {
	int *count_arr = (int *) malloc(sizeof(int) * 100);
	int i, j, k;
	for (k = 0; k < 100; k++)
		count_arr[k] = 0;
	for (i = 0; i < n; i++)
		count_arr[ini_arr[i]]++;
	for (k = 1; k < 100; k++)
		count_arr[k] += count_arr[k - 1];
	for (j = n; j > 0; j--)
		sorted_arr[--count_arr[ini_arr[j - 1]]] = ini_arr[j - 1];
	free(count_arr);
}

int main(int argc, char **argv) {
	int n = 10;
	int i;
	int *arr = (int *) malloc(sizeof(int) * n);
	int *sorted_arr = (int *) malloc(sizeof(int) * n);
	srand(time(0));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("ini_array: ");
	print_arr(arr, n);
	counting_sort(arr, sorted_arr, n);
	printf("sorted_array: ");
	print_arr(sorted_arr, n);
	free(arr);
	free(sorted_arr);
	return 0;
}
