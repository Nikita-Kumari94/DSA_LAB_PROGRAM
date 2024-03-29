#include <stdio.h>
#include <stdlib.h>

struct sparse
{
    int row;
    int col;
    int value;
};

void matrix(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("enter (%d,%d) element : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

struct sparse s[20];
struct sparse t[20];
struct sparse r[20];

void construct(struct sparse s[], int m, int n, int arr[m][n])
{
    s[0].row = m;
    s[0].col = n;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                continue;
            else
            {
                s[k].row = i;
                s[k].col = j;
                s[k].value = arr[i][j];
                k++;
            }
        }
    }
    s[0].value = k - 1;
}

void add(struct sparse s[], struct sparse t[], struct sparse r[])
{
    int i = 1, j = 1, k = 0;
    while (i <= s[0].value && j <= t[0].value)
    {
        if (s[i].row < t[j].row || (s[i].row == t[j].row && s[i].col < t[j].col))
        {
            r[k].row = s[i].row;
            r[k].col = s[i].col;
            r[k].value = s[i].value;
            i++, k++;
        }
        else if (s[i].row > t[j].row || (s[i].row == t[j].row && s[i].col > t[j].col))
        {
            r[k].row = t[j].row;
            r[k].col = t[j].col;
            r[k].value = t[j].value;
            j++, k++;
        }
        else
        {
            r[k].row = s[i].row;
            r[k].col = s[i].col;
            r[k].value = s[i].value + t[j].value;
            i++, j++, k++;
        }
    }
    while (i <= s[0].value)
    {
        r[k].row = s[i].row;
        r[k].col = s[i].col;
        r[k].value = s[i].value;
        i++, k++;
    }
    while (j <= t[0].value)
    {
        r[k].row = t[j].row;
        r[k].col = t[j].col;
        r[k].value = t[j].value;
        j++, k++;
    }
    r[0].row = s[0].row;
    r[0].col = s[0].col;
    r[0].value = k - 1;
}

void print(struct sparse s[])
{
    int m = s[0].row;
    int n = s[0].col;
    int l = s[0].value;
    int k = 1;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == s[k].row && j == s[k].col)
            {
                printf("%3d", s[k].value);
                k++;
            }
            else
                printf("%3d", 0);
        }
        printf("\n");
    }
}

void diaplay(int m, int n, int arr[m][n])
{
    printf("Matrix is : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m1, n1;
    int m2, n2;
    printf("Enter the dimension of 1sat matrix : ");
    scanf("%d %d", &m1, &n1);
    printf("Enter the dimension of 2nd matrix : ");
    scanf("%d %d", &m2, &n2);
    int a[m1][n1];
    int b[m2][n2];

    matrix(m1, n1, a);
    matrix(m2, n2, b);

    construct(s, m1, n1, a);
    construct(t, m2, n2, b);

    printf("1st Matrix is : \n");
    print(s);
    printf("2nd Matrix is : \n");
    print(t);
    add(s,t,r);
    printf("Addition of given matrices is : \n");
    print(r);

    return 0;
}