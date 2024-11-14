#include<cstdio>
#include<cstdlib>

using namespace std;
typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

Node* makeNode(int data) {
    Node *p = new Node;
    if (p == NULL) {
        cerr << "Memory allocation failed!" << endl;
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->next = nullptr;
    return p;
}

//Delete Node
//1 Delete a node
//1.1Delete first
Node* delete_first(Node* head){
	Node *p = head->next;
	delete head;
	head = head->next;
	return head;
}
//1.2 Delete mid or last
void delete_mid_or_last(Node *head, Node *del){
	if(head == del){
		delete_first(head);
		return;
	}
	Node *tmp = head;
	while(tmp->next != del) tmp = tmp->next;
	tmp->next = del->next;
	delete del;
	
}

//2 Delete all
void delete_all(Node *head){
	Node *cur = head;
	while(cur != NULL){
		cur = cur->next;
		delete head;
		head = cur;
	}
}
int main(){
	
}
