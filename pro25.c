/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head=NULL;

struct node * insert(int x)
{
    struct node *temp=head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (temp == 0){
        head = newnode;
    }
    
    else{
        while (temp->next != 0){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int middle(struct node * head){
    struct node * fast=head;
    struct node * slow=head;

    if(head==NULL){
    printf("EMPTY LIST !!");
    return 0;
    }
    else{
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
}

void print(struct node *head)
{
    struct node *p = head;
    while (p != 0)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){

    int choice=1;
    while(choice){
        int num;
        printf("enter the data : ");
        scanf("%d", &num);
        insert(num);

        printf("want to continue... 0 or 1 : ");
        scanf("%d",&choice);
    }
    printf("\nLinked list is : ");
    print(head);

    printf("Middle element in list is : %d\n", middle(head));
    return 0;
}