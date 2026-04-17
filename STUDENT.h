#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <cctype>
#include <algorithm>
using namespace std;

struct student{
    string Name;
    uint32_t ID;
    vector <double> grade_sub;
};


extern vector <student> students;
extern const vector <string> name_sub;

void print_Data_sub (const student& st);
void Data_sub (student &st);
void Update (student& st);
void PrintStudent (const student& st);
void Read_data();
double Sum_grade (const student& st);
void Write_data();
string normalize(string s);

//[1] Add New Student :
void Addstudent ();
//[2] Display All Students : 
void Display();
//[3] Search Student (by Name or ID) : 
void Search();
//[4] Delete Student :
void Delete_student();
// [5] Update student information :
void Update_student();
// [6] Show Top Students : 
void Display_top_student();
// [7] Sort Students by Grades :
void Sort_all_student();

#endif