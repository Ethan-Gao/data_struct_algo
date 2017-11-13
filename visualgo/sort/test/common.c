#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/timeb.h>
#include "common.h"

void gen_random1(int arr[], int cnt, int start, int end){
	int i = 0;
	
	for(i = 0; i < cnt; i++){
		arr[i] = start + rand() % (end - start + 1);
//		printf("%d ", arr[i]);
	} 
	printf("\n");
}

void gen_random2(int arr[], int cnt){
	int i = 0;
	
    srandom(time(NULL));// time量级为s，必须等待至少过1s，否则time(NULL)还是相同
    for(i = 0; i < cnt; i++){
		arr[i] = random();
//		printf("%d ", arr[i]);
	}
	printf("\n");	
}

void count_time(CB f, int arr[], int cnt){
	struct timeb startTime , endTime;
	
	ftime(&startTime);  
	f(arr, cnt);  
	ftime(&endTime); 
	printf("TIME: %ld ms\n",(endTime.time-startTime.time)*1000 + \
	(endTime.millitm - startTime.millitm));	
}

void print(int arr[], int cnt){
	int i = 0;
	
	for(i = 0; i < cnt; i++) printf("%d ", arr[i]);
	printf("\n");
}
