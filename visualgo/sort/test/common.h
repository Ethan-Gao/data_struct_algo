#ifndef _COMMON_H_
#define _COMMON_H_

/* 定义通用函数 */
//typedef void (*CB)(void);// 排序算法回掉接口
typedef void (*CB)(int arr[], int cnt);
void gen_random1(int arr[], int cnt, int start, int end);// 产生cnt个start-end之间的随机数
void gen_random2(int arr[], int cnt);// 产生cnt个0-RAND_MAX之间的随机数
void count_time(CB f, int arr[], int cnt);// 计算算法执行时间
void print(int arr[], int cnt);// 打印数组

#endif /* _COMMON_H_ */
