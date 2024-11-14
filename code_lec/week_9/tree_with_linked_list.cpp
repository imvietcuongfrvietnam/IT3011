#include<stdio.h>
#include<stdlib.h>

// Khai b�o tru?c Node
typedef struct _Node Node;

// C?u tr�c d? luu danh s�ch c�c con
typedef struct _ListChildren {
    struct _ListChildren *next;
    Node *child;  
} ListChild;

// C?u tr�c c?a Node
typedef struct _Node {
    ListChild *list;  // Danh s�ch c�c con
    char name;        // T�n c?a node
} Node;

// T?o m?t node m?i
Node* makeNode(char name) {
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL) {
        printf("Error mem location\n");
        exit(1);
    }
    p->name = name;
    p->list = NULL;  // B?t d?u v?i kh�ng c� con
    return p;
}

// Th�m m?t Node con v�o m?t Node
void addChild(Node *parent, Node *child) {
    ListChild *newChild = (ListChild*)malloc(sizeof(ListChild));
    if(newChild == NULL) {
        printf("Error allocating memory for child\n");
        exit(1);
    }
    newChild->child = child;
    newChild->next = parent->list;  // Th�m v�o d?u danh s�ch
    parent->list = newChild;
}

// H�m d? in c�y (d�nh cho vi?c ki?m tra)
void printTree(Node *root, int level) {
    if(root == NULL) return;
    
    // In t�n c?a node hi?n t?i v?i m?t kho?ng l�i theo level
    for(int i = 0; i < level; i++) printf("  ");
    printf("%c\n", root->name);

    // �? quy in c�c con
    ListChild *current = root->list;
    while(current != NULL) {
        printTree(current->child, level + 1);
        current = current->next;
    }
}

// H�m preOrder cho c�y
void preOrder(Node *root) {
    if(root == NULL) return;
    printf("%c ", root->name);  // In t�n node hi?n t?i

    // Duy?t qua t?t c? c�c con c?a node hi?n t?i
    ListChild *current = root->list;
    while(current != NULL) {
        preOrder(current->child);  // �? quy cho con
        current = current->next;  // Ti?n t?i con ti?p theo
    }
}

int main() {
    // T?o c�c node trong m?ng Header
    Node* Header[10];
    Header[0] = makeNode('A');
    Header[1] = makeNode('B');
    Header[2] = makeNode('C');
    Header[3] = makeNode('D');
    Header[4] = makeNode('E');
    Header[5] = makeNode('F');
    Header[6] = makeNode('G');
    Header[7] = makeNode('H');
    Header[8] = makeNode('I');
    Header[9] = makeNode('J');

    // Th�m c�c con v�o c�c Node
    addChild(Header[0], Header[1]);
    addChild(Header[0], Header[2]);
    addChild(Header[1], Header[4]);
    addChild(Header[2], Header[5]);
    addChild(Header[5], Header[6]);
    addChild(Header[5], Header[8]);
    addChild(Header[5], Header[7]);
    addChild(Header[2], Header[9]);
    
    // In c�y b?t d?u t? node 'A'
    printf("Tree structure:\n");
    printTree(Header[0], 0);

    printf("\nPre-order traversal:\n");
    preOrder(Header[0]);  // In theo th? t? pre-order

    return 0;
}

