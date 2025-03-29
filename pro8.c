#include <stdio.h>

void swap(int arr[], int n, int i)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[n];
    arr[n] = temp;
}

void bubble_sort(int arr[],int n){
    for(int i=n-1; i>=1;i--){
        for(int j=0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }

}

int main()
{
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

   bubble_sort(a,n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
