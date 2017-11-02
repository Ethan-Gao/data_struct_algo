#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

static DQ dq = {NULL, NULL};// 定义双端队列

void creat(void){
	PDEQUE new = NULL;
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1停止创建
		else {
			new = (PDEQUE)malloc(sizeof(DEQUE));
			new->value = value;
			if(dq.head == NULL){// 空
				new->pre = NULL;new->next = NULL;
				dq.head = dq.tail = new;
			} else {// 非空
				dq.tail->next = new;
				new->pre = dq.tail;new->next = NULL;
				dq.tail = new;// 更新队尾
			}
		}
	}
}

void destroy(void){
	PDEQUE x = NULL, y = NULL;
	
	for(x = dq.head; x != NULL;){
		y = x->next;
		free(x);x = NULL;
		x = y;
	}
	dq.head = NULL;
}

void print(void){
	PDEQUE x = NULL;
	
	for(x = dq.head; x != NULL; x = x->next)
		printf("%p:%p-%p-%d ", x, x->pre, x->next, x->value);
	printf("\n");
}

DEQUE_TYPE peek(int side){
	assert(!is_empty());
	return (side == FRONT)?dq.head->value:dq.tail->value;
}

void enqueue(int side, DEQUE_TYPE value){
	PDEQUE new = NULL;
	
	assert(!is_full());
	// 分配空间
	new = (PDEQUE)malloc(sizeof(DEQUE));
	new->value = value;
	// 若只有一个元素，直接入队
	if(dq.head == NULL){
		new->pre = NULL;
		new->next = NULL;
		dq.head = new;dq.tail = new;// 更新队头队尾
		return;
	}
	// 连接链表
	switch(side){
		case FRONT:// head队头,tail队尾
			dq.tail->next = new;
			new->next = NULL;new->pre = dq.tail;
			dq.tail = new;// 更新队尾
			break;
		case BACK:// head队尾,tail队头
			dq.head->pre = new;
			new->next = dq.head;new->pre = NULL;
			dq.head = new;// 更新队尾
			break;
	}
}

void dequeue(int side){
	PDEQUE p = NULL;
	
	assert(!is_empty());
	// 若只有一个元素，直接出队
	if( dq.head == dq.tail ){
		free(dq.head);
		dq.head = NULL;dq.tail = NULL;// 更新队头队尾
		return;
	}
	// 删除队头
	switch(side){
		case FRONT:// head队头,tail队尾
			p = dq.head->next;
			free(dq.head);dq.head = NULL;
			dq.head = p;dq.head->pre = NULL;// 更新队头
			break;
		case BACK:// head队尾,tail队头
			p = dq.tail->pre;
			free(dq.tail);dq.tail = NULL;
			dq.tail = p;dq.tail->next = NULL;// 更新队头
			break;
	}
}

int size(void){
	PDEQUE p = NULL;
	int sz = 0;
	
	for(p = dq.head; p != NULL; p = p->next) sz++;
	return sz;
}

int is_empty(void){
	return dq.head == NULL;
}

int is_full(void){
	return 0;// 永然不满
}

void test(void){
	int choice = 0, value = 0, side = 0;// side只能取FRONT和BACK两个数值
	
	while(1){
		printf("0-exit 1-creat 2-destroy 3-peek 4-enqueue 5-dequeue 6-size 7-print 8-empty 9-full\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:printf("DESTROY\n");destroy();break;
			case 3:
				printf("PEEK\n");
				scanf("%d", &side);
				printf("%d\n", peek(side));
				break;
			case 4:
				printf("ENQUEUE\n");
				scanf("%d %d", &side, &value);
				enqueue(side, value);
				break;
			case 5:
				printf("DEQUEUE\n");
				scanf("%d", &side);
				dequeue(side);
				break;
			case 6:printf("SIZE\n");printf("%d\n",size());break;
			case 7:printf("PRINT\n");print();break;
			case 8:printf("EMPTY\n");printf("%d\n",is_empty());break;
			case 9:printf("FULL\n");printf("%d\n",is_full());break;
			default:printf("ERROR\n");break;
		}
	}	
}
