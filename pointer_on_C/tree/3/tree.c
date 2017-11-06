#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

/* 程序参考http://blog.csdn.net/chenyufeng1991/article/details/50858926 */
void creat(PTREE *node){
	int value = 0;
	
	/* 输入数据 */
	scanf("%d", &value);
	if(value == -1){// -1停止
		*node = NULL;
		return;
	} else {
		/* 新建节点 */
		*node = (PTREE)malloc(sizeof(TREE));
		(*node)->data = value;
		printf("输入%d节点的左子节点\n", value);
		creat( &( (*node)->l ) );
		printf("输入%d节点的右子节点\n", value);
		creat( &( (*node)->r ) );
	}
}

void preorder(PTREE node){
	if(node == NULL) return;
	else {
		printf("%d ",node->data);
		preorder(node->l);
		preorder(node->r);
	}
}

void middleorder(PTREE node){
	if(node == NULL) return;
	else {
		preorder(node->l);
		printf("%d ",node->data);
		preorder(node->r);
	}	
}

void postorder(PTREE node){
	if(node == NULL) return;
	else {
		preorder(node->l);
		preorder(node->r);
		printf("%d ",node->data);
	}	
}

void traverse(PTREE node){
	PTREE p = node;
	
	if(p == NULL) return;
	else {
		insert(p);// 根节点入队尾
		while(!is_empty()){// 判断队列是否空
			p = delete();// 队头出队列
			printf("%d ",p->data);// 打印节点值
			if(p->l != NULL) insert(p->l);// 左节点入队尾
			if(p->r != NULL) insert(p->r);// 右节点入队尾
		}
	}
}

int deep(PTREE node){
	int depth = 0, leftdeep = 0, rightdeep = 0;
	
	if(node == NULL) return;
	else {
		leftdeep = deep(node->l);
		rightdeep = deep(node->r);
		depth = (leftdeep >= rightdeep)?(leftdeep+1):(rightdeep+1);
	}
	return depth;
}

int width(PTREE node){
	PTREE p = node;
	int l = 0, i = 0, j = 0, max = 0;
	
	if(p == NULL) return;
	else {
		insert(p);// 根节点入队尾
		while(!is_empty()){// 判断队列是否空
			l = len();
			max = (max>l)?max:l;
//			printf("%d-%d ",j,l);
			for(i = 0; i < l; i++){// 上一层所有节点出队头
				p = delete();// 上一层节点出队头
				if(p->l != NULL) insert(p->l);// 下一层左节点入队尾
				if(p->r != NULL) insert(p->r);// 下一层右节点入队尾
			}
//			j++;
		}
	}
//	printf("\n");
	
	return max;
}

int leafcount(PTREE node){
	static int count = 0;
	
	if(node != NULL){
		if(node->l == NULL && node->r == NULL) count++;
		leafcount(node->l);
		leafcount(node->r);
	}
	return count;
}
