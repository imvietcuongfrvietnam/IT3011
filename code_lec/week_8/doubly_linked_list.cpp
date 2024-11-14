#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
	struct _Node *next;
	struct _Node *prev;
	int data;
}Node;

Node *newNode(int data){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
		printf("Error meme alloc");
		exit(1);
	}	
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void traversal_before(Node *head){
	for(Node *tmp = head; tmp!=NULL;tmp = tmp->next){
		printf("%d ",tmp->data);
	}
}

void traversal_before2(Node *head){
	Node *tmp = head;
	while(tmp!=NULL){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

void traversal_after(Node *tail){
	for(Node *tmp = tail;tmp!=NULL;tmp = tmp->prev){
		printf("%d ",tmp->data);
	}
}

void traversal_after2(Node *tail){
	Node *tmp = tail;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp ->prev;
	}
}

void deleteNode(Node *head, Node*tail, Node *p){
	if(head == NULL) {printf("Danh sach rong");
	return;
	}
	else if(head == p){
		head = head->next;
		head->prev = NULL;
		free(p);
	}
	else if(p == tail){
		tail = tail->prev;
		tail->next = NULL;
		free(tail);
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);	
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
	Node *a = newNode(10);
	//Node *b = newNode(20);
	insertAfter(a, a,4);
	insertAfter(a, a,5);
	traversal_before(a);
}
