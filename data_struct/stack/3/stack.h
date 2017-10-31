#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE	int
typedef struct NODE
{
    STACK_TYPE data;
    struct NODE *next;
}List,*linkList;

void creat_stack(void);// 分配空间
void destroy_stack(void);// 释放空间
void push(STACK_TYPE value);// 入栈:数值压入堆栈
STACK_TYPE pop(void);// 出栈:弹出一个值，然后使用
void print(void);// 打印整个栈
int is_empty(void);// 堆栈空返回TRUE，否则返回FALSE
int is_full(void);// 堆栈满返回TRUE，否则返回FALSE

#endif /* _STACK_H_ */
