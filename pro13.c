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

void print_ar(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
}

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(arr, i, largest);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  for (int i = n/2-1; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = n-1; i >= 0; i--)
  {
    swap(arr, 0, i);
    heapify(arr, i, 0);
  }
}

int main()
{
  int a[] = {21, 8, 14, 16, 35, 7};
  int n = sizeof(a) / sizeof(a[0]);

  printf("Array before sorting : \n");
  print_ar(a, n);

  heapSort(a, n);

  printf("\nArray after sorting : \n");
  print_ar(a, n);

  return 0;
}