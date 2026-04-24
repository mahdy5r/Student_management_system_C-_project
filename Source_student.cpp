#include "STUDENT.h"
// using namespace std
vector <student> students;
const vector <string> name_sub = {"Arabic", "English", "Math", "Physics", "Chemistry"};

//=====================================================================
void Addstudent (){
    student st;

    cout << "Enter the student's name :\n";
    cin.ignore(numeric_limits<streamsize>::max() , '\n');
    getline(cin , st.Name);

    cout << "Enter the student's ID :\n";
    int32_t id;
    while (true){
        if (!(cin >> id)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, enter a number : ";
            continue;
        }

        if (id > 0){
            st.ID = static_cast <uint32_t> (id);
            if (ID_exists(st.ID)){
            cout << "ID already exists, try another one: ";
            continue;
            }
            break;
        }else{
            cout << "Error in ID (must be positive number): ";
        }
    }
    st.grade_sub.clear();

    Data_sub (st);
   
    students.push_back(st);
}
//=====================================================================
bool ID_exists (const uint32_t id){
    for (const auto& st : students){
        if (id == st.ID){
            return true;
        }
    }
    return false;

}
//=====================================================================
void Data_sub (student &st){

    for (size_t i = 0 ; i < name_sub.size() ; i++){

        cout << "Enter grade for " << name_sub[i] << " (0 - 100): ";
        double grade;

        while (true){
            if (!(cin >> grade)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max() , '\n');
                cout << "Invalid input, enter a number: ";
                continue;   
            }

            if(grade >= 0 && grade <=100){
            break;
        }else{
            cout << "Please enter a valid grade between 0 and 100: ";
        }
    }
        st.grade_sub.push_back(grade);

    }
    
}
//=====================================================================
//=====================================================================
void print_Data_sub (const student& st){  
    if (name_sub.size() != st.grade_sub.size()){
        cout << "Error in student data\n";
        return;
    } 
    double sum_grades = 0.0;
    
    for (size_t i = 0 ; i < name_sub.size() ; i++){
        cout << name_sub[i] << " : " << st.grade_sub[i] << endl;
        
        sum_grades += st.grade_sub[i];
        
    }
    double avg = (sum_grades/name_sub.size());
    double percent = (sum_grades/(name_sub.size() * 100.0)) * 100;
    cout << "Total grades :  " << sum_grades << endl ;
    cout << "average grades :  " << avg << endl ;
    cout << "Percentage of total grades :  " << percent << "%" << endl ;
    cout << "========================================\n";
}

//=====================================================================
void Display(){
    for (const auto& st : students){

        PrintStudent(st);

    }
}
//=====================================================================
string normalize(string s){
    for (auto &c : s){
        c = tolower(static_cast <unsigned char> (c));
    }
    return s;
}
//=====================================================================
void Read_data (){
    ifstream read ("Student_data.txt");

    if (!read){
        cout << "Error Opening file.\n";
        return;
    }

    student st;

    students.clear();
    
    while (getline(read,st.Name)){

        read >> st.ID;

        read.ignore(numeric_limits<streamsize>::max() , '\n');

        st.grade_sub.clear();

        for (size_t i = 0 ; i < name_sub.size() ; i++){

            double grade;

            if (!(read >> grade)){
                cout << "Error reading grades\n";
                return;
            }
            st.grade_sub.push_back(grade);
        }

        read.ignore(numeric_limits<streamsize>::max() , '\n');

        students.push_back(st);
    }
  
}
//=====================================================================
void Write_data (){
    
    sort(students.begin() , students.end() , [](const student& a , const student& b){
        auto na = normalize(a.Name);
        auto nb = normalize(b.Name);
        return ((na < nb) || ((na == nb) && (a.ID < b.ID)));
    });

    ofstream write("Student_data.txt");

    if (!write){
        cout << "Error opening file for writing\n";
        return;
    }

    for (const auto& st : students){

        write << st.Name << '\n';
        write << st.ID << '\n';
        for (size_t i = 0 ; i < st.grade_sub.size() ; i++){
            write << st.grade_sub[i];
            if (i != st.grade_sub.size() - 1){
                write << " ";
            }
        }
        write << '\n';
    }


}

