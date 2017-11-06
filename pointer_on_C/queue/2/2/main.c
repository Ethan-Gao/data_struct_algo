#include <stdio.h>
#include "queue.h"

int main(void){
	QUEUE_TYPE value = 0;
	int choice = 0;
	
	while(1){
		printf("0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:printf("EXIT\n");return 0;break;
			case 1:
				printf("INSERT\n");
				while(1){
					scanf("%d",&value);// 0结束
					if(value == 0) break;
					insert(value);
				}
				break;
			case 2:
				printf("DELETE\n");
				printf("%d\n",delete());
				break;
			case 3:print();printf("EXIT\n");break;
			case 4:printf("CREAT_QUEUE\n");creat_queue();break;
			case 5:printf("DESTROY_QUEUE\n");destroy_queue();break;
		}
	}
}

/*
** 循环队列说明：
** 1.删除位置为队头front，删除一个front增1，插入位置为队尾，插入一个队尾增1
** 2.通常情况front都会<=rear，但是操作很多次以后，就会越过循环队列的头尾节点的交界点
**	此时rear由于大于数组长度，从而rear=rear/数组长度，导致rear<front
** 3.静态数组必须留一个空位，以便区分空和满
** 结果:
$ make run
./main.elf
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
4
CREAT_QUEUE
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
1
INSERT
12
56
2
9
34
0
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
3
front=0 rear=0
index=0,value=34 index=1,value=12 index=2,value=56 index=3,value=2 index=4,value=9
EXIT
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
2
DELETE
34
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
2
DELETE
12
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
3
front=2 rear=0
index=2,value=56 index=3,value=2 index=4,value=9
EXIT
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
1
INSERT
123
678
0
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
3
front=2 rear=2
index=2,value=678 index=3,value=2 index=4,value=9 index=0,value=34 index=1,value=123
EXIT
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
5
DESTROY_QUEUE
0-exit 1-insert 2-delete 3-print 4-creat_queue 5-destroy_queue
*/