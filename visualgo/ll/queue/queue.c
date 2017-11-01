#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

static Q q = {NULL, NULL};// 定义一个队列

void creat(void){
	PQUEUE new = NULL;
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1结束创建
		else {
			new = (PQUEUE)malloc(sizeof(QUEUE));
			new->value = value;
			new->next = NULL;
			if(q.head == NULL){// 空队列
				q.head = new;
				q.tail = new;
			} else {// 非空队列
				q.tail->next = new;
				q.tail = new;// 更新队尾
			}
		}
	}
}

void destroy(void){
	PQUEUE x = NULL, y = NULL;
	
	for(x = q.head; x != NULL;){
		y = x->next;
		free(x);x = NULL;
		x = y;
	}
	q.head = NULL;
	q.tail = NULL;
}

void print(void){
	PQUEUE x = NULL;
	
	for(x = q.head; x != NULL; x = x->next)
		printf("%p:%p-%d ", x, x->next, x->value);
	printf("\n");
}

QUEUE_TYPE peek(void){
	assert(!is_empty());
	return q.head->value;
}

void enqueue(QUEUE_TYPE value){
	PQUEUE new = NULL;
	
	assert(!is_full());
	new = (PQUEUE)malloc(sizeof(QUEUE));
	new->value = value;
	q.tail->next = new;new->next = NULL;
	q.tail = new;// 更新队尾
}

void dequeue(void){
	PQUEUE x = NULL;
	
	assert(!is_empty());
	x = q.head->next;// 保存头节点下一节点
	free(q.head);q.head = NULL;
	q.head = x;// 更新队头
}

int size(void){
	PQUEUE x = NULL;
	int sz = 0;
	
	for(x = q.head; x != NULL; x = x->next) sz++;
	return sz;
}

int is_empty(void){
	return q.head == NULL;
}

int is_full(void){// 永然不满
	return 0;
}

void test(void){
	int choice = 0, value = 0;
	
	while(1){
		printf("0-exit 1-creat 2-destroy 3-peek 4-enqueue 5-dequeue 6-size 7-print 8-empty 9-full\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:printf("DESTROY\n");destroy();break;
			case 3:printf("PEEK\n");printf("%d\n", peek());break;
			case 4:printf("ENQUEUE\n");scanf("%d", &value);enqueue(value);break;
			case 5:printf("DEQUEUE\n");dequeue();break;
			case 6:printf("SIZE\n");printf("%d\n",size());break;
			case 7:printf("PRINT\n");print();break;
			case 8:printf("EMPTY\n");printf("%d\n",is_empty());break;
			case 9:printf("FULL\n");printf("%d\n",is_full());break;
			default:printf("ERROR\n");break;
		}
	}	
}
