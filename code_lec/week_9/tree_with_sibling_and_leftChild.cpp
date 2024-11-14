#include<stdio.h>
#include<stdlib.h>
//Tree with leftMostChild and rightSibling
typedef struct _Node{
	struct _Node *leftMostChild;
	struct _Node *rightSibling;
	char data;
}Node;

Node *makeNode(char data){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		printf("Error mem location\n");
		exit(1);
	}
	p->data = data;
	p->leftMostChild = NULL;
	p->rightSibling = NULL;
	return p;
}

//Duyet cay

void preOrder(Node *r){
	if(r == NULL) return;
	printf("%c ",r->data);
	Node *p = r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p = p->rightSibling;
	}
}

void postOrder(Node *r){
	if(r == NULL) return;
	Node* p = r->leftMostChild;
	while(p!=NULL){
		postOrder(p);
		p = p->rightSibling;
	}
	printf("%c ", r->data);
}

void inOrder(Node *r) {
    if (r == NULL) return;

    Node *p = r->leftMostChild;
    if (p != NULL) {
        inOrder(p); 
    }

    printf("%c ", r->data);

    if (p != NULL) p = p->rightSibling;
    while (p != NULL) {
        inOrder(p);
        p = p->rightSibling;
    }
}

int countNode(Node *r){
	if(r == NULL) return 0;
	Node *p = r->leftMostChild;
	int dem = 1;
	if(p == NULL) return dem;
	dem = dem + countNode(p);
	p = p->rightSibling;
	while(p!=NULL){
		dem += countNode(p);
		p = p->rightSibling;
	}
	return dem;
}

int height(Node *r){
	if(r == NULL) return 0;
	int heighth = 1;
	Node *p = r->leftMostChild;
	if(p == NULL) return heighth;
	int childHeight = height(p);
	p = p->rightSibling;
	while(p!=NULL){
		int h = height(p);
		if(childHeight<h) childHeight = h;
		p = p->rightSibling;
	}
	return heighth + childHeight;
}

int countLeaves(Node *r){
	if (r == NULL) return 0;
	Node *p = r->leftMostChild;
	if(p == NULL) return 1;
	int childLeaves = countLeaves(p);
	p = p->rightSibling;
	while(p!=NULL){
		childLeaves += countLeaves(p);
		p = p->rightSibling;
	}
	return childLeaves;
}

Node *parent(Node *root, Node *p){
	if(root == NULL || p == NULL) return NULL;
	  Node *child = root->leftMostChild;
    while (child != NULL) {
        if (child == p) {
            return root;  
        }
        child = child->rightSibling;  
    }
	child = root->leftMostChild;
    while (child != NULL) {
        Node *res = parent(child, p);  
        if (res != NULL) return res;  
        child = child->rightSibling;   
    }

    return NULL; 
} //Tim de quy theo chieu ngang

Node *parent2(Node *root, Node *p){
	if(root == NULL || p == NULL) return NULL;
	Node *q = root->leftMostChild;
	while(q!= NULL){
		if(q == p) return root;
		Node *tmp = parent2(q, p);
		if(tmp != NULL) return tmp;
		q = q->rightSibling;
	}
	return NULL;
}//De quy chieu doc (doc theo cay)

Node *find(Node *r, char data){
	if(r == NULL) return NULL;
	if(r->data == data) return r;
	Node *p = r->leftMostChild;
	while(p!= NULL){
		Node *tmp = find(p, data);
		if(tmp != NULL) return tmp;
		p = p->rightSibling;
	}
	return NULL;
}

void freeTree(Node *r){
	if(r == NULL) return;
	Node *p = r->leftMostChild;
	while(p!=NULL){
		Node *h = p->rightSibling;
		freeTree(p);
		p = h;
	}
	free(r);
}

int countNodeKChild(Node *r, int k){
	if(r == NULL) return 0;
	int dem = 0;
	Node *p = r->leftMostChild;
	while(p!=NULL){
		dem++;
		p = p->rightSibling;
	}
	if(dem == k) dem = 1;
	else dem = 0;
	for(Node *p = r->leftMostChild;p!=NULL;p=p->rightSibling){
		dem += countNodeKChild(p,k);
	}
	return dem;
}

int stepDepth(Node *r, Node *p, int k){
	if(r == p) return k;
	if(r == NULL) return NULL;
	for(Node *q = r->leftMostChild;q!=NULL;q = q->rightSibling){
		int tmp = stepDepth(q, p, k+1);
		if(tmp) return tmp;
	}
	return 0;
}
int depth(Node *r, Node *p){
return stepDepth(r, p, 1);
}

//**** Do cao va do sau duoc tinh tu 1 
int main(){
	Node *B = makeNode('B');
	Node *J = makeNode('J');
	Node *K = makeNode('K');
	Node *E = makeNode('E');
	Node *F = makeNode('F');
	Node *N = makeNode('N');
	Node *O = makeNode('O');
	Node *P = makeNode('P');
	B->leftMostChild = E;
	E->rightSibling = F;
	E->leftMostChild = J;
	J->rightSibling = K;
	K->leftMostChild = N;
	N->rightSibling = O;
	O->rightSibling = P;
	Node *root = B;
	preOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n%d\n%d\n%d\n%c\n%c\n%c\n%d\n%d",height(root),countNode(root),countLeaves(root), parent(root, J)->data, parent2(root, J)->data, find(root, 'J')->data,
	countNodeKChild(root, 2),depth(root, J));


}
