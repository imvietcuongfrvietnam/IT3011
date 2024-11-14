#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

typedef struct _stack {
    Node *top;
    int size;
} stack;

Node *makeNode(int data) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }   
    p->data = data;
    p->next = NULL;
    return p;
}

void initStack(stack *s) {
    s->top = NULL;
    s->size = 0;
}

bool isEmpty(stack *s) {
    return s->top == NULL;
}

int top(stack *s) {
    if (isEmpty(s)) return -1;
    return s->top->data;
}

void push(stack *s, int x) {
    Node *p = makeNode(x);
    p->next = s->top;
    s->top = p;
    s->size++;
}

void pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, nothing to pop\n");
        return;
    }
    Node *p = s->top;
    s->top = s->top->next;
    free(p);
    s->size--;
}

int main() {
    stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", top(&myStack));

    pop(&myStack);
    printf("Top element after pop: %d\n", top(&myStack));

    pop(&myStack);
    pop(&myStack);
    pop(&myStack);

    return 0;
}

