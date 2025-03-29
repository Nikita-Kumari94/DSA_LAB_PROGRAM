#include <stdio.h>

void next_gr(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int ng = -1;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ng = arr[j];
                break;
            }
        }
        printf("Next greater element to the right of %d is %d\n", arr[i], ng);
    }
}

int main() {
    int arr[] = {4, 2, 11, 5, 8, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    next_gr(arr, n);
    return 0;
}
