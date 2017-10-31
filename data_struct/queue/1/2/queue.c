#include <stdio.h>
#include <assert.h>
#include "queue.h"

static Queue q = {{0}, 0, 0, 0};// 定义一个队列

void insert(QUEUE_TYPE value){
	assert(!is_full());// 判断是否满
	q.rear = (q.rear+1)%ARRAY_SIZE;
	q.queue[q.rear] = value;
	q.len++;
	printf("q.rear=%d\n",q.rear);
}

QUEUE_TYPE delete(void){
	QUEUE_TYPE tmp = 0;
	
	assert(!is_empty());// 判断是否空
	tmp = q.queue[q.front];
	q.front = (q.front+1)%ARRAY_SIZE;
	q.len--;
	return tmp;
}

/*
从q.front开始打印q.len长度数据
*/
void print(void){
	int i = 0;
	
	printf("front=%d rear=%d\n",q.front,q.rear);
	assert(!is_empty());// 判断是否空
	// 打印内容
	for(i = q.front; i <= (q.front+q.len-1); i++)
		printf("index=%d,value=%d ",i%ARRAY_SIZE,q.queue[i%ARRAY_SIZE]);
	printf("\n");
}

int is_empty(void){
	return q.len == 0;
}

int is_full(void){
	return q.len == ARRAY_SIZE;
}
