#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head1=NULL;
struct node * head2=NULL;
struct node * headnew=NULL;

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

struct node * merge(struct node * head1, struct node * head2){
    struct node * first=head1;
    struct node * second=head2;
    struct node * temp=headnew;
    

    while(first!=NULL && second!=NULL){
        if(first->data <= second->data){
            if(headnew==NULL){
                headnew=first;
                temp=headnew;
            }
            else{
                temp->next =first;
                temp=temp->next;
            }
            first=first->next;
        }
        else{
            if(headnew==NULL){
                headnew=second;
                temp=headnew;
            }
            else{
                temp->next =second;
                temp=temp->next;
            }
            second= second->next;
        }
    }
    if(first!=NULL){
        temp->next=first;
    }
    if(second!=NULL){
        temp->next=second;
    }
    return headnew;
}


int main(){
    int choice=1;
    printf("enter the elements of 1st linked list in ascending order : \n");
    while(choice){
        int num;
        printf("enter the data : ");
        scanf("%d", &num);
        insert(&head1 , num);
        printf("want to continue... 0 or 1 : ");
        scanf("%d",&choice);
    }

    int ch=1;
    printf("enter the elements of 2nd linked list in ascending order : \n");
    while(ch){
        int num;
        printf("enter the data : ");
        scanf("%d", &num);
        insert(&head2 , num);
        printf("want to continue... 0 or 1 : ");
        scanf("%d",&ch);
    }
    printf("First linked list : \n");
    print(head1);
    printf("Second linked list : \n");
    print(head2);
    headnew=merge(head1, head2);
    printf("Merged sorted linked list : \n");
    print(headnew);
    return 0;
}
