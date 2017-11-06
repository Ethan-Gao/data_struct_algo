#include <stdio.h>
#include "dll.h"

int main(void){
	linkList head = NULL;
	int choice = 0;
	
	while(1){
		printf("0-exit 1-creat 2-print 3-sort 4-reverse 5-add 6-del 7-destroy\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:return 0;break;
			case 1:printf("CREAT:\n");creat(&head);break;
			case 2:printf("PRINT:\n");print(&head);break;
			case 3:printf("SORT:\n");sort(&head);break;
			case 4:printf("REVERSE:\n");reverse(&head);break;
			case 5:printf("ADD:\n");add(&head);break;
			case 6:printf("DEL:\n");del(&head);break;
			case 7:printf("DESTROY:\n");destroy(&head);break;
		}
	}
	return 0;
}
