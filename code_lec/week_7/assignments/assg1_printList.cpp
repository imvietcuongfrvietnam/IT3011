#include<cstdlib>
#include<stdio.h>
typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

//Traversal

//while

void traversal_while(Node *head){
	Node *p = head;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

void traversal_for(Node* head){
	Node *cur;
	for(cur = head;cur!=NULL;cur = cur->next){
		printf("%d ",cur->data);
	}
}
Node *makeNode(int data){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		exit(1);
	}
	p->data = data;
	p->next = NULL;
	return p;
}


int main(){
Node *a = makeNode(1);
Node *b = makeNode(2);
Node *c = makeNode(3);
Node *head = a;
a->next = b;
b->next = c;
traversal_for(head);
printf("\n");
traversal_while(head);
}
