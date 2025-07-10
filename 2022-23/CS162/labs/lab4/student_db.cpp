#include <iostream>
#include <string>
#include "student_db.h"
using namespace std;

//Create the array based on number of students in file
student* create_student_db(int numOfStudents) {
    student* ptr = new student[numOfStudents];
    return ptr;
}

//Read through input file stream (ifstream) and stores info in a pre-allocated array of stdent that's passed in
void populate_student_db_info(student* ptr, int numOfStudents, ifstream &inputFile) {
    for (int i = 0; i < numOfStudents; i++) {
        inputFile >> ptr[i].ID;
        inputFile >> ptr[i].firstName;
        inputFile >> ptr[i].lastName;
        inputFile >> ptr[i].major;
    }
}

//Print students by last name
void outputStudentsOne(student* ptr, int numOfStudents, ofstream &outputFile, string lastName) {
    for (int i = 0; i < numOfStudents; i++) {
        if (lastName == ptr[i].lastName) {
        outputFile << ptr[i].ID << " " << ptr[i].firstName << " " << ptr[i].lastName << " " << ptr[i].major;
        }
    }
}

//Print number of unique majors
void outputStudentsTwo(student* ptr, int numOfStudents, ofstream &outputFile) {
    int uniqueMajor = numOfStudents;
    for (int i = 0; i < numOfStudents; i++) {
        for (int j = 0; j < numOfStudents; j++) {
            if((ptr[i].major == ptr[j].major) && (i != j)) {
                uniqueMajor--;
            }
        }
    }
    outputFile << uniqueMajor;
}

void outputStudentsThree(student* ptr, int numOfStudents, ofstream &outputFile) {
    for(int i = 0; i < numOfStudents - 1; i++) {
        for (int i = 0; i < numOfStudents - 1; i++) {
            if (ptr[i].ID > ptr[i+1].ID) {
                swap(ptr[i], ptr[i+1]);
            }
        }
    }
    for (int i = 0; i < numOfStudents; i++) {
        outputFile << ptr[i].ID << " " << ptr[i].firstName << " " << ptr[i].lastName << " " << ptr[i].major << endl;
    }
}

//Delete all dynamic memory
void delete_student_db_info(student* ptr) {
    delete [] ptr;
    ptr = NULL;
}