#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Student{
    string name;
    int rollno;
    float cgpa;
};
void add_Student(vector <Student>&student){
    Student s;
    cout<<"Enter the name of student"<<endl;
    cin>>s.name;
    cout<<"Enter the roll number of student"<<endl;
    cin>>s.rollno;
    cout<<"Enter the cgpa of student"<<endl;
    cin>>s.cgpa;
    student.push_back(s);
}
void display_student(const vector <Student> & student){
    cout<<"Student Records"<<endl;
    for(const auto& s : student){
        cout<<"Name is "<<s.name<<endl<<"Roll number is "<<s.rollno<<"CGPA is "<<s.cgpa<<endl;
    }
};
void search_Student(const vector <Student>& student){
    int Rollno;
    cout<<"Enter the Roll number of Student"<<endl;
    cin>>Rollno;
    for(const auto& s: student){
        if (s.rollno == Rollno)
        {
            cout<<"Student Name is "<<s.name<<endl<<"Student Roll number is "<<s.rollno<<endl<<"Student CGPA is "<<s.cgpa<<endl;
        }else{
            cout<<"Student does not exist in data base"<<endl;
        }
        
    }
};

int main(){
    vector <Student> student;
    int choice;
    do
    {
        cout<<"/n -----Student Record form -----/n";
        cout<<"1. Add student /n 2. Display all students /n 3. Search a Student /n";
        cout<<"Enter the option /n";
        cin>>choice;
        switch (choice)
        {
        case 1 : add_Student(student); break;
        case 2 : display_student(student); break;
        case 3 : search_Student(student); break;
        case 4 : cout<<"Exiting Progam .../n"; break;
        default : cout<<"Enter valid expression /n";break;
        }
    } while (choice != 4);
    
    return 0;
}