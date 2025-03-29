#include <stdio.h>

int main() {
  int n, num, rev= 0, rem;
    printf("Enter the no. to be checked : ");
    scanf("%d", &n);
    num = n;

    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    if (num == rev)
        printf("%d is a palindrome", num);
    else
        printf("%d is not a palindrome", num);
    return 0;
}
