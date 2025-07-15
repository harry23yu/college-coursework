/* CS261- HW1 - Program2.c*/
/* Name: Harry Yu
 * Date: 1/20/2023
 * Solution description: Ten students will have random initials and a score from 0 to 100. The minimum, 
 maximum, and average score will be calculated.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
     char initials[2];
     int score;
};

struct student* allocate() {
     /*Allocate memory for ten students*/
     struct student *ptr = (struct student*) malloc(sizeof(struct student) * 10);
     /*return the pointer*/
     return ptr;
}

void generate(struct student* students) {
     /*Generate random initials and scores for ten students. The two initial letters must be capital and must be between A and Z. 
     The scores must be between 0 and 100*/
     int i;
     srand(time(NULL));
     for (i = 0; i < 10; i++) {
          students[i].initials[0] = rand() % 26 + 'A';
          students[i].initials[1] = rand() % 26 + 'A';
          students[i].score = rand() % 101;
     }
}

void output(struct student* students) {
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
     int i;
     printf("Student initials and score: ");
     for (i = 0; i < 10; i++) {
          printf("%c %c %d, ", students[i].initials[0], students[i].initials[1], students[i].score);
     }
     printf("\n");
}

void summary(struct student* students) {
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = 100;
     int max = 0;
     float total = 0.0;
     float average = 0.0;
     int i;
     for (i = 0; i < 10; i++) {
          total = total + students[i].score;
          if (students[i].score < min) {
               min = students[i].score;
          }
          if (students[i].score > max) {
               max = students[i].score;
          }
     }
     average = total / 10;
     printf("Minimum score: %d\n", min);
     printf("Maximum score: %d\n", max);
     printf("Average score: %f\n", average);
}

void deallocate(struct student* stud) {
     /*Deallocate memory from stud*/
     /*Make sure there are no memory leaks*/
     /*If stud exists, free it*/
     if (stud) {
          free(stud);
     }
}

int main() {
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}