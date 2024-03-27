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

void inOrder(struct node * a){
    if (a != NULL){
        inOrder(a->left);
        printf("%d " , a->data);
        inOrder(a->right);
    }
}

int main(){
    struct node * root;
    struct node * tree = createN(root);
    printf("\nINORDER TRAVERSAL : \n");
    inOrder(tree);
    return 0;
}
