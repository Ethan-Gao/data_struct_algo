#include <stdio.h>
#include "mer.h"

#define ARR_SIZE	100
static int a[ARR_SIZE] = {0};// 定义数组
static int cnt = 0, i = 0;// 定义creat元素的个数

void creat(void){
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1停止
		else {
			a[cnt] = value;
			cnt++;
		}
	}
}

/*
** 参考:
** https://en.wikipedia.org/wiki/Merge_sort
** https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F#C.E8.AA.9E.E8.A8.80
** 说明:
** 去掉printf前面//，即可看到分割和合并过程
*/
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
	/*
	** 作用:
	** 不停二分直到只剩下1个或者2个元素
	** 分析:
	** 由于start表示开始，end表示结束，所以只有剩下1个或者2个元素才会满足
	** start >= end这个条件，从而结束递归，然后执行后面内容
	*/
	if (start >= end) return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
//	printf("%d:(%d-%d) (%d-%d)\n", i++, start1, end1, start2, end2);
	merge_sort_recursive(arr, reg, start1, end1);
//	printf("%d:(%d-%d) (%d-%d)\n", i++, start1, end1, start2, end2);
	merge_sort_recursive(arr, reg, start2, end2);
	
	/* 将二分完后的数组进行排序，然后在合并放入reg数组 */
//	printf("%d:(%d-%d) (%d-%d)\n", i++, start1, end1, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)// 排序二分后的数组放入reg数组
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 <= end1)// 将前半部分剩余放入
		reg[k++] = arr[start1++];
	while (start2 <= end2)// 将后半部分剩余放入
		reg[k++] = arr[start2++];

	/* 将reg数组排序结果复制到arr数组 */
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}

void merge_sort(int arr[], const int len) {
	int reg[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
}

void print(void){
	int i = 0;
	
	for(i = 0; i < cnt; i++) printf("%d ", a[i]);
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
			case 2:printf("SORT\n");merge_sort(a, cnt);break;
			case 3:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
