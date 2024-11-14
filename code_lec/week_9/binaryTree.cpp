#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
	struct _Node *leftChild;
	struct _Node *rightChild;
	char data;
}Node; //Binary Tree


Node *makeNode(char data){
	Node *p = (Node *)malloc(sizeof(Node));
	if(p == NULL){
		printf("Error mem loation\n");
		exit(1);
	}
	p->data = data;
	p->leftChild = NULL;
	p->rightChild = NULL;
}

void preOrder(Node *r){
	if(r == NULL) return;
	printf("%c ", r->data);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void postOrder(Node *r){
	if(r == NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	printf("%c ",r->data);
}

void inOrder(Node *r){
	if(r == NULL) return;
	inOrder(r->leftChild);
	printf("%c ",r->data);
	inOrder(r->rightChild);
}

int countNode(Node *r){
	if(r == NULL) return 0;
	return 1+ countNode(r->leftChild) + countNode(r->rightChild);
}

int countLeaves(Node *r){
	if(r == NULL) return 0;
	if(r->leftChild == NULL && r->rightChild == NULL) return 1;
	return countLeaves(r->leftChild) + countLeaves(r->rightChild);
}

int height(Node *r){
	if(r == NULL) return;
	int hLeft = height(r->leftChild), hRgiht = height(r->rightChild);
	return hLeft>hRight?hLeft+1:hRight+1;
}

int countNodeKChild(Node *r, int k){
	if(r == NULL || k>2 || k<0) return 0;
	int dem = 0;
	if(r->leftChild!=NULL) dem++;
	if(r->rightChild!=NULL) dem++;
	return dem == k + countNodeKChild(r->leftChild) + countNodeKChild(r->rightChild);
}

int countNodeLeftChild(Node *r){
	//Chi tinh cac nut ben trai cua cay
	if(r == NULL ) return 0;
	return (r->leftChild!=NULL && r->rightChild== NULL) + countNodeLeftChild(r->leftChild) + countNodeLeftChild(r->rightChild);
}

void freeTree(Node *r){
	if(r == NULL) return;
	freeTree(r->leftChild);
	freeTree(r->rightChild);
	free(r);
}

Node* parent(Node* r, Node* p){
	if(r == NULL) return NULL;
	if(r->leftChild == p || r->rightChild == p) return r;
	
	Node* q = parent(r->leftChild,p);
	if(q!=NULL) return q;
	
	return parent(r->rightChild,p);
}

int stepdepth(Node* r, Node* p, int k){
	if(r == NULL) return 0;
	if(r == p) return k;

	int l1 = stepdepth(r->leftChild, p, k+1);
	if(l1!=0) return l1;
	
	return stepdepth(r->rightChild, p, k+1);
}

int depth(Node* r, Node* p){
	if(r == NULL || p == NULL) return 0;
	
	return stepdepth(r,p,1);
}

bool isFullBinaryTree(Node *r){
	if(r == NULL) return true;
	if(r->leftChild == NULL && r->rightChild == NULL) return true;
	return isFullBinaryTree(r->leftChild) && isFullBinaryTree(r->rightChild) && (height(r->leftChild) == height(r->rightChild));
}

bool isCompleteBT(Node *r){
	if (r == NULL) return true;
	else if
}

