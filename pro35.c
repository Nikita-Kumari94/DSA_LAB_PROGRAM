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

struct node * LCA(struct node * root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    
    if (root->data == n1 || root->data == n2)
    return root;
    
    struct node* llca = LCA(root->left, n1, n2);
    struct node* rlca = LCA(root->right, n1, n2);

    if (llca && rlca)
        return root;
    
    return (llca != NULL) ? llca : rlca;
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

    int n1, n2;
    printf("\nEnter the first no. :");
    scanf("%d",&n1);
    printf("Enter the second no. :");
    scanf("%d",&n2);
    struct node * lca = LCA(tree, n1, n2);

    if (lca != NULL)
        printf("\nLCA of %d and %d is %d\n", n1, n2, lca->data);
    else
        printf("\nNot present in the tree\n");

    return 0;
}
