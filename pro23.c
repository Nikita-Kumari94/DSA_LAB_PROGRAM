/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = 0;

void create()
{
    struct node *newnode, *temp;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("enter data: ");
        scanf("%d", &newnode->data);
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        temp->next = head;
        printf("enter 1 for continue... 0 for exit : ");
        scanf("%d", &choice);
    }
}

void print(struct node *head)
{
    struct node *p = head;
    if (head == 0)
    {
        printf("empty...");
    }
    else
    {
        while (p->next != head)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("%d ", p->data);
    }
}

int main()
{
    create();
    print(head);
    return 0;
}