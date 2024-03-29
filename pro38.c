/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createN(struct node * a){
    int data;
    printf("Enter the data (Enter -1 if no data) : ");
    scanf("%d" , &data);
    if(data == -1){
        a = NULL;
        return a;
    }
    a = (struct node *)malloc(sizeof(struct node));
    a->data = data;
    a->left = NULL;
    a->right = NULL;
    printf("For left node of %d : ",data);
    a->left = createN(a->left);
    printf("For right node of %d : ",data);
    a->right = createN(a->right);
    return a;
}

void left_traverse(struct node* root, int level, int* maxLevel) {
    if (root == NULL) {
        return;
    }
    if (*maxLevel < level) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    left_traverse(root->left, level + 1, maxLevel);
    left_traverse(root->right, level + 1, maxLevel);
}

void leftView(struct node* root) {
    int maxLevel = 0;
    left_traverse(root, 1, &maxLevel);
}

int main() {
    struct node * root;
    struct node * tree = createN(root);
    printf("Left view of the binary tree is : ");
    leftView(tree);

    return 0;
}