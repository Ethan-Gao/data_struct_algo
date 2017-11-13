#include <stdio.h>
#include <stdlib.h>
#include "common.h"

extern void bub_sort(int arr[], int cnt);

int main(void){
	int choice = 0, cnt = 0, start = 0, end = 0; 
	int *arr = NULL;
	
	while(1){
		printf("0-exit 1-creat 2-sort 3-time\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return 0;break;
			case 1:
				printf("CREAT\n");printf("input cnt, start, end\n");
				scanf("%d %d %d", &cnt, &start, &end);
				arr = (int *)malloc(cnt * sizeof(int));
				gen_random1(arr, cnt, start, end);
				print(arr, cnt);
				break;
			case 2:
				printf("SORT\n");
				bub_sort(arr, cnt);
				print(arr, cnt);
				break;
			case 3:
				printf("TIME\n");printf("input cnt, start, end\n");
				scanf("%d %d %d", &cnt, &start, &end);
				arr = (int *)malloc(cnt * sizeof(int));
				gen_random1(arr, cnt, start, end);
				count_time(bub_sort, arr, cnt);
				break;
			default:printf("ERROR\n");break;
		}
	}
	return 0;
}