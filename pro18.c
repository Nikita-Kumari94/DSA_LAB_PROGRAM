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
    head = 0;
    int n, t, pos, pos2;
    printf("Enter the no of data: ");
    scanf("%d", &n);
    t = n;
    printf("Enter the data: ");
    while (n)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
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
        n--;
    }
    printf("List is : ");
    print(head);

    // ********************INSERTION AT GIVEN POSITION**************************
    printf("\n\nEnter the postion for insertion : ");
    scanf("%d", &pos);

    if (pos > t)
    {
        printf("INVALID !!");
    }
    else if (pos == 1)
    {
        printf("Enter the data for insertion : ");
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
        printf("List after insertion : ");
        print(head);
    }
    else
    {
        printf("Enter the data for insertion : ");
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        int i = 1;
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;

        printf("List after insertion : ");
        print(head);
    }
    t++;

    //************************DELETION AT GIVEN POSITION*********************************
    printf("\n\nEnter the postion for deletion : ");
    scanf("%d", &pos2);

    if (pos2 > t)
    {
        printf("INVALID !!");
    }
    else if (pos2 == 1)
    {
        head = head->next;
        printf("List after deletion : ");
        print(head);
    }
    else if (pos2 == t)
    {
        int i = 1;
        temp = head;
        while (i < pos2 - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = NULL;
        printf("List after deletion : ");
        print(head);
    }
    else
    {
        int i = 1;
        temp = head;
        while (i < pos2 - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;

        printf("List after deletion : ");
        print(head);
    }

    return 0;
}