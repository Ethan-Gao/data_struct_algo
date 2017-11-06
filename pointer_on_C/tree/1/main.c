#include <stdio.h>
#include "tree.h"

int main(void){
	PTREE root = NULL;
	int depth = 0, count = 0;

	printf("请输入第一个节点的值，-1表示没有叶节点：\n");  
	creat(&root);  

	printf("先序遍历二叉树：");  
	preorder(root);
	printf("\n");

	printf("中序遍历二叉树：");  
	middleorder(root); 
	printf("\n");

	printf("后续遍历二叉树：");  
	postorder(root);
	printf("\n");

	depth = deep(root);  
	printf("树的深度为：%d\n",depth);  

	count = leafcount(root);  
	printf("叶子节点个数:%d\n",count);

	return 0;
}