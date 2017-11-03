#include <stdio.h>
#include "qui.h"

#define ARR_SIZE	100
static int arr[ARR_SIZE] = {0};// 定义数组，用于存放数据
static int cnt = 0;// creat创建的元素个数

void creat(void){
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) break;// -1停止
		else {
			arr[cnt] = value;
			cnt++;
		}
	}
}

/*
** 方式并不唯一，但是算法都类似
** 参考:
** http://blog.csdn.net/guoyong10721073/article/details/8025201
** https://visualgo.net/en/sorting  QUICK_SORT
*/

void quick_sort_bk(int s[], int l, int r){
	int i, j, x;  
	if (l < r){
		i = l;  
		j = r;  
		x = s[i];  
		while (i < j){
			while(i < j && s[j] > x)   
			j--; /* 从右向左找第一个小于x的数 */  
			if(i < j)   
			s[i++] = s[j];  

			while(i < j && s[i] < x)   
			i++; /* 从左向右找第一个大于x的数 */  
			if(i < j)   
			s[j--] = s[i];
		}  
		s[i] = x;
		quick_sort(s, l, i-1); /* 递归调用 */  
		quick_sort(s, i+1, r);  
	}  
}

void quick_sort(int s[], int start, int end){
	int start1, end1, x;
	
	if(start >= end) return;// 1个元素不用排序
	
	start1 = start;  
	end1 = end;  
	x = s[start1];
	while (start1 < end1){
		while(start1 < end1 && s[end1] > x) end1--; /* 从右向左找第一个小于x的数 */  
		if(start1 < end1) s[start1++] = s[end1];  

		while(start1 < end1 && s[start1] < x) start1++; /* 从左向右找第一个大于x的数 */  
		if(start1 < end1) s[end1--] = s[start1];
	}  
	s[start1] = x;
	quick_sort(s, start, start1-1); /* 递归调用 */  
	quick_sort(s, start1+1, end);
}

void print(void){
	int i = 0;
	
	for(i = 0; i< cnt; i++) printf("%d ", arr[i]);
	printf("\n");
}

/* 测试函数 */
void test(void){
	int choice = 0;
	
	while(1){
		printf("0-exit 1-creat 2-sort 3-print\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:printf("SORT\n");quick_sort(arr, 0, cnt-1);break;
			case 3:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
