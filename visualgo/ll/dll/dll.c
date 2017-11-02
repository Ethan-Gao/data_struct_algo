#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dll.h"

static PDLL dll = NULL;// 定义空双链表

void creat(void){
	PDLL new = NULL, tail = NULL;
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1停止创建
		else {
			new = (PDLL)malloc(sizeof(DLL));
			new->value = value;
			if(dll == NULL){// 空链表
				new->pre = NULL;new->next = NULL;
				dll = new;// 更新链头
				tail = new;// 更新链尾
			} else {// 非空链表
				tail->next = new;
				new->pre = tail;new->next = NULL;
				tail = new;// 更新链尾
			}
		}
	}
}

void destroy(void){
	PDLL p = NULL, q = NULL;
	
	for(p = dll; p != NULL;){
		q = p->next;
		free(p);p = NULL;
		p = q;
	}
	dll = NULL;
}

void print(void){
	PDLL p = NULL;
	
	for(p = dll; p != NULL; p = p->next)
		printf("%p:%p-%p-%d ", p, p->pre, p->next, p->value);
	printf("\n");
}

int search(DLL_TYPE value){
	PDLL p = NULL;
	int index = 0;
	
	for(p = dll; p != NULL; p = p->next){
		if(p->value == value) return index;
		index++;
	}
	return -1;// 未找到
}

void insert(int index, DLL_TYPE value){
	PDLL p = NULL, new = NULL;
	int sz = 0, i = 0;
	
	sz = size();// 最大索引值=元素个数-1
	assert(!is_full());
	new = (PDLL)malloc(sizeof(DLL));
	new->value = value;
	if(index == 0){// 头部插入
		new->pre = NULL;new->next = dll;
		dll->pre = new;
		dll = new;// 更新链头
	} else if(index == sz){// 尾部插入
		p = dll;
		for(i = 0; i< (index-1); i++) p = p->next;// 移动到index前一个位置
		p->next = new;
		new->pre = p;new->next = NULL;
	} else if(index > sz){// 超范围
		printf("error, index must <= %d\n", sz);
	} else {// 中间插入
		p = dll;
		for(i = 0; i< (index-1); i++) p = p->next;// 移动到index前一个位置
		new->pre = p;new->next = p->next;
		p->next = new;
	}
}

void delete(int index){
	PDLL p = NULL, q = NULL;
	int sz = 0, i = 0;
	
	sz = size();// 最大索引值=元素个数-1
	assert(!is_empty());
	if(index == 0){// 头部删除
		p = dll->next;
		free(dll);dll = NULL;
		p->pre = NULL;
		dll = p;// 更新链头
	} else if(index == (sz-1)){// 尾部删除
		p = dll;
		for(i = 0; i< (index-1); i++) p = p->next;// 移动到index前一个位置
		free(p->next);p->next = NULL;
		p->next = NULL;// 更新链尾
	} else if(index > (sz-1)){// 超范围
		printf("error, index must <= %d\n", sz-1);
	} else {// 中间删除
		p = dll;
		for(i = 0; i< (index-1); i++) p = p->next;// 移动到index前一个位置
		q = p->next->next;
		free(p->next);p->next = NULL;
		p->next = q;
		q->pre = p;
	}
}

/*
** 索引从0开始,最大索引值=元素个数-1
** 最大索引	0 	1 	2 	...
** 元素个数	1 	2	3	...
*/
int size(void){
	PDLL p = NULL;
	int sz = 0;
	
	for(p = dll; p != NULL; p = p->next) sz++;
	return sz;
}

int is_empty(void){
	return dll == NULL;
}

int is_full(void){
	return 0;// 永然不满
}

void test(void){
	int choice = 0, value = 0, index = 0;
	
	while(1){
		printf("0-exit 1-creat 2-destroy 3-search 4-insert 5-delete 6-size 7-print 8-empty 9-full\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:printf("DESTROY\n");destroy();break;
			case 3:
				printf("SEARCH\n");
				scanf("%d", &value);
				printf("%d\n", search(value));
				break;
			case 4:
				printf("INSERT\n");
				scanf("%d %d", &index, &value);
				insert(index, value);
				break;
			case 5:
				printf("DELETE\n");
				scanf("%d", &index);
				delete(index);
				break;
			case 6:printf("SIZE\n");printf("%d\n",size());break;
			case 7:printf("PRINT\n");print();break;
			case 8:printf("EMPTY\n");printf("%d\n",is_empty());break;
			case 9:printf("FULL\n");printf("%d\n",is_full());break;
			default:printf("ERROR\n");break;
		}
	}	
}
