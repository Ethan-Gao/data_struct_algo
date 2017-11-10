#include <stdio.h>
#include <stdlib.h>
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
** 方式并不唯一，但是算法都类似，
** 普通快排选择第一个或者最后一个元素，随机快排随机选择元素
** 参考:
** http://blog.csdn.net/always2015/article/details/46523531
** https://visualgo.net/en/sorting  R-Q
*/
//两数交换
void exchange(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// p表示将数组A排序的起始下标，r是结束下标
int random_patition(int *A,int p,int r){
	int temp;
	int i = p - 1;
	int j = 0;
	int k = p + rand() % (r - p +1);// 产生随机数组下标
	
	exchange(&A[r], &A[k]);// 仍然将随机的枢轴交换到最后
	temp = A[r];// 设置temp为数组结束值

	for(j = p;j <= r-1; j++){
		if(A[j] <= temp){
			i=i+1;
			exchange(&A[i], &A[j]);
		}
	}
	//最后主元交换
	exchange(&A[i+1], &A[r]);
	return i+1;
}

//递归调用
void QuickSort(int *A,int p,int q){
	if(p < q){// 结束条件p >= q
		int r = random_patition(A, p, q);
		QuickSort(A, p, r-1);
		QuickSort(A, r+1, q);
	}
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
			case 2:printf("SORT\n");QuickSort(arr, 0, cnt-1);break;
			case 3:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
