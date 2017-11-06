#include <stdio.h>
#include "stack.h"

int main(void){
	int choice = 0, value = 0;
	
	while(1){
		printf("0-exit 1-push 2-pop 3-top 4-print 5-pop_top\n");
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
			case 2:printf("POP\n");pop();break;
			case 3:printf("TOP\n");printf("top=%d\n", top());break;
			case 4:printf("PRINT\n");print();break;
			case 5:printf("POP_TOP\n");printf("top=%d\n", pop_top());break;
			default:
				printf("choose error\n");
				break;
		}
	}
}

/*
** 直接指定数组空间
** 结果:
$ make run
./stack.elf
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
1
PUSH
12
5
8
2
0
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
4
PRINT
0-12 1-5 2-8 3-2
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
2
POP
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
4
PRINT
0-12 1-5 2-8
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
3
TOP
top=8
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
4
PRINT
0-12 1-5 2-8
0-exit 1-push 2-pop 3-top 4-print 5-pop_top
*/