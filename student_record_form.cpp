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
int main(){
    vector <Student> student;

    return 0;
}