#ifndef _DEQUE_H_
#define _DEQUE_H_

/* 定义双端队列结构 */
typedef int DEQUE_TYPE;
typedef struct _DEQUE_ {
	DEQUE_TYPE value;
	struct _DEQUE_ *pre;
	struct _DEQUE_ *next;
} DEQUE, *PDEQUE;
typedef struct _DQ_ {// 双端队列具有头尾两个方向
	PDEQUE head;
	PDEQUE tail;
} DQ;

/* 声明相关操作函数 */
enum _SIDE_ {
	/* 注意：不管队列方向，元素永然都是队头出队尾入 */
	FRONT = 1, // head队头,tail队尾
	BACK = 2,// head队尾,tail队头
};
void creat(void);// 创建队列
void destroy(void);// 销毁队列
void print(void);// 打印队列
DEQUE_TYPE peek(int side);// 返回队头值，不出队
void enqueue(int side, DEQUE_TYPE value);// 向队尾加入元素
void dequeue(int side);// 队头元素出队
int size(void);// 队列元素个数
int is_empty(void);// 栈空TRUE否则FALSE
int is_full(void);// 栈满TRUE否则FALSE

/* 声明测试函数 */
void test(void);

#endif /* _DEQUE_H_ */
