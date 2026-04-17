#include "STUDENT.h"

int main(){
    cout << fixed << setprecision(2);
    Read_data();
    int16_t choice;
    while (true) {
    cout << R"(========================================
    Student Management System
========================================

Please choose an option:

[1] Add New Student
[2] Display All Students
[3] Search Student (by Name or ID)
[4] Delete Student
[5] Update student information
[6] Show Top Students
[7] Sort Students by Grades
[0] Exit

----------------------------------------)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1 :{
                Addstudent();
                break;
            }
            case 2 :{
                Display();
                break;
            }
            case 3 :{
                Search();
                break;
            }
            case 4 :{
                Delete_student();
                break;
            }
            case 5 :{
                Update_student();
                break;
            }
            case 6 :{
                Display_top_student();
                break;
            }
            case 7 :{
                Sort_all_student();
                break;
            }
            case 0 :{
                Write_data();
                cout << "Thank you for using Student Management System. Goodbye!\n";
                return 0;

            }
            default :{
                cout << "Invalid choice, please try again\n";
                break;
            }
        }
 
    }
}