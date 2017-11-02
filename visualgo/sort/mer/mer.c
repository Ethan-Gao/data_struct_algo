#include <stdio.h>
#include "mer.h"

#define ARR_SIZE	100
static int arr[ARR_SIZE] = {0};// 定义数组
static int cnt = 0;// 定义creat元素的个数

void creat(void){
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1停止
		else {
			arr[cnt] = value;
			cnt++;
		}
	}
}

/*
** 先将数组一分为二，然后排序合并在一起
** 参考http://www.cnblogs.com/bluestorm/archive/2012/09/06/2673138.html
*/
static void merge(int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;

	/* 将arr一分为二，即left和right */
    for (i = 0; i < n1; i++) /* left holds arr[start..mid] */
        left[i] = arr[start+i];
    for (j = 0; j < n2; j++) /* right holds arr[mid+1..end] */
        right[j] = arr[mid+1+j];

	/* 将left和right合二为一，即合成arr */
    i = j = 0;
    k = start;
    while (i < n1 && j < n2){
        if (left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];	
	}
    while (i < n1) /* left[] is not exhausted */
        arr[k++] = left[i++];
    while (j < n2) /* right[] is not exhausted */
        arr[k++] = right[j++];
}

static void merge_print(char *str, int start, int mid, int end){
	int i = 0;
	
	printf("%s (%d-%d, %d-%d) ", str, start, mid, mid+1, end);
	for(i = 0; i < cnt; i++) printf("%d ", arr[i]);
	printf("\n");
}

// merge_sort()：先排序，再合并
void merge_sort(int start, int end){
    int mid = 0;
	
    if (start < end){
        mid = (start + end) / 2;
		merge_print("split", start, mid, end);
		
        // 分解 + 解决：Divide + Conquer
        merge_sort(start, mid); // 递归划分原数组左半边array[start...mid]
        merge_sort(mid+1, end); // 递归划分array[mid+1...end]
        // 合并：Combine
        merge(start, mid, end); // 合并
		merge_print("merge", start, mid, end);
    }
}

void print(void){
	int i = 0;
	
	for(i = 0; i < cnt; i++) printf("%d ", arr[i]);
	printf("\n");
}

void test(void){
	int choice = 0;
	
	while(1){
		printf("0-exit 1-creat 2-sort 3-print\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:printf("SORT\n");merge_sort(0, cnt-1);break;
			case 3:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
