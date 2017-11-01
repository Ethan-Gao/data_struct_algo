#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define STACK_SIZE	100

static List *stack = NULL;// stack永然指向链表头

void creat_stack(void){
}

void destroy_stack(void){
	List *next = NULL, *p = NULL;
	
	for(p = stack; p != NULL;){
		next = p->next;// 保存下一节点
		free(p);p = NULL;// 释放空间
		p = next;// 还原下一节点
	}
	stack = NULL;
}

void push(STACK_TYPE value){
	List *new = NULL;
	
	assert(!is_full());// 判断栈满
	new = (List *)malloc(sizeof(List));// 分配内存
	new->data = value;// 添加新节点到表头
	new->next = stack;
	stack = new;// 更新表头
}

STACK_TYPE pop(void){
	List *next = NULL;
	STACK_TYPE value = 0;
	
	assert(!is_empty());// 判断栈空
	next = stack->next;// 备份
	value = stack->data;
	free(stack);stack = NULL;// 释放表头
	stack = next;// 更新表头
	return value;
}

void print(void){
	List *tmp = NULL;// 此处会改变stack，需要保存
	
	tmp = stack;
	for(;stack != NULL; stack = stack->next)
		printf("%p:%p-%d ",stack,stack->next,stack->data);
	printf("\n");
	stack = tmp;
}

int is_empty(void){
	printf("%p\n",stack);
	return stack == NULL;
}

int is_full(void){
	return 0;
}
