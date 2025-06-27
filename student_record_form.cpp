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
int main(){
    vector <Student> student;
    return 0;
}