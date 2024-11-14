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

int main(){
	
}
