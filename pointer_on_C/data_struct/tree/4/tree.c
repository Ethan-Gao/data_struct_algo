#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

/* 定义树根节点指针 */
static PTREE root = NULL;

void insert(TREE_TYPE value){
	PTREE current = NULL, *link = NULL;
	
	// 从根节点开始
	link = &root;
	// 持续查找值，进入合适的子树
	while( (current = *link) != NULL ){
		// 根据情况进入左子树或者右子树
		if( value < current->value ) link = &current->l;
		else {
			assert(value != current->value);// 不使用相同元素
			link = &current->r;
		}
	}
	// 创建新节点
	current = (PTREE)malloc(sizeof(TREE));
	assert(current != NULL);
	current->value = value;
	current->l = NULL;current->r = NULL;
	// 连接节点到树
	*link = current;
}

TREE_TYPE *find(TREE_TYPE value){
	PTREE current = NULL;
	
	// 从根节点开始，持续查找
	current = root;
	while( current != NULL && current->value != value ){
		if( value < current->value ) current = current->l;
		else current = current->r;
	}
	// 查找完毕
	if(current != NULL) return &current->value;// 查找到
	else return NULL;// 未找到
}

void delete(TREE_TYPE value){
	
}

void preorder(PTREE node){
	if(node != NULL){
		printf("%d ",node->value);
		preorder(node->l);
		preorder(node->r);
	}
}

void middleorder(PTREE node){
	if(node != NULL){
		middleorder(node->l);
		printf("%d ",node->value);
		middleorder(node->r);
	}	
}

void postorder(PTREE node){
	if(node != NULL){
		postorder(node->l);
		postorder(node->r);
		printf("%d ",node->value);
	}	
}

void test(void){
	TREE_TYPE arr[] = {1, 5, 4, 3, 2, 6}; 
	int i = 0;
	
	// 输入树
	printf("开始插入数值：");
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ",arr[i]);
		insert(arr[i]);
	}
	printf("\n");
	// 打印遍历结果
	printf("前序遍历结果为：");
	preorder(root);
	printf("\n");
	printf("中序遍历结果为：");
	middleorder(root);
	printf("\n");
	printf("后序遍历结果为：");
	postorder(root);
	printf("\n");
	// 查找一个数值
	printf("查找%d结果为%p\n",5,find(5));
}