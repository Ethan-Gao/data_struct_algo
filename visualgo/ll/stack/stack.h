#ifndef _STACK_H_
#define _STACK_H_

/* 定义栈结构 */
typedef int STACK_TYPE;
typedef struct _STACK_ {
	STACK_TYPE value;
	struct _STACK_ *next;
} STACK, *PSTACK;

/* 声明相关操作函数 */
void creat(void);// 创建栈
void destroy(void);// 创建栈
STACK_TYPE peek(void);// 返回栈顶元素,不出栈
void push(STACK_TYPE value);// 将元素放入栈顶
void pop(void);// 栈顶元素出栈
int size(void);// 栈元素个数
void print(void);// 打印整个栈
int is_empty(void);// 栈空TRUE否则FALSE
int is_full(void);// 栈满TRUE否则FALSE

/* 测试函数 */
void test(void);

#endif /* _STACK_H_ */
