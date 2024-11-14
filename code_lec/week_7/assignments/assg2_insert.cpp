#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

//Traversal

//while

void printList(Node *head){
	Node *p = head;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
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

Node* insertToHead_thamtri(Node *head, int data){
	Node *p = makeNode(data);
	p->next = head;
	head = p;
	return head;
}

void insertToHead_thamchieu(Node **head, int data){
	Node *p = makeNode(data);
	p->next = *head;
	*head = p;
}
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d",&n);
	Node *head;
	int data;
	printf("Nhap vao so thu 1: ");
	scanf("%d", &data);
	head = makeNode(data);
	for(int i = 2;i<=n;i++){
		printf("Nhap vao so thu %d: ",i);
		scanf("%d",&data);
		head = insertToHead_thamtri(head, data);
	//	insertToHead_thamchieu(&head, data);
	}
	printList(head);
	return 0;
}

