#ifndef _SLL_H_
#define _SLL_H_

/* 定义单链表结构 */
typedef int SLL_TYPE;
typedef struct _SLL_ {
	SLL_TYPE value;
	struct _SLL_ *next;
} SLL, *PSLL;

/* 声明相关操作函数,所有index从0到len-1 */
void creat(void);// 创建链表
void destroy(void);// 销毁链表
int search(SLL_TYPE value);// 搜索二叉树,返回位置索引
void insert(int index, SLL_TYPE value);// 向位置索引index处插入一个数值
void remov(int index);// 从位置索引index处删除一个数值
void print(void);// 打印整个单链表

/* 测试函数 */
void test(void);

#endif /* _SLL_H_ */
