/* 23/CS/283
NIKITA KUMARI */

#include <stdio.h>

int main(){

    float a[6][6]={0};

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("Enter the marks of student %d in subject %d : ", i+1, j+1);
            scanf("%f",&a[i][j]);
            a[i][5]+=a[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            a[5][i]+=a[j][i];
        }
        a[5][i]/=5;
    }

    for(int i=0; i<5; i++){
        printf("Sum of marks of student %d : %0.2f \n", i+1, a[i][5]);
    }
    for(int i=0; i<5; i++){
        printf("Average of marks in subject %d : %0.2f \n", i+1, a[5][i]);
    }

    return 0;
}