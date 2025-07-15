/* CS261- HW1 - Program4.c*/
/* Name: Harry Yu
 * Date: 1/20/2023
 * Solution description: This is very similar to program 2, except that the 
 students will be sorted based on their initials.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student {
    char initials[2];
    int score;
};

void sort(struct student* students, int n) {
    /*Sort n students based on their initials*/
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if (students[j].initials[0] != students[j+1].initials[0]) {
                if (students[j].initials[0] > students[j+1].initials[0]) {
                    char temp = students[j].initials[0];
                    students[j].initials[0] = students[j+1].initials[0];
                    students[j+1].initials[0] = temp;
                    char temp2 = students[j].initials[1];
                    students[j].initials[1] = students[j+1].initials[1];
                    students[j+1].initials[1] = temp2;
                    int tempScore = students[j].score;
                    students[j].score = students[j+1].score;
                    students[j+1].score = tempScore;
                }
            }
            if (students[j].initials[0] == students[j+1].initials[0]) {
                if (students[j].initials[1] > students[j+1].initials[1]) {
                    char temp = students[j].initials[1];
                    students[j].initials[1] = students[j+1].initials[1];
                    students[j+1].initials[1] = temp;
                    char temp2 = students[j].initials[0];
                    students[j].initials[0] = students[j+1].initials[0];
                    students[j+1].initials[0] = temp2;
                    int tempScore = students[j].score;
                    students[j].score = students[j+1].score;
                    students[j+1].score = tempScore;
                }
            }
        }
    }
}

int main() {
    /*Declare an integer n and assign it a value.*/
    srand(time(NULL));
    int n;
    printf("How many students do you want? ");
    scanf("%d", &n);

    /*Allocate memory for n students using malloc.*/
    struct student *ptr = (struct student*) malloc(sizeof(struct student) * n);

    /*Generate random initials and scores for the n students, using rand().*/
    int i;
    for (i = 0; i < n; i++) {
        ptr[i].initials[0] = rand() % 26 + 'A';
        ptr[i].initials[1] = rand() % 26 + 'A';
        ptr[i].score = rand() % 101;
    }

    /*Print the contents of the array of n students.*/
    int j;
    printf("Student initials and score: ");
    for (j = 0; j < n; j++) {
        printf("%c %c %d, ", ptr[j].initials[0], ptr[j].initials[1], ptr[j].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(ptr, n);

    /*Print the contents of the array of n students.*/
    int k;
    printf("Sorted array of student initials and score: ");
    for (k = 0; k < n; k++) {
        printf("%c %c %d, ", ptr[k].initials[0], ptr[k].initials[1], ptr[k].score);
    }
    printf("\n");

    return 0;
}