#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE	int

void push(STACK_TYPE value);// 入栈:数值压入堆栈
void pop(void);// 出栈:弹出一个值，然后丢弃
STACK_TYPE top(void);// 顶部:返回栈顶元素，但不修改堆栈
STACK_TYPE pop_top(void);// 出栈:弹出顶部元素，然后使用
void print(void);// 打印整个栈
int is_empty(void);// 堆栈空返回TRUE，否则返回FALSE
int is_full(void);// 堆栈满返回TRUE，否则返回FALSE

#endif /* _STACK_H_ */
