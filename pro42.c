/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>
#include <stdlib.h>

int top=-1;
int n=10;
void push(int arr[],int l){
    if(top==n){
        printf("Stack Overflow...\n");
    }
    else{
        top+=1;
        arr[top]=l;
    }
}
void display(int arr[]){
    for(int i=0; i<=top; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void pop(int arr[]){
    if(top==-1)
        printf("Stack Underflow...\n");
    else{
        int x=arr[top];
        printf("\nDeleted value is : %d\n",x);
        top-=1;
    }
}

int main(){
    int a[10]={0};
    int choice;
    printf("1.Push\n2.Pop\n3.Dispaly\n4.Exit\nEnter your choice :");
    scanf("%d",&choice);
    while(choice!=4){
        if(choice==1){
            int num;
            printf("Enter the data to be pushed : ");
            scanf("%d",&num);
            push(a,num);
        }
        else if(choice==2){
            pop(a);
        }
        else if(choice==3){
            printf("\nElements in stack are: ");
            display(a);
        }
        else if(choice==4)
        break;

        else
        printf("Invalid choice..");
        
    printf("\n1.Push\n2.Pop\n3.Dispaly\n4Exit\nEnter your choice :");
    scanf("%d",&choice);
    }
    return 0;
}
