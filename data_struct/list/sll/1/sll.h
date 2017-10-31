#ifndef _SLL_H_
#define _SLL_H_

/* 链表定义 */
typedef struct NODE
{
    int data;
    struct NODE *next;
}List,*linkList;

/* 函数声明 */
void creat(linkList *head);
void print(linkList *head);
void sort(linkList *head);// 冒泡排序，从小到大
void reverse(linkList *head);
void add(linkList *head);// 只针对从小到大有序链表
void del(linkList *head);
void destroy(linkList *head);

#endif /* _SLL_H_ */
