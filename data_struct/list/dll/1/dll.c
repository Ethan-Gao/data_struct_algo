#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void creat(linkList *head){
	linkList new = NULL, tail = NULL;
	int value = 0;
	
	while(1){
		/* 输入数据,0退出 */
		scanf("%d",&value);
		if(value == 0) return;
		/* 创建链表 */
		// 分配内存
		new = (linkList)malloc(sizeof(List));
		// 操作链表
		if( (*head) == NULL ){// 链表头
			*head = new;
			new->pre = NULL;new->next = NULL;new->data = value;
		} else {
			tail->next = new;
			new->pre = tail;new->next = NULL;new->data = value;
		}
		// 更新尾部
		tail = new;
	}
}

void print(linkList *head){
	linkList tmp = NULL;
	
	for(tmp = *head; tmp != NULL; tmp = tmp->next)
		printf("%p:%p-%p-%d ",tmp,tmp->pre,tmp->next,tmp->data);
	printf("\n");
}

void sort(linkList *head){
	linkList p1 = NULL, p2 = NULL, tail = NULL;
	int val = 0;
	
	for(p1 = *head; p1->next != NULL; p1 = p1->next){
		// 进行排序
		for(p2 = *head; p2->next != tail; p2 = p2->next){
			if(p2->data > p2->next->data){
				val = p2->data;
				p2->data = p2->next->data;
				p2->next->data = val;
			}
		}
		// 更新尾部
		tail = p2;
	}
}

void reverse(linkList *head){
	linkList tmp1 = NULL, tmp2 = NULL, p = NULL;
	
	for(p = *head; p != NULL;){
		// 备份
		tmp1 = p->next;
		tmp2 = p->pre;
		// 修改
		p->pre = tmp1;
		p->next = tmp2;
		// 还原
		p = tmp1;
	}
	// 更新头部
	*head = tmp2->pre;
}

void add(linkList *head){
	linkList new = NULL, tmp = NULL, tail = NULL;
	int value = 0;
	
	/* 输入数据 */
	scanf("%d",&value);
	/* 插入链表 */
	// 寻找尾部
	for(tmp = *head; tmp->next != NULL; tmp = tmp->next);tail = tmp;
	// 分配内存
	new = (linkList)malloc(sizeof(List));
	new->data = value;
	// 寻找位置
	if( value < (*head)->data ){// 头部
		new->next = *head;new->pre = NULL;
		(*head)->pre = new;
		// 更新头部
		*head = new;
	} else if( value > tail->data ){// 尾部
		tail->next = new;
		new->pre = tail;new->next = NULL;
	} else {// 中部
		for(tmp = *head; tmp->next != NULL; tmp = tmp->next){
			if( ( tmp->data < value ) && ( value < tmp->next->data ) ){
				new->next = tmp->next;new->pre = tmp;
				tmp->next->pre = new;
				tmp->next = new;
			}
		}
	}
}

void del(linkList *head){
	linkList tmp = NULL, old = NULL;
	int value = 0;
	
	/* 输入删除的数据 */
	scanf("%d",&value);
	/* 寻找删除位置 */
	for(tmp = *head; tmp != NULL; tmp = tmp->next){
		if(tmp->data == value){// 存在此数值
			// 操作链表
			if( tmp == (*head) ) {(*head) = (*head)->next;(*head)->pre = NULL;}
			else old->next = tmp->next;
			// 释放空间
			free(tmp);
			return;
		}
		old = tmp;
	}
	printf("mismatch\n");	
}

void destroy(linkList *head){
	linkList tmp = NULL, next = NULL;

 	tmp = *head;
	while(tmp != NULL){
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*head = NULL;// free会释放内存，但是不会设置指针为NULL，需要手动设置	
}
