#ifndef _QUEUE_H_
#define _QUEUE_H_

/* 定义队列结构 */
typedef int QUEUE_TYPE;
typedef struct _QUEUE_ {
	QUEUE_TYPE value;
	struct _QUEUE_ *next;
} QUEUE, *PQUEUE;
typedef struct _Q_ {// 定义头尾便于操作,队头取出,队尾加入
	PQUEUE head;
	PQUEUE tail;
} Q;

/* 声明相关操作函数 */
void creat(void);// 创建队列
void destroy(void);// 销毁队列
void print(void);// 打印队列
QUEUE_TYPE peek(void);// 返回队头值，不出队
void enqueue(QUEUE_TYPE value);// 向队尾加入元素
void dequeue(void);// 队头元素出队
int size(void);// 队列元素个数
int is_empty(void);// 栈空TRUE否则FALSE
int is_full(void);// 栈满TRUE否则FALSE

/* 测试函数 */
void test(void);

#endif /* _QUEUE_H_ */