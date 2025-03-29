#include <stdio.h>

int main(){
    int flag=0;
    int n, i, num;

    int a[]={10, 32, 45, 9, 12, 87, 25};
    n= sizeof(a)/sizeof(a[0]);
    printf("enter the no. to be searched : ");
    scanf("%d", &num);
    for(i=0; i<n; i++){
        if(num==a[i]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf(" Found!!! at position %d ", i+1);
    }
    else
    printf(" Not Found ");
    return 0;
}
