/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node * head;

void print(struct node * head){
    struct node* p=head;
    printf("List in reverse order : \n");
    while(p->next!=0){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("%d ", p->data);
    printf("\n");
    printf("List in original order : \n");
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->prev;
    }
    printf("\n");
}

struct node * getnode(int x){
    struct node * newnode= (struct node *) malloc (sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=x;
    return newnode;
}
void create(){
    int choice=1;
    while(choice){
        int x;
        printf("Enter the data : ");
        scanf("%d", &x);
        struct node* newnode= getnode(x);
        if(head==NULL){
            head= newnode;
        }
        else{
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
        }

        printf("enter 1 for continue... 0 for exit : ");
        scanf("%d", &choice);
    }
}

int main(){
    create();
    print(head);
    return 0;
}