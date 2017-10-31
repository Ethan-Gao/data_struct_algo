#include <stdio.h>
#include "stack.h"

int main(void){
	int choice = 0, value = 0;
	
	creat_stack();
	while(1){
		printf("0-exit 1-push 2-pop 3-print\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:return 0;break;
			case 1:
				printf("PUSH\n");
				while(1){
					scanf("%d", &value);
					if(value == 0) break;// 0退出压栈
					else push(value);
				}
				break;
			case 2:printf("POP\n");printf("pop=%d\n", pop());break;
			case 3:printf("PRINT\n");print();break;
			default:
				printf("choose error\n");
				break;
		}
	}
	destroy_stack();
	
	return 0;
}

/*
** 动态分配数组空间
** 结果:
$ make run
./stack.elf
creat_stack...
0-exit 1-push 2-pop 3-print
1
PUSH
1
5
9
0
0-exit 1-push 2-pop 3-print
3
PRINT
0-1 1-5 2-9
0-exit 1-push 2-pop 3-print
2
POP
pop=9
0-exit 1-push 2-pop 3-print
3
PRINT
0-1 1-5
0-exit 1-push 2-pop 3-print
*/