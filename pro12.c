#include <stdio.h>

void print_ar(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
}

void merge(int arr[], int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;

    int L[n], R[m];

    for (int i = 0; i < n; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < m; j++)
        R[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n && j < m){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < m){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/ 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int a[] = {41, 16, 8, 19, 21, 10, 14};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Array before sorting : \n");
    print_ar(a, n);

    mergeSort(a, 0, n-1);

    printf("\nArray after sorting : \n");
    print_ar(a, n);

    return 0;
}
