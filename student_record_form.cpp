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
        cout<<"Name is "<<s.name<<endl<<"Roll number is "<<s.rollno<<endl<<"CGPA is "<<s.cgpa<<endl;
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
        cout<<endl<<" -----Student Record form -----"<<endl;
        cout<<"1. Add student " <<endl<<"2. Display all students" <<endl <<"3. Search a Student "<<endl;
        cout<<"Enter the option "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1 : add_Student(student); break;
        case 2 : display_student(student); break;
        case 3 : search_Student(student); break;
        case 4 : cout<<"Exiting Progam ..."<<endl; break;
        default : cout<<"Enter valid expression "<<endl;break;
        }
    } while (choice != 4);
    
    return 0;
}