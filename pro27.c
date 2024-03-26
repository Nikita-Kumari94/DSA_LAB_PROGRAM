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
int count=0;

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

int palindrome(struct node * head, int count){
    int i=0,j=0;
    struct node *front, *rear;
 
    while (i != count / 2)
    {
        front = rear = head;
        for (j = 0; j < i; j++){
            front = front->next;
        }

        for (j = 0; j < count - (i + 1); j++){
            rear = rear->next;
        }
        
        if (front->data != rear->data){
            return 0;
        }
        else{
            i++;
        }
    }

    return 1;
}


void print(struct node *head)
{
    struct node *p = head;
    while (p != 0)
    {
        printf("%d ", p->data);
        p = p->next;
        count++;
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

    print(head);

    int t=palindrome(head,count);
    if(t==0)
    printf("NOT A PALINDROME");
    else
    printf("...PALINDROME...");

    return 0;
}