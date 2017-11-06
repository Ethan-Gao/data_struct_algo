#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define STACK_SIZE	100

static STACK_TYPE *stack;
static int top_element = -1;// 指向栈顶

void creat_stack(void){
	printf("creat_stack...\n");
	stack = (STACK_TYPE *)malloc(STACK_SIZE * sizeof(STACK_TYPE));
	assert(stack != NULL);
}

void destroy_stack(void){
	printf("destroy_stack...\n");
	free(stack);
	stack = NULL;
}

void push(STACK_TYPE value){
	assert(!is_full());// 判断栈满
	top_element++;
	stack[top_element] = value;
}

STACK_TYPE pop(void){
	assert(!is_empty());// 判断栈空
	return stack[top_element--];
}

void print(void){
	int i = 0;
	
	for(i = -1; i < top_element; i++) 
		printf("%d-%d ", i+1, stack[i+1]);
	printf("\n");
}

int is_empty(void){
	return top_element == -1;
}

int is_full(void){
	return top_element == (STACK_SIZE-1);
}
