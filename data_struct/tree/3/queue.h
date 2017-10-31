#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "tree.h"
#define QUEUE_TYPE	PTREE	// 层次遍历必须需要入队，必须使用此类型

typedef struct _Queue_ {
	QUEUE_TYPE value;
	struct _Queue_ *next;
} Queue;

void insert(QUEUE_TYPE value);// 向队尾添加一个新元素
QUEUE_TYPE delete(void);// 从队头取出一个元素，然后使用
void print(void);// 打印整个队列
int is_empty(void);// 队列空则TRUE，否则FALSE
int is_full(void);// 队列满则TRUE，否则FALSE
int len(void);// 队列长度

#endif /* _QUEUE_H_ */
