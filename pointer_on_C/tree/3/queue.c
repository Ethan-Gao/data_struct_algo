#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

static Queue *head = NULL, *tail = NULL;// 定义一个队列

void insert(QUEUE_TYPE value){
	Queue *new = NULL;
	
	assert(!is_full());// 判断是否满
	new = (Queue *)malloc(sizeof(Queue));// 分配内存
	if(head == NULL){// 没有结点
		head = new;head->next = NULL;
		head->value = value;
	} else {// 有节点
		tail->next = new;new->next = NULL;
		new->value = value;
	}
	tail = new;// 更新队尾
}

QUEUE_TYPE delete(void){
	QUEUE_TYPE value = (QUEUE_TYPE)0;
	Queue *next = NULL;
	
	assert(!is_empty());// 判断是否空
	value = head->value;// 备份队头
	next = head->next;
	free(head);head = NULL;// 释放队头
	head = next;// 更新队头
	return value;
}

void print(void){
	Queue *p = NULL;
	
	for(p = head; p != NULL; p = p->next)
		printf("%p:%p-%p ",p,p->next,p->value);
	printf("\n");
}

int is_empty(void){
	return head == NULL;
}

int is_full(void){
	return 0;
}

int len(void){
	Queue *p = NULL;
	int cnt = 0;
	
	for(p = head; p != NULL; p = p->next) cnt++;
	return cnt;
}
