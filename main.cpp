#include <iostream>
#include<stdlib.h>
#include "schoolDatabase.h"
using namespace std;
int menu()
{
    int choice;
    cout<<"\nEnter your choice:";
    cin>>choice;
    return choice;
}
char cmenu()
{
    char dec;
    cout<<"\nEnter s for student and t for teacher:";
    cin>>dec;
    return dec;
}
int main()
{
    int ch;
    char dec;
    Student s;
    Teacher t;
    try
    {
        dec=cmenu();
        if(dec=='s')
        {
            cout<<"\nStudent functions:";
            cout<<"\n1.Input student";
            cout<<"\n2.Search student by name";
            cout<<"\n3.Search student by branch";
            cout<<"\n4.Search student by year";
            cout<<"\n5.Search student by Roll No.";
            cout<<"\n6.Display all students";
            cout<<"\n7.Search a student";
            cout<<"\n8.Delete student file";
            cout<<"\n9.Append student file";
            cout<<"\n10.Exit";
            while(1)
            {
                ch=menu();
                switch(ch)
                {
                    case 1:
                        s.inputS();
                        break;
                    case 2:
                        s.searchnameS();
                        break;
                    case 3:
                        s.searchbranchS();
                        break;
                    case 4:
                        s.searchyearS();
                        break;
                    case 5:
                        s.searchrollnoS();
                        break;
                    case 6:
                        s.displayallS();
                        break;
                    case 7:
                        s.searchS();
                        break;
                    case 8:
                        s.deleteFileS();
                        break;
                    case 9:
                        s.appendFileS();
                        break;
                    case 10:
                        exit(1);
                }
            }
        }
        else if(dec=='t')
        {
            cout<<"\nTeacher functions:";
            cout<<"\n1.Input teacher";
            cout<<"\n2.Search teacher by name";
            cout<<"\n3.Search teacher by branch";
            cout<<"\n4.Search teacher by subject";
            cout<<"\n5.Display all teachers";
            cout<<"\n6.Search a teacher";
            cout<<"\n7.Delete teacher file";
            cout<<"\n8.Append teacher file";
            cout<<"\n9.Exit";
            while(1)
            {
                ch=menu();
                switch(ch)
                {
                    case 1:
                        t.inputT();
                        break;
                    case 2:
                        t.searchnameT();
                        break;
                    case 3:
                        t.searchbranchT();
                        break;
                    case 4:
                        t.searchsubjectT();
                        break;
                    case 5:
                        t.displayallT();
                        break;
                    case 6:
                        t.searchT();
                        break;
                    case 7:
                        t.deleteFileT();
                        break;
                    case 8:
                        t.appendFileT();
                        break;
                    case 9:
                        exit(1);
                }
            }
        }
        else
            throw "Invalid entry. Choose student[s] or teacher[t].";
    }
    catch(const char*s)
    {
        cout<<s;
    }
}
