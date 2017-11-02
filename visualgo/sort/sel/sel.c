#include <stdio.h>
#include "sel.h"

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

// 每次遍历一次，找出最小移到前面
void sort(void){
	int i = 0, j = 0;
	int min_value = 0, min_index = 0, tmp = 0;
	
	for(i = 0; i < cnt; i++){
		// 设置当前位置为最小值
		min_index = i;
		min_value = arr[min_index];
		// 寻找从当前位置到数组末尾的最小值
		for(j = i; j < cnt; j++){
			if(arr[j] < min_value){
				min_index = j;// 记录位置
				min_value = arr[j];
			}
		}
		// 交换元素
		tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
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