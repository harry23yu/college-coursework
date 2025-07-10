#include <iostream>
#include <string>
#include <fstream>
#include "student_db.h"
using namespace std;

int main() {
    //ask user for file name
    cout << "Please type file name: ";
    string nameOfFile;
    cin >> nameOfFile;
    cout << endl;

    ifstream inputFile; //input file stream: inputFile
    inputFile.open(nameOfFile.c_str());
    int numOfStudents;
    inputFile >> numOfStudents;
    student* student = create_student_db(numOfStudents);
    populate_student_db_info(student, numOfStudents, inputFile);

    if (!(inputFile.is_open())) { //check to see if file is open
        cout << "Error opening file." << endl;
    }
    else { //if file is open, do this
        cout << "How would you like to search the list today?" << endl;
        int method;
        cout << "Press 1 for search by students' last name. 2 for search by number of unique majors. 3 for sort students by ID number. ";
        cin >> method;
        ofstream outputFile;
        outputFile.open("output.txt");
        if (method == 1) {
            string lastName;
            cout << "Enter last name: ";
            cin >> lastName;
            outputStudentsOne(student, numOfStudents, outputFile, lastName);
        }
        if (method == 2) {
            outputStudentsTwo(student, numOfStudents, outputFile);
        }
        if (method == 3) {
            outputStudentsThree(student, numOfStudents, outputFile);
        }
        outputFile.close();
    }
    
    inputFile.close();
    delete_student_db_info(student);
    return 0;
}