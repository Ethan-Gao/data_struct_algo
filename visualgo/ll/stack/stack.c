#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

static PSTACK stack = NULL;// 定义栈(单链表式)

void creat(void){
	PSTACK new = NULL;
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1停止创建
		else {
			new = (PSTACK)malloc(sizeof(STACK));// 分配空间
			new->value = value;
			new->next = stack;// 放到栈顶/链表头
			stack = new;// 更新表头
		}
	}
}

void destroy(void){
	PSTACK p = NULL, q = NULL;
	
	for(p = stack; p != NULL;){
		q = p->next;
		free(p);p = NULL;
		p = q;
	}
	stack = NULL;
}

STACK_TYPE peek(void){
	assert(!is_empty());
	return stack->value;
}

void push(STACK_TYPE value){
	PSTACK new = NULL;
	
	assert(!is_full());
	new = (PSTACK)malloc(sizeof(STACK));
	new->value = value;
	new->next = stack;
	stack = new;
}

void pop(void){
	PSTACK p = NULL;
	
	assert(!is_empty());
	p = stack->next;
	free(stack);stack = NULL;
	stack = p;
}

int size(void){
	PSTACK p = NULL;
	int sz = 0;
	
	for(p = stack; p != NULL; p = p->next) sz++;
	return sz;
}

void print(void){
	PSTACK p = NULL;
	
	for(p = stack; p != NULL; p = p->next)
		printf("%p:%p-%d ", p, p->next, p->value);
	printf("\n");
}

int is_empty(void){
	return stack == NULL;
}

int is_full(void){
	return 0;// 永然不满
}

void test(void){
	int choice = 0, value = 0;
	
	while(1){
		printf("0-exit 1-creat 2-destroy 3-peek 4-push 5-pop 6-size 7-print 8-empty 9-full\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:printf("CREAT\n");destroy();break;
			case 3:printf("TOP\n");printf("%d\n", peek());break;
			case 4:printf("PUSH\n");scanf("%d", &value);push(value);break;
			case 5:printf("POP\n");pop();break;
			case 6:printf("SIZE\n");printf("%d\n",size());break;
			case 7:printf("PRINT\n");print();break;
			case 8:printf("EMPTY\n");printf("%d\n",is_empty());break;
			case 9:printf("FULL\n");printf("%d\n",is_full());break;
			default:printf("ERROR\n");break;
		}
	}
}
