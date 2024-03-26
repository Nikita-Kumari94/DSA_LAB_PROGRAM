/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head1=NULL;
struct node * head2=NULL;

void insert(struct node ** p, int x)
{
    struct node *temp=*p;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (temp == NULL)
    {
        *p = newnode;
    }
    
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int length(struct node * head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

struct node *MergePoint(struct node *head1, struct node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    while (len1 > len2)
    {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1)
    {
        head2 = head2->next;
        len2--;
    }
    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}


void print(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    head1->data = 1;
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1->next->data = 5;
    head1->next->next = (struct node *)malloc(sizeof(struct node));
    head1->next->next->data = 14;
    head1->next->next->next = (struct node *)malloc(sizeof(struct node));
    head1->next->next->next->data = 8;
    head1->next->next->next->next = NULL;

    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2->data = 7;
    head2->next = head1->next->next;

    printf("First Linked List :\n");
    print(head1);

    printf("Second Linked List :\n");
    print(head2);

    struct node * mp = MergePoint(head1, head2);

    if (mp != NULL){
        printf("Merge Point: %d\n", mp->data);
    }
    else{
        printf("No merge point found.\n");
    }
    return 0;
}