#include <stdio.h>
#include "queue.h"

int main(void){
	QUEUE_TYPE value = 0;
	int choice = 0;
	
	while(1){
		printf("0-exit 1-insert 2-delete 3-print\n");
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
0-exit 1-insert 2-delete 3-print
1
INSERT
1
5
8
2
7
0
0-exit 1-insert 2-delete 3-print
3
front=1 rear=5
index=1,value=1 index=2,value=5 index=3,value=8 index=4,value=2 index=5,value=7
EXIT
0-exit 1-insert 2-delete 3-print
2
DELETE
1
0-exit 1-insert 2-delete 3-print
1
INSERT
4
0
0-exit 1-insert 2-delete 3-print
3
front=2 rear=0
index=2,value=5 index=3,value=8 index=4,value=2 index=5,value=7 index=6,value=2
EXIT
0-exit 1-insert 2-delete 3-print
*/