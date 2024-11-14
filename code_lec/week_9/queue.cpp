#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

typedef struct _queue {
    Node *back;
    Node *front;
} queue;

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

void initQueue(queue *s) {
    s->back = NULL;
    s->front = NULL;
}

bool isEmpty(queue *s) {
    return s->front == NULL;
}

int front(queue *q) {
    if (!isEmpty(q)) return q->front->data;
    printf("Queue is empty, no front element\n");
    return -1;  // Giá tr? d?c bi?t khi queue r?ng
}

int back(queue *q) {
    if (!isEmpty(q)) return q->back->data;
    printf("Queue is empty, no back element\n");
    return -1;  // Giá tr? d?c bi?t khi queue r?ng
}

void push(queue *q, int x) {
    Node *p = makeNode(x);
    if (!isEmpty(q)) {
        q->back->next = p;
        q->back = p;
    } else {
        q->back = p;
        q->front = p;
    }
}

void pop(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to pop\n");
        return;
    }
    Node *res = q->front;
    q->front = res->next;
    if (q->front == NULL) {
        q->back = NULL;  // C?p nh?t `back` n?u hàng d?i r?ng sau khi pop
    }
    free(res);
}

int main() {
    queue q;
    initQueue(&q);

    // Ki?m tra d?y ph?n t? vào queue
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    // Ki?m tra ph?n t? d?u và cu?i
    printf("Front element: %d\n", front(&q));  // K? v?ng 10
    printf("Back element: %d\n", back(&q));    // K? v?ng 30

    // Th?c hi?n pop
    pop(&q);
    printf("After pop, front element: %d\n", front(&q)); // K? v?ng 20

    // Th?c hi?n pop d?n khi queue r?ng
    pop(&q);
    pop(&q);
    pop(&q); // Ki?m tra pop trên queue r?ng

    printf("Is queue empty? %s\n", isEmpty(&q) ? "Yes" : "No");  // K? v?ng Yes

    return 0;
}

