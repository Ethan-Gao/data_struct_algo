#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// 产生cnt个start-end之间的随机数
void f1(int cnt, int start, int end){
	long int i, value;
	
	for(i = 0; i < cnt; i++){
		value = start + rand() % (end - start + 1);
		printf("%ld ", value);
	} 
	printf("\n");
}

// 测试随机数,种子固定,得出的随机数是固定的  
void f2(void){
	int i;
	
    srandom(1);
    for(i = 0; i < 10; i++) printf("%d:%ld ", i, random());
	printf("\n");
}

// 测试随机数,种子是随机的，得出的随机数是不固定的 
void f3(void){
	int i;
	
    srandom(time(NULL));// time量级为s，必须等待至少过1s，否则time(NULL)还是相同
    for(i = 0; i < 10; i++) printf("%d:%ld ", i, random());
	printf("\n");
}

int main(void){
	printf("RAND_MAX=0x%x\n", RAND_MAX);
	f1(10, 1, 100);// 产生1000个从1-100的数字
	f2();sleep(1);f2();// 多次执行f2结果都相同
	f3();sleep(1);f3();// 多次执行f2结果不相同
	return 0;
}
