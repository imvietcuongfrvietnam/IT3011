#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
	int coef;
	int exp;
	struct _Node *next;
}Node;

Node *makeNode(int coef, int exp){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL) exit(1);
	p->coef = coef;
	p->exp = exp;
	p->next = NULL;
	return p;
}

int main(){
	
}
