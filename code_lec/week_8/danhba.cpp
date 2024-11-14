#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _data{
	char sdt[20];
	char ht[30];
	char email[50];
	char chucvu[20];
	int ns;
}data;

typedef struct _Node{
	data data;
	struct _Node *next;
	struct _Node *prev;
}Node;

Node *makeNode(char *sdt, char *ht, char *email, char *chucvu, int ns){
	Node *p = (Node*)malloc(sizeof(Node));
	if (p == NULL){
		printf("Error");
		exit(1);
	}
	strcpy(p->data.ht, ht);
	strcpy(p->data.email, email);
	strcpy(p->data.sdt, sdt);
	strcpy(p->data.chucvu, chucvu);
	p->data.ns = ns;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void search(Node *head){
	Node *tmp = head;
	while(tmp != NULL){
		if(tmp->data.ns > 2000) printf("%s\n",tmp->data.ht);
		tmp = tmp->next;
	}
}

	void insertAfter(Node*& head, Node *p, int x) {
    if (head == NULL) {
        head = newNode(x);
        return;
    }

    Node *q = newNode(x);
    q->prev = p;
    q->next = p->next;
    p->next = q;
    
    if (q->next != NULL) { // Only update q->next->prev if q->next is not NULL
        q->next->prev = q;
    }
}

int main(){
	Node *a = makeNode("0912791554", "giang", "giang@gmail.com", "sinh vien", 2005);
	Node *b = makeNode("0904744241","tung", "tung@gmail.com", "sinh vien", 2000);
	Node *c = makeNode("0904123243","cuong","cuong@gmail.com","sinh vien", 2004);
	a->next = b;
	b->next = c;
	c->prev = b;
	b->prev = a;
	search(a);
}
