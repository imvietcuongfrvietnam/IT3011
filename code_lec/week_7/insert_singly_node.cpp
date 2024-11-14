#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

// Function to create a new node
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

// Insert Node

// 1. Insert head by value
Node* insertToHead_thamtri(Node *head, int data) {
    Node *p = makeNode(data);
    p->next = head;
    head = p;
    return head;
}

// 1. Insert head by reference
void insertToHead_thamchieu(Node **head, int data) {
    Node *p = makeNode(data);
    p->next = *head;
    *head = p;
}

// 2. Insert After
void insert_after(Node *cur, int data) {
    Node *p = makeNode(data);
    p->next = cur->next;
    cur->next = p;
}

// 3. Insert Before
void insert_before(Node *head, Node *cur, int data) {
	if(head == NULL){
		head = makeNode(data);
		return;
	}
    Node *p = makeNode(data);
    if (head == cur) { // Special case: if cur is head
        p->next = head;
        head = p;
        return;
    }
    Node *tmp = head;
    while (tmp != nullptr && tmp->next != cur) {
        tmp = tmp->next;
    }
    if (tmp == nullptr) {
        cerr << "Current node not found in the list." << endl;
        delete p; // Avoid memory leak
        return;
    }
    tmp->next = p;
    p->next = cur;
}

// 4. Insert Last
void insert_last(Node *head, int data) {
    Node *p = makeNode(data);
    if (head == nullptr) {
        head = p;
        return;
    }
    Node *last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = p;
}

// Function to print the list
void printList(Node *head) {
    Node *tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Function to free the list
void freeList(Node *head) {
    Node *tmp;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Node *head = nullptr;

    // Example usage
    head = insertToHead_thamtri(head, 10);
    insertToHead_thamchieu(&head, 20);
    insert_after(head, 30);
    insert_last(head, 40);

    printList(head);

    freeList(head); // Free the allocated memory
    return 0;
}

