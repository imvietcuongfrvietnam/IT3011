#include<stdio.h>
#include<stdlib.h>
typedef struct _data{
	char id[10];
	char ht[30];
}data;
typedef struct _Node{
	struct{
		char id[10];
		char ht[30];	
	}data;
	struct _Node *next;
}Node;

Node *head;

int main(){
	Node* node;
	char c;
	node = (Node*)malloc(sizeof(Node));
	scanf("%s %s", node->data.ht,node->data.id);
	node->next = NULL;
	head = node;
	printf("%s %s %d %d", head->data.id, head->data.ht,sizeof(Node),sizeof(data));
}
