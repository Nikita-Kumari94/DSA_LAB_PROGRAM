/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>

void print_arr(int ar[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", ar[i]);
    }
}

int main(){

    int a[10]={4, 6, 12, 19, 11};
    int t, size;
    
    int i=0;
    int count=0;
    while(a[i]!=0){
        count++;
        i++;
    }
    size=count;
    printf("Array before insertion : \n");
    print_arr(a,size);
    printf("\n");

    printf("Enter the no to be inserted at the end: ");
    scanf("%d", &t);
    a[count]=t;
    size+=1;
    printf("Array after insertion : \n");
    print_arr(a,size);
    
    a[size-1]=0;
    size--;
    printf("\nArray after deletion : \n");
    print_arr(a,size);
    
    return 0;
}