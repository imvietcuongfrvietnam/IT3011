#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
	char data;
	struct _Node *next;
}Node;

typedef struct _N{
	char *p;
	char c;
}N;
int main(){
	Node *node1, *node2, *node3;
	node1 = (Node*)malloc(sizeof(Node));
	node2 = (Node*)malloc(sizeof(Node));
	node3 = (Node*)malloc(sizeof(Node));
	node1->next = node2;
	node2->next = node3;
	node1->data = 'a';
	node2->data = 'b';
	node3->data = 'c';
	node3->next = NULL;
	printf("%d %d %d",sizeof(Node),sizeof(char),sizeof(N));
	Node *node = node1;
	while(node!=NULL){
		printf("\n%c",node->data);
		node = node->next;
	}
}
