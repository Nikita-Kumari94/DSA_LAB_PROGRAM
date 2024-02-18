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

int main()
{

    int a[10] = {4, 6, 12, 19, 11};
    int t, pos, pos2, size;

    int i = 0;
    int count = 0;
    while (a[i] != 0)
    {
        count++;
        i++;
    }
    size = count;

    printf("Array before insertion : \n");
    print_arr(a, size);
    printf("\n");
    printf("Enter the position of the element where you want to insert : ");
    scanf("%d", &pos);
    while (count >= pos - 1)
    {
        a[count + 1] = a[count];
        count--;
    }
    printf("Enter the no to be inserted : ");
    scanf("%d", &t);
    a[pos - 1] = t;
    size += 1;
    printf("Array after insertion : \n");
    print_arr(a, size);
    printf("\n");
    printf("Enter the position of the element where you want to delete : ");
    scanf("%d", &pos2);

    for (int j = pos2 - 1; j < size - 1; j++)
    {
        a[j] = a[j + 1];
    }
    size--;
    printf("Array after deletion : \n");
    print_arr(a, size);

    return 0;
}