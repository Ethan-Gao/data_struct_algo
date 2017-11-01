#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

void creat(linkList *head){
	linkList new = NULL, tail = NULL;
	int value = 0;
	
	while(1){
		/* 输入数据,0退出 */
		scanf("%d",&value);
		if( value == 0 ) return;
		/* 创建链表 */
		new = (linkList)malloc(sizeof(List));
		if( (*head) == NULL ){// 链表头
			// 操作链表
			*head = new;
			new->next = NULL;new->data = value;
		} else {
			// 操作链表
			tail->next = new;
			new->next = NULL;new->data = value;
		}
		/* 更新尾部 */
		tail = new;
	}
}

void print(linkList *head){
	linkList tmp = NULL;
	
	/* 循环打印 */
	for(tmp = *head; tmp != NULL; tmp = tmp->next)
		printf("%p-%p-%d ",tmp,tmp->next,tmp->data);
	printf("\n");
}

void sort(linkList *head){
	linkList p1 = NULL, p2 = NULL, tail = NULL;
	int val = 0;
	
	/* 进行排序 */
	tail = NULL;
	for(p1 = *head; p1->next != NULL; p1 = p1->next){
		// 交换顺序
		printf("tail=%p\n",tail);
		for(p2 = *head; p2->next != tail; p2 = p2->next){
			if(p2->data > p2->next->data){
				val = p2->data;
				p2->data = p2->next->data;
				p2->next->data = val;
			}
		}
		// 移动尾部
		tail = p2;
	}
}

void reverse(linkList *head){
	linkList old = NULL, new = NULL, tmp = NULL;
	
	/* 从原链表的头部一个一个取节点并插入到新链表的头部 */
	for(old = *head; old != NULL;){
		// 保存下一个节点
		tmp = old->next;
		// 操作链表
		old->next = new;
		new = old;
		// 恢复原链表
		old = tmp;
	}
	*head = new;
}

void add(linkList *head){
	linkList tmp = NULL, tail = NULL, new = NULL;
	int value = 0;
	
	/* 输入插入的数据 */
	scanf("%d",&value);
	/* 分配空间 */
	new = (linkList)malloc(sizeof(List));
	/* 寻找尾部 */
	for(tmp = *head; tmp->next != NULL; tmp = tmp->next);tail = tmp;
	/* 插入元素 */
	if(value < (*head)->data){// 头部
		new->next = *head;new->data = value;
		*head = new;
	} else if(value > tail->data){// 尾部
		tail->next = new;
		new->next = NULL;new->data = value;
	} else {// 中间
		for(tmp = *head; tmp->next != NULL; tmp = tmp->next){
			if((tmp->data < value) && (tmp->next->data > value)){
				new->next = tmp->next;new->data = value;
				tmp->next = new;
				break;
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
			if( tmp == (*head) ){(*head) = (*head)->next;}
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
