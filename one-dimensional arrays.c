/*assighnment: 3 part 1
 autor: Lir Goffer, ID: 209103274*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define size_b 10
#define size_s 5
#define statsize 10
int contain(int[], int, int[], int); //cheak if the small array is a sub array of the big one
void digits(int[], int, int[]); //cheak how many times each number apper in the array
void main() {
    int i;
    int big[size_b], small[size_s];
    int statistics[statsize] = { 0 };

    printf("please enter 10 numbers:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &big[i]); //get the array

    printf("please enter 5 numbers:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &small[i]); //get the array

    printf("%d\n", contain(big, size_b, small, size_s)); //run the func

    digits(big, size_b, statistics); //run the func
    printf("statistics big:");
    for (i = 0; i < statsize; i++) {
        printf("%3d", statistics[i]);
    }
    printf("\n");
 
    digits(small, size_s, statistics); //run the func
    printf("statistics small:");
    for (i = 0; i < statsize; i++) {
        printf("%3d", statistics[i]);
    }
}


int contain(int big[], int size_b1, int small[], int size_s1) {
    int i, j;
    int bool, k;
    for (i = 0; i < size_b; i++) { //run the big array
        bool = 1;
        if (big[i] == small[0]) { //if values are the same
            k = 1;
            for (j = i + 1; j < size_b; j++) { //run the small array
                if (k >= size_s - 1) { 
                    break;
                }
                if (big[j] != small[k]) { //if values are the same
                    bool = 0;
                    break;
                }
                k++;
            }
            if (bool == 1) {
                return i; //return the number of the index that start the sub array
            }
        }
    }
    return -1; //if there is not sub array
}

void digits(int arr[], int size, int statistics[]) {
    int i, j;
    int num, count;
    for (j = 0; j < 10; j++) { //from 1-10 check every number
        count = 0;
        for (i = 0; i < size; i++) {  //run the array
              num = arr[i];
              if (num == 0 && j == 0) { //in case of zero
                  count++;
              }
             while (num!= 0) {
                if (num % 10 == j) {
                    count++; //count how much times every number appear
                }
                num /= 10;
            }
            statistics[j] = count; //put the amount of the appearance in the stat array
        } 
    }
  }