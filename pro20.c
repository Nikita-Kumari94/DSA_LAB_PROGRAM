/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

void print(struct node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

struct node* reverse(struct node *head){
    struct node *prenode, *currnode, *nextnode=NULL;
    prenode=NULL;
    currnode=head;
    while(currnode!=0){
        nextnode=currnode->next;
        currnode->next=prenode;
        prenode=currnode;
        currnode=nextnode;
    }
    head=prenode;
    return head;
}

int main() {
    struct node * head, *newnode, *temp;
    head=0;
    int n,num, flag=0;
    printf("Enter the no of data: ");
    scanf("%d", &n);

    printf("Enter the data: ");
    while(n){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        scanf("%d", &newnode->data);
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        n--;
    }
    printf("List is : ");
    print(head);
    
    head=reverse(head);
    printf("\nReversed List is : ");
    print(head);
    return 0;
}