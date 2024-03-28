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

int max(int a, int b){
    return (a > b) ? a : b;
}

int diameter(struct node* tree)
{
    if (tree == NULL) return 0;

    int lh = height(tree->left);
    int rh = height(tree->right);

    int ldia = diameter(tree->left);
    int rdia = diameter(tree->right);
  
    return max(lh + rh + 1, max(ldia, rdia));
}

void inOrder(struct node * a){
    if (a != NULL){
        inOrder(a->left);
        printf("%d " , a->data);
        inOrder(a->right);
    }
}

int main(){
    struct node* root;
    struct node * tree = createN(root);
    printf("\nINORDER : ");
    inOrder(tree);
    printf("\nDiameter of the given binary tree is %d\n", diameter(tree));
 
    return 0;
}