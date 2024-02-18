/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>

void swap(int arr[], int n, int i)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[n];
    arr[n] = temp;
}

void selection_sort(int arr[], int n)
{
    int step = 0;
    for (step = 0; step <= n-2; step++)
    {
        int min = step;
        for (int i = step; i < n; i++)
        {
            if (arr[min] > arr[i])
            {
                min=i;
            }
        }
        swap(arr,step,min);
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

   selection_sort(a,n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}