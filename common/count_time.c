#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/timeb.h>

#define TEST 4

#if TEST == 1
	#define TIME_TEST_CODE	usleep(98765)// 98765us	
#elif TEST == 2
	#define TIME_TEST_CODE	usleep(1234567)// 1234567us
#elif TEST == 3
	#define TIME_TEST_CODE	{\
		int x = 5000, y = 5000;\
		for(; x > 0; x--)\
			for(; y > 0; y--);\
	}
#elif TEST == 4
	#define TIME_TEST_CODE	{\
		long int x = 90000000, y = 90000000;\
		for(; x > 0; x--)\
			for(; y > 0; y--);\
	}
#else
	#error "TEST is error"
#endif

// 使用clock, #include <time.h>
// ms级别，ms量级以下无法统计，只计算cpu有效运行时间，延时休眠均不统计
void f1(void){
	clock_t start = 0, end = 0;

	start = clock();
	TIME_TEST_CODE;
	end = clock();
	printf("F1: %ld ms\n", (long int)(end - start));
}

// 使用gettimeofday, #include <sys/time.h>
// us级别，较精确
void f2(void){
	struct timeval startTime,endTime;  
	float Timeuse;// us级别  
	int i,j;  

	gettimeofday(&startTime,NULL);  
	TIME_TEST_CODE;
	gettimeofday(&endTime,NULL);  

	Timeuse = 1000000*(endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec);
	Timeuse /= 1000;  
	printf("F2: %0.0f ms\n", Timeuse);// %0.0f不打印小数位	
}

// 使用clock_gettime, #include <time.h>
static unsigned long GetTickCount(void){  
    struct timespec ts; 
	
    clock_gettime(CLOCK_MONOTONIC, &ts);  
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);// tv_nsec-纳秒，返回ms结果
}

void f3(void){
    unsigned long start, end;
	
    start = GetTickCount();
    TIME_TEST_CODE; 
    end = GetTickCount();  
    printf("F3: %ld ms\n", end - start);  	
}

// 使用time, #include <time.h>
// s级别，s以下量级无法统计
void f4(void){
	time_t start, end;
	
	start = time(NULL);
	TIME_TEST_CODE;
	end = time(NULL);  
	printf("F4: %ld ms\n", 1000 * (long int)(end - start));	
} 

// 使用ftime, #include <sys/timeb.h>
void f5(void){
	struct timeb startTime , endTime;
	
	ftime(&startTime);  
	TIME_TEST_CODE;  
	ftime(&endTime); 
	printf("F5: %ld ms\n", (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm));	
}

int main(void){
	f1();
	f2();
	f3();
	f4();
	f5();
	return 0;
}

/*
说明:
参考http://blog.csdn.net/shudaxia123/article/details/50494199 
以下程序均运行在linux，但是和windows类似

结果:
1.TEST=1
$ ./a.out
F1: 38 ms
F2: 100 ms
F3: 99 ms
F4: 0 ms
F5: 99 ms
2.TEST=2
$ ./a.out
F1: 43 ms
F2: 1235 ms
F3: 1234 ms
F4: 2000 ms
F5: 1235 ms
3.TEST=3
$ ./a.out
F1: 42 ms
F2: 0 ms
F3: 0 ms
F4: 0 ms
F5: 0 ms
4.TEST=4
$ ./a.out
F1: 7831 ms
F2: 8 ms
F3: 8 ms
F4: 0 ms
F5: 8 ms

总结:
linux下F2 F3 F5较准确，但F5最简单，首选F5
*/
