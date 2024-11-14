#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

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

bool checkSyntax(char *input) {
    stack s;
    initStack(&s);
    char sym;
    int len = strlen(input);
    
    for (int i = 0; i < len; i++) {
        switch (input[i]) {
            case '[':
            case '{':
            case '(':
                push(&s, input[i]);
                break;
            default:
                if (isEmpty(&s)) return false;
                sym = top(&s);
                pop(&s);
                if ((sym == '(' && input[i] == ')') || 
                    (sym == '[' && input[i] == ']') || 
                    (sym == '{' && input[i] == '}')) {
                    break;
                } else {
                    return false;
                }
        }
    }
    return isEmpty(&s);
}

int main() {
    char *input = "{}{}{}{}{}{}{}";
    if (checkSyntax(input)) 
        printf("True\n");
    else 
        printf("False\n");
    return 0;
}

