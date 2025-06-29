#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Student
{
    string name;
    int rollno;
    float cgpa;
};
const string data_file = "student.txt";

void save_Student_to_file(const Student &s)
{

    ofstream out(data_file, ios::app);
    if (!out)
    {
        cout << " Cannot open file for writing!" << endl;
        return;
    }
    out << s.name << "," << s.rollno << "," << s.cgpa << endl;
    out.close();
}
void load_student_data_from_file(vector<Student> &students)
{
    ifstream in(data_file, ios::app);
    if (!in)
        return;
    string line;
    while (getline(in, line))
    {
        size_t p1 = line.find(',');
        size_t p2 = line.rfind(',');
        if (p1 == string::npos || p2 == string ::npos || p1 == p2)
            continue;
        Student s;
        s.name = line.substr(0, p1);
        s.rollno = stoi(line.substr(p1 + 1, p2 - p1 - 1));
        s.cgpa = stof(line.substr(p2 + 1));
        students.push_back(s);
    }
}
void add_Student(vector<Student> &student)
{
    Student s;
    cout << "Enter the name of student" << endl;
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter the roll number of student" << endl;
    cin >> s.rollno;
    cin.ignore();
    cout << "Enter the cgpa of student" << endl;
    cin >> s.cgpa;
    student.push_back(s);
    cout << "Student added & written to file!" << endl;
    save_Student_to_file(s);
}
void display_student(const vector<Student> &student)
{
    if (student.empty())
    {
        cout << "No student record  " << endl;
        return;
    }

    cout << "Student Records" << endl;
    for (const auto &s : student)
    {
        cout << "Name is " << s.name << endl
             << "Roll number is " << s.rollno << endl
             << "CGPA is " << s.cgpa << endl;
    }
};
void search_Student(const vector<Student> &student)
{
    int Rollno;
    cout << "Enter the Roll number of Student" << endl;
    cin >> Rollno;
    cin.ignore();
    bool found = false;
    for (const auto &s : student)
    {
        if (s.rollno == Rollno)
        {
            cout << "Student Name is " << s.name << endl
                 << "Student Roll number is " << s.rollno << endl
                 << "Student CGPA is " << s.cgpa << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Student with roll number " << Rollno << " not found." << endl;
    }
};

int main()
{
    vector<Student> student;
    load_student_data_from_file(student);
    int choice;
    do
    {
        cout << endl
             << " -----Student Record form -----" << endl;
        cout << "1. Add student " << endl
             << "2. Display all students" << endl
             << "3. Search a Student " << endl;
        cout << "Enter the option " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_Student(student);
            break;
        case 2:
            display_student(student);
            break;
        case 3:
            search_Student(student);
            break;
        case 4:
            cout << "Exiting Progam ..." << endl;
            break;
        default:
            cout << "Enter valid expression " << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}