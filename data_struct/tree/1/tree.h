#ifndef _TREE_H_
#define _TREE_H_

// 二叉树节点定义
typedef struct _TREE_ {
	int data;
	struct _TREE_ *l;// 左树
	struct _TREE_ *r;// 右树
} TREE, *PTREE;

// 函数定义
void creat(PTREE *node);//创建二叉树
/*
** 遍历参考http://blog.csdn.net/wtfmonking/article/details/17038077
** 先序遍历:访问根结点的操作在遍历左、右子树之前,顺序为中左右
** 中序遍历:访问根结点的操作在遍历左子树之后和右子树之前,顺序为左中右
** 后序遍历:访问根结点的操作在遍历左、右子树之后,顺序为左右中
*/
void preorder(PTREE node);// 先序遍历二叉树
void middleorder(PTREE node);// 中序遍历二叉树
void postorder(PTREE node);// 后序遍历二叉树
int deep(PTREE node);// 二叉树深度
int leafcount(PTREE node); // 叶子节点数

#endif /* _TREE_H_ */
