#ifndef STUDENT_DB
#define STUDENT_DB
using namespace std;

#include <iostream>
#include <string>
#include <fstream>

struct student {
    int ID;
    string firstName;
    string lastName;
    string major;
};

student* create_student_db(int numOfStudents);
void populate_student_db_info(student* ptr, int numOfStudents, ifstream &);
void outputStudentsOne(student* ptr, int numOfStudents, ofstream &outputFile, string lastName);
void outputStudentsTwo(student* ptr, int numOfStudents, ofstream &outputFile);
void outputStudentsThree(student* ptr, int numOfStudents, ofstream &outputFile);
void delete_student_db_info(student* ptr);

#endif