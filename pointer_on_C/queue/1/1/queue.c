#include <stdio.h>
#include <assert.h>
#include "queue.h"

static Queue q = {{0}, 1, 0};// 定义一个队列

void insert(QUEUE_TYPE value){
	assert(!is_full());// 判断是否满
	q.rear = (q.rear+1)%ARRAY_SIZE;
	q.queue[q.rear] = value;
}

QUEUE_TYPE delete(void){
	QUEUE_TYPE tmp = 0;
	
	assert(!is_empty());// 判断是否空
	tmp = q.queue[q.front];
	q.front = (q.front+1)%ARRAY_SIZE;
	return tmp;
}

/*
通常front<rear，front删除一次增大一下，rear插入一次增大一下，逐次操作会
越过头部和尾部连接点，从而导致rear>ARRAY_SIZE为rear%ARRAY_SIZE，此时rear
就有可能小于front
*/
void print(void){
	QUEUE_TYPE front = 0, rear = 0;
	int i = 0;
	
	printf("front=%d rear=%d\n",q.front,q.rear);
	assert(!is_empty());// 判断是否空
	// 获取头尾
	if(q.rear < q.front){// 循环队列已经跨过头尾交界点
		rear = q.rear + ARRAY_SIZE;
	} else {// 循环队列未跨过头尾交界点
		rear = q.rear;
	}
	front = q.front;
	// 打印内容
	for(i = front; i <= rear; i++)
		printf("index=%d,value=%d ",i%ARRAY_SIZE,q.queue[i%ARRAY_SIZE]);
	printf("\n");
}

int is_empty(void){
	return (q.rear+1)%ARRAY_SIZE == q.front;
}

int is_full(void){
	return (q.rear+2)%ARRAY_SIZE == q.front;
}
