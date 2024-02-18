/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>

void print_arr(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
}

void swap(int arr[], int n, int i)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[n];
    arr[n] = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start< end)
        {
            swap(a, start, end);
        }
    }
    swap(a, lb, end);
    return end;
}

void Quick_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        Quick_sort(a, lb, loc - 1);
        Quick_sort(a, loc + 1, ub);
    }
}

int main(){

    int a[]={12, 45, 24, 11, 19, 11, 8};
    int n= sizeof(a) / sizeof(a[0]);
    printf(" Before sorting : \n ");
    print_arr(a,n);
    Quick_sort(a, 0, n-1);
    printf("\n After sorting : \n ");
    print_arr(a, n);
    return 0;
}