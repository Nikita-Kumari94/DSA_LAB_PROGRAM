#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;
};

struct QNode {
    struct TNode* treeNode;
    int horizontalDistance;
};

struct TNode* create(int data) {
    struct TNode* newNode = (struct TNode*)malloc(sizeof(struct TNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void bottomView(struct TNode* root) {
    if (root == NULL) return;

    int hashTable[100] = {0};

    struct QNode queue[100];
    int front = -1, rear = -1;

    queue[++rear] = (struct QNode){root, 0};

    while (front != rear) {
        struct QNode current = queue[++front];
        struct TNode* node = current.treeNode;
        int hd = current.horizontalDistance;

        hashTable[hd] = node->data;

        if (node->left != NULL)
            queue[++rear] = (struct QNode){node->left, hd - 1};

        if (node->right != NULL)
            queue[++rear] = (struct QNode){node->right, hd + 1};
    }

    for (int i = 0; i < 100; i++) {
        if (hashTable[i] != 0)
            printf("%d ", hashTable[i]);
    }
}

int main() {
    struct TNode* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->right = create(4);
    root->right->left = create(5);
    root->right->right = create(6);

    printf("Bottom view of the binary tree: ");
    bottomView(root);
    printf("\n");

    return 0;
}
