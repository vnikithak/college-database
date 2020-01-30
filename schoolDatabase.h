#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
//This is the student class containing data members and member functions.
//The data considered for students is name, branch, year and roll number.
class Student
{
    string name,branch;
    int year,rollno;
public:
    Student()
    {
        name=" ";
        branch=" ";
        year=0;
        rollno=0;
    }
    void inputS();
    void searchnameS();
    void searchbranchS();
    void searchyearS();
    void searchrollnoS();
    void displayallS();
    void searchS();
    void deleteFileS();
    void appendFileS();
};
//The following is a function to input a new student into the student file.
void Student::inputS()
{
    ofstream student("student.txt",ios::app);
    cout<<"\nEnter the new student's name:"<<endl;
    cin>>name;
    cin.sync();
    cout<<"\nEnter the student's branch:"<<endl;
    cin>>branch;
    cout<<"\nEnter the student's year:"<<endl;
    cin>>year;
    cout<<"\nEnter the student's Roll no:"<<endl;
    cin>>rollno;
    student<<name << ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
    student.close();
}
//The following is a function which searches and displays students who share the name which is inputted.
void Student::searchnameS()
{
    ifstream student("student.txt");
    string str;
    cout<<"\nEnter the student's name:";
    cin>>str;
    while(student>>name>>branch>>year>>rollno)
    {
        if (str==name)
        {
            cout<<"\nStudent found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Year"<<"Roll No."<<endl;
            cout<<"---------------"<<endl;
            cout<<name << ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
        }
    }
    while (student>>name)
    {
        if (str!=name)
        {
            cout<<"No student exists under that name"<<endl;
        }
    }
    cin.get();
}
//The following is a function which searches and displays students who share the branch which is inputted.
void Student::searchbranchS()
{
    ifstream student("student.txt");
    string str;
    cout<<"\nEnter the student's branch:";
    cin>>str;
    while(student>>name>>branch>>year>>rollno)
    {
        if (str==branch)
        {
            cout<<"\nStudent found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Year"<<"Roll No."<<endl;
            cout<<"---------------"<<endl;
            cout<<name << ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
        }
    }
    while (student>>branch)
    {
        if (str!=branch)
        {
            cout<<"No student exists under that branch"<<endl;
        }
    }
    cin.get();
}
//The following is a function which searches and displays students who share the year which is inputted.
void Student::searchyearS()
{
    ifstream student("student.txt");
    int y;
    cout<<"\nEnter the student's year:";
    cin>>y;
    while(student>>name>>branch>>year>>rollno)
    {
        if (y==year)
        {
            cout<<"\nStudent found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Year"<<"Roll No."<<endl;
            cout<<"---------------"<<endl;
            cout<<name<< ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
        }
    }
    while (student>>year)
    {
        if (y!=year)
        {
            cout<<"No student exists under that year"<<endl;
        }
    }
    cin.get();
}
//The following is a function which searches and displays student who has the roll number which is inputted.
void Student::searchrollnoS()
{
    ifstream student("student.txt");
    int no;
    cout<<"\nEnter the student's Roll No:";
    cin>>no;
    while(student>>name>>branch>>year>>rollno)
    {
        if (no==rollno)
        {
            cout<<"\nStudent found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Year"<<"Roll No."<<endl;
            cout<<"---------------"<<endl;
            cout<<name<< ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
        }
    }
    while (student>>rollno)
    {
        if (no!=rollno)
        {
            cout<<"No student exists under that Roll No"<<endl;
        }
    }
    cin.get();
}
//The following is a function that displays all of the students along with their respective information.
void Student::displayallS()
{
    ifstream student("student.txt");
    cout << "Entire student database"<< endl;
    cout<<name<< ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
    cout << "---------------" << endl;
    while(student>>name>>branch>>year>>rollno)
    {
        cout<<name<< ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
    }
    cin.get();
}
//The following is a search function which encompasses all of the other search functions.
void Student::searchS()
{
    int choice;
    cout << "1.Search by name" << endl;
    cout << "2.Search by branch" << endl;
    cout << "3.Search by year" << endl;
    cout << "4.Search by Roll No" << endl;
    cout << "5.Display all students" << endl;
    cin >> choice;
    switch (choice)
     {
        case 1:
            searchnameS();
            break;
        case 2:
            searchbranchS();
            break;
        case 3:
            searchyearS();
            break;
        case 4:
            searchrollnoS();
            break;
        case 5:
            displayallS();
            break;
    }
}
//The following is a function to close the student file.
void Student::deleteFileS()
{
    string dec;
    cout<<"Are you sure?[Y][N]" << endl;
    cin>>dec;
    if (dec=="y")
    {
        ofstream student("student.txt");
        cout<<"Successfully deleted."<<endl;
        student.close();
    }
}
//The following is a function to append specific student information such as name, branch, year
//or roll number of an existing student.
void Student::appendFileS()
{
    string input,newname,dec;
    ifstream student("student.txt");
    if(!student.eof())
    {
        student>>name>>branch>>year>>rollno;
    }
    cout<<"Enter the name of student:";
    cin>>input;
    if(input==name)
    {
        cout<<name << ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
        cout<<"Is this the correct student[y][n]:";
        cin>>dec;
        if(dec=="y")
        {
            cout<<"Enter the new name:";
            cin>>newname;
            name=newname;
        }
        student.close();
     }
     ofstream student2("student.txt",ios::app);
     student2<< name << ' ' <<branch<< ' ' <<year<< ' ' <<rollno<<endl;
     student2.close();
}
//This is the teacher class containing data members and member functions.
//The data considered for teachers is name, branch, and subject.
class Teacher
{
    string name,branch,subject;
public:
    Teacher()
    {
        name=" ";
        branch=" ";
        subject=" ";
    }
    void inputT();
    void searchnameT();
    void searchbranchT();
    void searchsubjectT();
    void displayallT();
    void searchT();
    void deleteFileT();
    void appendFileT();
};
//The following is a function to input a new teacher into the student file.
void Teacher::inputT()
{
    ofstream teacher("teacher.txt",ios::app);
    cout<<"\nEnter the new teacher's name:"<<endl;
    cin>>name;
    cin.sync();
    cout<<"\nEnter the teacher's branch:"<<endl;
    cin>>branch;
    cout<<"\nEnter the teacher's subject:"<<endl;
    cin>>subject;
    teacher<<name<< ' ' <<branch<< ' ' <<subject<<endl;
    teacher.close();
}
//The following is a function which searches and displays teachers who share the name which is inputted.
void Teacher::searchnameT()
{
    ifstream teacher("teacher.txt");
    string str;
    cout<<"\nEnter the teacher's name:";
    cin>>str;
    while(teacher>>name>>branch>>subject)
    {
        if (str==name)
        {
            cout<<"\nTeacher found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Subject"<<endl;
            cout<<"---------------"<<endl;
            cout<<name<< ' ' <<branch<< ' ' <<subject<<endl;
        }
    }
    while (teacher>>name)
    {
        if (str!=name)
        {
            cout<<"No teacher exists under that name"<<endl;
        }
    }
    cin.get();
}
//The following is a function which searches and displays teachers who share the branch which is inputted.
void Teacher::searchbranchT()
{
    ifstream teacher("teacher.txt");
    string str;
    cout<<"\nEnter the teacher's branch:";
    cin>>str;
    while(teacher>>name>>branch>>subject)
    {
        if (str==branch)
        {
            cout<<"\nTeacher found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Subject"<<endl;
            cout<<"---------------"<<endl;
            cout<<name<< ' ' <<branch<< ' ' <<subject<<endl;
        }
    }
    while (teacher>>branch)
    {
        if (str!=branch)
        {
            cout<<"No teacher exists under that branch"<<endl;
        }
    }
    cin.get();
}
//The following is a function which searches and displays teachers who share the subject which is inputted.
void Teacher::searchsubjectT()
{
    ifstream teacher("teacher.txt");
    string str;
    cout<<"\nEnter the teacher's subject:";
    cin>>str;
    while(teacher>>name>>branch>>subject)
    {
        if (str==subject)
        {
            cout<<"\nTeacher found" << endl;
            cout<<"Name"<< ' ' <<"Branch"<< ' ' <<"Subject"<<endl;
            cout<<"---------------"<<endl;
            cout<<name<< ' ' <<branch<< ' ' <<subject<<endl;
        }
    }
    while (teacher>>subject)
    {
        if (str!=subject)
        {
            cout<<"No teacher exists under that subject"<<endl;
        }
    }
    cin.get();
}
//The following is a function that displays all of the teachers along with their respective information.
void Teacher::displayallT()
{
    ifstream teacher("teacher.txt");
    cout << "Entire teacher database"<< endl;
    cout<<name<< ' ' <<branch<< ' ' <<subject<<endl;
    cout << "---------------" << endl;
    while(teacher>>name>>branch>>subject)
    {
        cout<<name<< ' ' <<branch<< ' ' <<subject<<endl;
    }
    cin.get();
}
//The following is a search function which encompasses all of the other search functions.
void Teacher::searchT()
{
    int choice2;
    cout << "1.Search by name" << endl;
    cout << "2.Search by branch" << endl;
    cout << "3.Search by subject" << endl;
    cout << "4.Display all teachers" << endl;
    cin >> choice2;
    switch (choice2)
     {
        case 1:
            searchnameT();
            break;
        case 2:
            searchbranchT();
            break;
        case 3:
            searchsubjectT();
            break;
        case 4:
            displayallT();
            break;
    }
}
//The following is a function to close the teacher file.
void Teacher::deleteFileT()
{
    string dec;
    cout<<"Are you sure?[Y][N]" << endl;
    cin>>dec;
    if (dec=="y")
    {
        ofstream teacher("teacher.txt");
        cout<<"Successfully deleted."<<endl;
        teacher.close();
    }
}
//The following is a function to append specific teacher information such as name, branch, or subject of an existing teacher.
void Teacher::appendFileT()
{
    string input,newname,dec;
    ifstream teacher("teacher.txt");
    if(!teacher.eof())
    {
        teacher>>name>>branch>>subject;
    }
    cout<<"Enter the name of teacher:";
    cin>>input;
    if(input==name)
    {
        cout<<name<< ' ' <<branch<< ' ' <<subject<<endl;
        cout<<"Is this the correct teacher[y][n]:";
        cin>>dec;
        if(dec=="y")
        {
            cout<<"Enter the new name:";
            cin>>newname;
            name=newname;
        }
        teacher.close();
     }
     ofstream teacher2("teacher.txt",ios::app);
     teacher2<<name<< ' ' <<branch<< ' ' <<subject<<endl;
     teacher2.close();
}
