/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head;

struct node * insert(int x)
{
    struct node *temp=head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (temp == 0)
    {
        head = newnode;
    }
    
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
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

    insert(4);
    insert(8);
    insert(2);
    insert(11);
    insert(3);
    insert(9);
    insert(5);

    print(head);

    int n;
    printf("enter the nth node from last : ");
    scanf("%d",&n);

    struct node *fast, *slow;
    slow=head;
    fast=head;
    
    while(n){
        fast=fast->next;
        n--;
    }
    while(fast!=0){
        fast=fast->next;
        slow=slow->next;
    }
    printf("%d ",slow->data);

    return 0;
}