#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *top;
};

void display(struct node *p)
{
    printf("\nElements in stack are: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int isempty(struct node *p)
{
    if (p == NULL)
        return 0;
    else
        return 1;
}

struct node *push(struct node *p, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Unable to allocate memory...");
    }
    else
    {
        newnode->data = data;
        newnode->next = p;
        p = newnode;
        printf("Push operation implemented successfully...\n");
    }
    return p;
}

struct node *pop(struct node *p)
{
    if (p == NULL)
    {
        printf("%d", 0);
    }
    else
    {
        int value = p->data;
        p = p->next;
        printf("The popped value is %d .", value);
    }
    return p;
}

int main()
{
    struct node *top, new, temp;
    top = NULL;
    int choice = 1;
    while (choice)
    {
        if (top == NULL)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data : ");
            scanf("%d", &new->data);
            new->next = NULL;
            top = new;
        }
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data : ");
            scanf("%d", &new->data);
            new->next = top;
            top = new;
        }
        printf("Do you want to continue (0->NO,1->YES) : ");
        scanf("%d", &choice);
    }

    int ch;
    printf("1.Push\n2.Pop\n3.Dispaly\n4.Exit\nEnter your choice :");
    scanf("%d", &ch);
    while (ch != 4)
    {
        if (ch == 1)
        {
            int value;
            printf("\nEnter the value to be pushed : ");
            scanf("%d", &value);
            top = push(top, value);
        }
        else if (ch == 2)
        {
            if (isempty(top) == 0)
                printf("\nEmpty stack");
            else
                top = pop(top);
            display(top);
        }
        else if (ch == 3)
        {
            display(top);
        }
        else if (ch == 4)
            break;
        else
            printf("Invalid choice..");

        printf("\n1.Push\n2.Pop\n3.Dispaly\n4Exit\nEnter your choice :");
        scanf("%d", &ch);
    }
    return 0;
}
