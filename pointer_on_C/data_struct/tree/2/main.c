#include<stdio.h>
#include<malloc.h>

/* 定义结构 */
typedef struct binode{
	char data;
	struct binode *lchild,*rchild;
}binode,*bitree;// 定义树结点结构
typedef struct queuenode{
	bitree ch;
	struct queuenode *next;
}queuenode,*queueptr;// 定义队列结点结构
typedef struct{
	queueptr front;
	queueptr rear;
}linkqueue;// 定义队列指针

/* 建树 */
int createbitree(bitree &T,int &sum){
	char ch;
	
	// 输入
	scanf("%c",&ch);
	if(ch==' ') T=NULL;// 输入空格代表没有左右节点
	else {// 新建左右节点
		if(!(T=(bitree)malloc(sizeof(binode))))
		return 0;
		T->data=ch;
		sum++;
		createbitree(T->lchild,sum);
		createbitree(T->rchild,sum);
	}
	
	return 1;
}
/* 初始化一个带头结点的队列 */
void initqueue(linkqueue &q){
 q.front=q.rear=(queueptr)malloc(sizeof(queuenode));
 q.front->next=NULL;
}

/* 入队列 */
void enqueue(linkqueue &q,bitree p){
	queueptr s;
	
	// 分配内存
	s=(queueptr)malloc(sizeof(queuenode));
	// 入队
	s->ch=p;
	s->next=NULL;
	q.rear->next=s;
	q.rear=s;
}

/* 出队列 */
void dequeue(linkqueue &q,bitree &p){
	char data;
	queueptr s;

	// 出队
	s=q.front->next;
	p=s->ch;
	data=p->data;
	q.front->next=s->next;
	if(q.rear==s)
	q.rear=q.front;
	// 释放内存
	free(s);
	
	printf("%c ",data);
}
/* 判断队列是否为空 */
int queueempty(linkqueue q){
	if(q.front->next==NULL) return 1;
	else return 0;
}

/* 按层次遍历树中结点 */
void traverse(bitree bt){
	linkqueue q;
	bitree p;

	// 初始化队列
	initqueue(q);
	p=bt;
	// 根节点入队
	enqueue(q,p);
	// 循环至队列空
	while(queueempty(q)!=1){
		// 出队
		dequeue(q,p);
		// 左右子节点入队
		if(p->lchild!=NULL) enqueue(q,p->lchild);
		if(p->rchild!=NULL) enqueue(q,p->rchild);
	}
	
	printf("\n");
}

/* 主函数 */
int main(void){
	int n=0;
	bitree bt;
	
	createbitree(bt,n);
	printf("该二叉树共有%d个结点.\n",n);
	printf("按层次遍历树中结点其输出顺序为: \n");
	traverse(bt);
	
	return 0;
}
