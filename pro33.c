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

int height(struct node * root){
    if(root==NULL)
    return 0;
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
        return (lheight+1);
        else
        return (rheight+1);
    }
}

int main(){
    struct node * root;
    struct node * tree = createN(root);
    int h=height(tree);
    printf("\nHeight of tree is : %d",h);
    
    return 0;
}
