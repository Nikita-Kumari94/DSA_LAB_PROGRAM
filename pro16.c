/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    struct node *head, *newnode, *temp;
    head = NULL;

    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("Enter the data : ");
        scanf("%d", &newnode->data);

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0->NO,1->YES) : ");
        scanf("%d", &choice);
    }

    printf("Original list : ");
    print(head);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n\nEnter the number to be insetred at the beginning : ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    printf("\nList after insertion at the beginning : ");
    print(head);

    head = head->next;
    printf("\nList after deletion at the beginning : ");
    print(head);

    return 0;
}