//=====================================================================
void Search (){
    bool found = false;
    cout << R"(How you want to search:
[1] By name.
[2] By ID.

Enter your choice: )";

    uint16_t choice;
    cin >> choice;
    cout << '\n';

    switch (choice){
        case 1 :{
            cout << "Enter the student's name :\n";
            string s;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin , s);
            for (size_t i = 0 ; i < students.size() ; i++){
                if (students[i].Name == s){
                    found = true;
                    PrintStudent(students[i]);

                }

            }

            if (!found){
                cout << "Student not found\n";
            }
            break;
        }

        case 2 : {
            cout << "Enter the student's ID :\n";
            uint32_t n;
            cin >> n;
            for (size_t i = 0 ; i < students.size() ; i++){
                if (students[i].ID == n){
                    found = true;
                    PrintStudent(students[i]);
                    break;
                } 
            }

            if (!found){
                cout << "Student not found\n";
            }
            break;

            }

        default :{
            cout << "Invalid choice, please try again\n";
            break;
        }
        
    }
}
//=====================================================================
//=====================================================================
void Delete_student (){
    bool found = false;
    cout << "Enter the student ID you want to delete : \n";
    uint32_t n;
    cin >> n;
    for (size_t i = 0 ; i < students.size() ; i++){
        if (students[i].ID == n){
            found = true;
            students.erase(students.begin()+i);
            cout << "The student was successfully removed.\n";
            break;
        }
    }

    if (!found){
        cout << "Student not found\n";
    }


}
//=====================================================================
//=====================================================================
void PrintStudent (const student& st){

    cout << "========================================\n";
    cout << "Student's name : " << st.Name << endl;
    cout << "Student's ID : "   << st.ID   << endl;

    cout << "grade_sub : \n";
    print_Data_sub(st);
}
//=====================================================================
//=====================================================================
void Update_student (){
    bool found = false;
    cout << "Enter the student ID you want to Update : \n";
    uint32_t n;
    cin >> n;
    for (size_t i = 0 ; i < students.size() ; i++){
        if (students[i].ID == n){
            found = true;
            Switch_Update(students[i]);
            break;
    }

}

    if (!found){
        cout << "Student not found\n";
    }
}
//=====================================================================
void Rename (student& st){
    string name;
    cout << "Enter the student's new name (current name : " << st.Name << ")\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin , name);
    st.Name = name;
    cout << "The name was successfully changed.\n";
}
//=====================================================================
void Switch_Update (student& st){
    int16_t choice;
    cout << R"(Choose what you want to edit:

1. Edit name only.
2. Edit grades only.
3. Edit name and grades.

Enter your choice: )";

    cin >> choice; 
    cout << '\n';

    switch(choice){
        case 1 : {
            Rename(st);
            break;
        }
        case 2 : {
            Update(st);
            break;
        }
        case 3 : {
            Rename(st);
            Update(st);
            break;
        }
        default :{
            cout << "Invalid choice, please try again\n";
            break;
        }
    }

}

//=====================================================================
void Update (student& st){
    if (name_sub.size() != st.grade_sub.size()){
        cout << "Error in student data\n";
        return;
    }
    cout << "Subject grades : \n\n";

    for(size_t i = 0 ; i < name_sub.size() ; i++){
        
    cout << name_sub[i] << " (current: " << st.grade_sub[i] << ")\n";
    cout << "Enter new grade for " << name_sub[i] << ": ";
    
    double new_grade;
    
    while (true){
        if (!(cin >> new_grade)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            cout << "Invalid input, enter a number: ";
            continue;   
        }
    
        if(new_grade >= 0 && new_grade <=100){
            break;
        }else{
            cout << "Please enter a valid grade between 0 and 100: ";
        }
    }
    st.grade_sub[i] = new_grade;
    }

    cout << "The data was successfully changed.\n";
}


void Display_top_student (){
    vector <pair<double,int>> ranking ;

    for (size_t i = 0 ; i < students.size() ; i++){
        ranking.push_back({Sum_grade(students[i]) , i});
    }

    sort(ranking.begin() , ranking.end() , [](const auto& a , const auto& b ){
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);}
    );

    
    if (students.size() <= 3){
        cout << "Top students : \n";
        for (size_t i = 0 ; i < students.size() ; i++){
            PrintStudent(students[ranking[i].second]);
        }
    }
    else if (students.size() > 3){
        cout << "Top three students : \n";
        for (size_t i = 0 ; i < 3 ; i++){
            PrintStudent(students[ranking[i].second]);
        }
    }
 
}

double Sum_grade (const student& st){
    double sum_grade = 0.0;
     for (size_t i = 0 ; i < st.grade_sub.size() ; i++){
        sum_grade += st.grade_sub[i];
     }
     return sum_grade;
}


void Sort_all_student (){
    vector <pair<double,int>> ranking ;

    for (size_t i = 0 ; i < students.size() ; i++){
        ranking.push_back({Sum_grade(students[i]) , i});
    }

    sort(ranking.begin() , ranking.end() , [](const auto& a , const auto& b ){
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    });

    
    cout << "Top three students : \n";

        for (size_t i = 0 ; i < students.size() ; i++){
            PrintStudent(students[ranking[i].second]);
        }
 
}