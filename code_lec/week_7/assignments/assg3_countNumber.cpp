#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

Node *makeNode(int data){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		exit(1);
	}
	p->data = data;
	p->next = NULL;
	return p;
}

int countNumberInList(Node *head, int x){
	int count = 0;
	Node *tmp = head;
	while(tmp!=NULL){
	//	if(tmp->data == x) count++;
	count+= (tmp->data == x);
		tmp = tmp->next;
	}
	return count;
}
int main(){
	Node *a = makeNode(3);
	Node *b = makeNode(4);
	Node *c = makeNode(3);
	Node *d = makeNode(2);
	a->next = b;
	b->next =c;
	c->next = d;
	Node *head = a;
	printf("%d",countNumberInList(head, 3));
	free(a);
	free(b);
	free(c);
}
