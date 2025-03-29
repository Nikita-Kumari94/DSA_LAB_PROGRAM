#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node* newnode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct node* Tree(int in[], int post[], int inStart, int inEnd, int* pe) {
    if (inStart > inEnd)
        return NULL;

    struct node* root = newnode(post[*pe]);
    (*pe)--;

    if (inStart == inEnd)
        return root;

    int inIndex = search(in, inStart, inEnd, root->data);

    root->right = Tree(in, post, inIndex + 1, inEnd, pe);
    root->left = Tree(in, post, inStart, inIndex - 1, pe);

    return root;
}

void preOrder(struct node * a){
    if (a != NULL){
        printf("%d " , a->data);
        preOrder(a->left);
        preOrder(a->right);
    }
}

int main(){
    int post[]={40,50,20,60,30,10};
    int in[]={40,20,50,10,60,30};
    int psize= sizeof(post)/sizeof(post[0]);
    int isize= sizeof(in)/sizeof(in[0]);
    int is=0, pe=psize-1, ie=isize-1;

    struct node* root=Tree(in, post, is, ie, &pe);

    printf("Preorder traversal of the constructed tree: ");
    preOrder(root);

    return 0;
}
