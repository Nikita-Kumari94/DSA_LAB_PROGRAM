#include <stdio.h>

int binary_search(int arr[], int num, int left, int right)
{
    if (left > right)
        return -1;
    else
    {
        int mid = (left + right) / 2;
        if (num == arr[mid])
        {
            return mid;
        }
        else if (num > arr[mid])
        {
            binary_search(arr, num, mid+1, right);
        }
        else if (num < arr[mid])
        {
            binary_search(arr, num, left, mid-1);
        }
    }
}
void swap(int arr[], int n, int i)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[n];
    arr[n] = temp;
}

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--){
        for (int j = 0; j <= i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr, j, j + 1);
            }
        }
    }
}

int main()
{
    int n, num;

    int a[] = {10, 32, 45, 9, 12, 87, 25};
    n = sizeof(a) / sizeof(a[0]);
    printf("enter the no. to be searched : ");
    scanf("%d", &num);
    bubble_sort(a, n);
    int x = binary_search(a, num, 0, n);
    if (x == -1)
    {
        printf("not present");
    }
    else
    {
        printf("found ");
    }
    return 0;
}
