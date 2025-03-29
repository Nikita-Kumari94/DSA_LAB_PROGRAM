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
    int n, num, flag = 0;
    printf("Enter the no of data: ");
    scanf("%d", &n);

    printf("Enter the data: ");
    while (n)
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        newnode->next=NULL;
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

    printf("\nEnter the no to be searched : ");
    scanf("%d", &num);

    temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            printf("Found !!");
            flag = 1;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (flag == 0)
        printf("NOT FOUND !!");
    return 0;
}
