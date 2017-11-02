#include <stdio.h>
#include "bub.h"

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

void sort(void){
	int i = 0, j = 0, tmp = 0;
	
	for(i = 0; i < (cnt-1); i++)
		for(j = 0; j < (cnt-1-i); j++){
			if(arr[j] > arr[j+1]){// 从小到大
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
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
			case 2:printf("SORT\n");sort();break;
			case 3:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
