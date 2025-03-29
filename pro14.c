#include <stdio.h>

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void reverse(int arr[], int n, int d)
{
    for (int i = n; i < (n + d) / 2; i++)
    {
        swap(&arr[i], &arr[n + d - 1 - i]);
    }
}
void rotate(int arr[], int d, int l)
{
    d = d % l;
    reverse(arr, 0, d);
    reverse(arr, d, l);
    reverse(arr, 0, l);
}

void print(int arr[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
}
int numfloor(int arr[], int n, int l, int x)
{
    for (int i = n; i < l; i++)
    {
        if (arr[i] == x)
            return i;
        else if (x < 1)
            return -1;
        else if (arr[l - 1] < x)
            return l - 1;
        else
        {
            if (arr[i] > x)
            {
                return --i;
                break;
            }
        }
    }
    return -1;
}

int peak(int arr[], int l)
{
    if (l == 1)
    {
        return 0;
    }
    if (arr[0] >= arr[1])
    {
        printf("%d ", arr[0]);
    }
    if (arr[l - 1] >= arr[l - 2])
    {
        printf("%d ", arr[l - 1]);
    }
    for (int i = 1; i < l - 2; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
        {
            return i;
        }
    }
}

int numceil(int arr[], int n, int l, int x)
{
    for (int i = n; i < l; i++)
    {
        if (arr[i] == x)
            return i;
        else if (x < 1)
            return i;
        else if (arr[l - 1] < x)
            return -1;
        else
        {
            if (arr[i] > x)
            {
                return i;
                break;
            }
        }
    }
    return -1;
}

int main()
{
    int a[] = {1, 5, 11, 13, 15, 19, 22, 37, 45, 49};
    int d, l, x, t;
    l = sizeof(a) / sizeof(a[0]);
    printf("Rotate array by how many places ? : ");
    scanf("%d", &d);
    printf("Array before rotation : \n");
    print(a, l);
    rotate(a, d, l);
    printf("\nArray after rotation : \n");
    print(a, l);
    printf("\n\nFind floor and ceil of : ");
    scanf("%d", &x);
    if (x > a[0])
    {
        t = numfloor(a, 0, l - d, x);
    }
    else
    {
        t = numfloor(a, l - d, l, x);
    }

    if (t == -1)
        printf("\nFloor Not available ");
    else
        printf("\nFloor of %d is : %d", x, a[t]);

    int s;
    if (x < a[l - 1])
    {
        s = numceil(a, l - d, l, x);
    }
    else
    {
        s = numceil(a, 0, l - d, x);
    }

    if (s == -1)
        printf("\nCeil Not available ");
    else
        printf("\nCeil of %d is : %d", x, a[s]);
    
    printf("\n\nPeak in this array : \n");
    int u = peak(a, l);
    printf("%d", a[u]);

    printf("\n\nMinimum in this array is : %d ",a[l-d]);

    return 0;
}
