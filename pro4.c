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
    while(count>=0){
            a[count+1]=a[count];
            count--;
        }
    printf("enter the no to be inserted at first position : ");
    scanf("%d", &t);
    a[0]=t;
    size+=1;
    printf("Array after insertion : \n");
    print_arr(a,size);

    for(int k=0; k<9; k++){
        a[k]=a[k+1];
    }
    size--;
    printf("\n");
    printf("Array after deletion : \n");
    print_arr(a, size);

    return 0;
}
