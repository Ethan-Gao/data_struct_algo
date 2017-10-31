#ifndef _TREE_H_
#define _TREE_H_

// 定义树结构
typedef int TREE_TYPE;
typedef struct _TREE_ {
	TREE_TYPE value;
	struct _TREE_ *l;
	struct _TREE_ *r;
} TREE, *PTREE;

// 定义树函数
void insert(TREE_TYPE value);// 向树添加一个节点
TREE_TYPE *find(TREE_TYPE value);// 查找一个特定值
void preorder(PTREE node);// 先序遍历二叉树
void middleorder(PTREE node);// 中序遍历二叉树
void postorder(PTREE node);// 后序遍历二叉树
void test(void);// 测试程序
#endif /* _TREE_H_ */
