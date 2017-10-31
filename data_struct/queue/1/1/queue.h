#ifndef _QUEUE_H_
#define _QUEUE_H_

#define QUEUE_TYPE	int

#define QUEUE_SIZE	5 // 定义小便于测试
#define ARRAY_SIZE	(QUEUE_SIZE+1)// 保留一个元素不用，以便区分空和满
typedef struct _Queue_ {
	QUEUE_TYPE queue[ARRAY_SIZE];
	int front;// 队列头
	int rear;// 队列尾
} Queue;

void insert(QUEUE_TYPE value);// 向队尾添加一个新元素
QUEUE_TYPE delete(void);// 从队头取出一个元素，然后使用
void print(void);// 打印整个队列
int is_empty(void);// 队列空则TRUE，否则FALSE
int is_full(void);// 队列满则TRUE，否则FALSE

#endif /* _QUEUE_H_ */
