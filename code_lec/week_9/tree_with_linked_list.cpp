#include<stdio.h>
#include<stdlib.h>

// Khai báo tru?c Node
typedef struct _Node Node;

// C?u trúc d? luu danh sách các con
typedef struct _ListChildren {
    struct _ListChildren *next;
    Node *child;  
} ListChild;

// C?u trúc c?a Node
typedef struct _Node {
    ListChild *list;  // Danh sách các con
    char name;        // Tên c?a node
} Node;

// T?o m?t node m?i
Node* makeNode(char name) {
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL) {
        printf("Error mem location\n");
        exit(1);
    }
    p->name = name;
    p->list = NULL;  // B?t d?u v?i không có con
    return p;
}

// Thêm m?t Node con vào m?t Node
void addChild(Node *parent, Node *child) {
    ListChild *newChild = (ListChild*)malloc(sizeof(ListChild));
    if(newChild == NULL) {
        printf("Error allocating memory for child\n");
        exit(1);
    }
    newChild->child = child;
    newChild->next = parent->list;  // Thêm vào d?u danh sách
    parent->list = newChild;
}

// Hàm d? in cây (dành cho vi?c ki?m tra)
void printTree(Node *root, int level) {
    if(root == NULL) return;
    
    // In tên c?a node hi?n t?i v?i m?t kho?ng lùi theo level
    for(int i = 0; i < level; i++) printf("  ");
    printf("%c\n", root->name);

    // Ð? quy in các con
    ListChild *current = root->list;
    while(current != NULL) {
        printTree(current->child, level + 1);
        current = current->next;
    }
}

// Hàm preOrder cho cây
void preOrder(Node *root) {
    if(root == NULL) return;
    printf("%c ", root->name);  // In tên node hi?n t?i

    // Duy?t qua t?t c? các con c?a node hi?n t?i
    ListChild *current = root->list;
    while(current != NULL) {
        preOrder(current->child);  // Ð? quy cho con
        current = current->next;  // Ti?n t?i con ti?p theo
    }
}

int main() {
    // T?o các node trong m?ng Header
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

    // Thêm các con vào các Node
    addChild(Header[0], Header[1]);
    addChild(Header[0], Header[2]);
    addChild(Header[1], Header[4]);
    addChild(Header[2], Header[5]);
    addChild(Header[5], Header[6]);
    addChild(Header[5], Header[8]);
    addChild(Header[5], Header[7]);
    addChild(Header[2], Header[9]);
    
    // In cây b?t d?u t? node 'A'
    printf("Tree structure:\n");
    printTree(Header[0], 0);

    printf("\nPre-order traversal:\n");
    preOrder(Header[0]);  // In theo th? t? pre-order

    return 0;
}

