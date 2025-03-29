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

struct node* Tree(int in[], int pre[], int inStart, int inEnd, int* ps) {
    if (inStart > inEnd)
        return NULL;

    struct node* root = newnode(pre[*ps]);
    (*ps)++;

    if (inStart == inEnd)
        return root;

    int inIndex = search(in, inStart, inEnd, root->data);

    root->left = Tree(in, pre, inStart, inIndex - 1, ps);
    root->right = Tree(in, pre, inIndex + 1, inEnd, ps);

    return root;
}

void postOrder(struct node * a){
    if (a != NULL){
        postOrder(a->left);
        postOrder(a->right);
        printf("%d " , a->data);
    }
}

int main(){
    int pre[]={10, 20, 40, 50, 30, 60};
    int in[]={40, 20, 50, 10, 60, 30};
    int psize= sizeof(pre)/sizeof(pre[0]);
    int isize= sizeof(in)/sizeof(in[0]);
    int is=0, ps=0, pe=psize-1, ie=isize-1;

    struct node* root=Tree(in, pre, is, ie, &ps);

    printf("Postorder traversal of the constructed tree: ");
    postOrder(root);

    return 0;
}
