#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

static PSLL head = NULL;// 定义一个单链表

/* 局部函数，非接口api
** index	0 	1 	2	3 	...
** length	1 	2 	3 	4 	...
*/
static int length_to_index(void){
	PSLL p = NULL;
	int len = 0;
	
	for(p = head; p != NULL; p = p->next) len++;
	return len-1;
}

void creat(void){
	PSLL tail = NULL, new = NULL;
	int value = 0;
	
	while(1){
		scanf("%d", &value);
		if(value == -1) return;// -1结束创建
		else{
			new = (PSLL)malloc(sizeof(SLL));
			new->value = value;new->next = NULL;
			if(head == NULL){// 空链表
				head = new;
				tail = new;
			} else {// 非空链表
				tail->next = new;
				tail = new;
			}
		}
	}
}

void destroy(void){
	PSLL p = NULL, q = NULL;
	
	for(p = head; p != NULL;){
		q = p->next;
		free(p);p = NULL;
		p = q;
	}
	head = NULL;
}

int search(SLL_TYPE value){
	PSLL p = NULL;
	int index = 0;
	
	for(p = head; p != NULL; p = p->next){
		if(p->value == value) return index;
		index++;
	}
	return -1;//未找到
}

void insert(int index, SLL_TYPE value){
	PSLL new = NULL, p = NULL;
	int len = 0, i = 0;
	
	new = (PSLL)malloc(sizeof(SLL));// 分配空间
	new->value = value;
	len = length_to_index();// 获取长度
	if(index == 0){// 头部插入
		new->next = head;
		head = new;
	} else if(index == len){// 尾部插入
		p = head;
		for(i = 0; i < len; i++) p = p->next;// 移动到末尾
		p->next = new;
		new->next = NULL;
	} else if(index > len){// 超过尾部以后的位置
		printf("error, index must <= %d\n", len);
	} else {// 中间插入
		p = head;
		for(i = 0; i < (index-1); i++) p = p->next;// 移动到index位置前一个位置
		new->next = p->next;
		p->next = new;
	}
}

void remov(int index){
	PSLL p = NULL, q = NULL;
	int len = 0, i = 0;
	
	len = length_to_index();// 获取长度
	if(index == 0){// 头部删除
		p = head->next;
		free(head);head = NULL;
		head = p;
	} else if(index == len){// 尾部删除
		p = head;
		for(i = 0; i < (index-1); i++) p = p->next;// 移动到末尾前一个位置
		free(p->next);p->next = NULL;
	} else if(index > len){// 超过尾部以后的位置
		printf("error, index must <= %d\n", len);
	} else {// 中间删除
		p = head;
		for(i = 0; i < (index-1); i++) p = p->next;// 移动到index位置前一个位置
		q = p->next->next;
		free(p->next);p->next = NULL;
		p->next = q;
	}
}

void print(void){
	PSLL p = NULL;
	int index = 0;
	
	for(p = head; p != NULL; p = p->next){
		printf("%d@%p:%p-%d ", index, p, p->next, p->value);
		index++;
	}
	printf("\n");
}

void test(void){
	int choice = 0, index = 0, value = 0;
	
	while(1){
		printf("0-exit 1-creat 2-search 3-insert 4-remov 5-destroy 6-print\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:printf("EXIT\n");return;break;
			case 1:printf("CREAT\n");creat();break;
			case 2:
				printf("SEARCH\n");
				scanf("%d", &value);
				printf("RESULT=%d\n", search(value));
				break;
			case 3:
				printf("INSERT\n");
				scanf("%d %d", &index, &value);
				insert(index, value);
				break;
			case 4:
				printf("REMOVE\n");
				scanf("%d", &index);
				remov(index);
				break;
			case 5:printf("DESTROY\n");destroy();break;
			case 6:printf("PRINT\n");print();break;
			default:printf("ERROR\n");break;
		}
	}
}
