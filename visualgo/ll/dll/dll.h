#ifndef _DLL_H_
#define _DLL_H_

/* 定义双链表结构 */
typedef int DLL_TYPE;
typedef struct _DLL_ {
	DLL_TYPE value;
	struct _DLL_ *pre;
	struct _DLL_ *next;
} DLL, *PDLL;

/* 声明操作函数 */
void creat(void);// 创建链表
void destroy(void);// 销毁链表
void print(void);// 打印链表
int search(DLL_TYPE value);// 搜索值，返回位置索引
void insert(int index, DLL_TYPE value);// 向位置索引index处插入value
void delete(int index);// 删除位置索引index处元素
int size(void);// 链表元素个数
int is_empty(void);// 栈空TRUE否则FALSE
int is_full(void);// 栈满TRUE否则FALSE

/* 声明测试函数 */
void test(void);

#endif /* _DLL_H_ */
