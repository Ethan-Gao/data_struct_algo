#include <stdio.h>
#include "ins.h"

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

void sort(void){// 从小到大
	int i = 0, j = 0, cur = 0;
	
	for(i = 1; i < cnt; i++){
		cur = arr[i];
		// 将当前值与其前面所有元素比较，如果大于则元素右移
		for(j = (i-1); j >= 0; j--){
			if(arr[j] > cur) arr[j+1] = arr[j];
			else break;// 寻找到位置
		}
		arr[j+1] = cur;
//		print();// 打印此次排序结果
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
			case 2:printf("SORT\n");sort();break;
			case 3:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
