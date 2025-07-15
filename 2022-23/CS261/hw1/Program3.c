/* CS261- HW1 - Program3.c*/
/* Name: Harry Yu
 * Date: 1/20/2023
 * Solution description: An array will have 20 random numbers. The array will then be 
 sorted in ascending order.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n) {
    /*Sort the array of integers of length n*/ 
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (number[j] > number[j+1]) {
                int temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }    
}

int main() {
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int* ptr;
    int i, j, k;
    srand(time(NULL));
    /*Allocate memory for an array of n integers using malloc.*/
    ptr = (int*)malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    for (i = 0; i < n; i++) {
        ptr[i] = rand();
    }
    /*Print the contents of the array.*/
    printf("The numbers in the array are: ");
    for (j = 0; j < n; j++) {
        printf("%d, ", ptr[j]);
    }
    printf("\n");
    /*Pass this array along with n to the sort() function of part a.*/
    sort(ptr, n);
    /*Print the contents of the array.*/    
    printf("The numbers in the sorted array are: ");
    for (k = 0; k < n; k++) {
        printf("%d, ", ptr[k]);
    }
    printf("\n");

    return 0;
}