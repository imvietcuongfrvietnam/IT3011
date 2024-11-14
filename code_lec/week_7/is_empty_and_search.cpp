#include<cstdio>
#include<cstdlib>

using namespace std;
typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

int isEmpty(Node *head){
	return head == nul;
}

//Search data = k
Node *search_data_equal(Node *head, int k){
	Node *tmp = head;
	while(tmp->data!=k && tmp!=NULL){
		tmp = tmp->next;
	}
	return tmp;
}

Node *search_element_in_k_position(Node * head, int k){
	int cnt = 0;
	Node *tmp = head;
	while(tmp!=NULL && cnt != k){
		cnt++;
		tmp = tmp->next;
	}
	return tmp;
}
int main(){
	
}
