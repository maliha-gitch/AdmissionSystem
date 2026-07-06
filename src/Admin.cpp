#include "../include/Admin.h"

#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Assignment.h"

#include <iomanip>

using namespace std;

//==========================================
// Constructor
//==========================================

Admin::Admin()
{
    id = "ADM-2026-0001";

    name = "System Administrator";

    phone = "";

    email = "";

    password = "admin123";
}

//==========================================
// Destructor
//==========================================

Admin::~Admin()
{

}

//==========================================
// Setter
//==========================================

void Admin::setPassword(string password)
{
    this->password = password;
}

//==========================================
// Getter
//==========================================

string Admin::getPassword() const
{
    return password;
}
//==========================================
// Admin Login
//==========================================

bool Admin::login(string adminID,
                  string password)
{
    CSVManager csv;

    vector<vector<string>> admins;

    admins = csv.readAll("database/admins.csv");

    // Skip header row
    for(size_t i = 1; i < admins.size(); i++)
    {
        if(admins[i].size() < 5)
            continue;

        if(admins[i][0] == adminID &&
           admins[i][1] == password)
        {
            id = admins[i][0];
            this->password = admins[i][1];
            name = admins[i][2];
            phone = admins[i][3];
            email = admins[i][4];

            cout << "\n=========================================\n";
            cout << "         ADMIN LOGIN SUCCESSFUL\n";
            cout << "=========================================\n";
            cout << "Welcome, " << name << "!\n";
            cout << "=========================================\n";

            return true;
        }
    }

    cout << "\n=========================================\n";
    cout << "Invalid Admin ID or Password.\n";
    cout << "=========================================\n";

    return false;
}
//==========================================
// Admin Dashboard
//==========================================

void Admin::dashboard()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================================\n";
        cout << "              ADMIN DASHBOARD\n";
        cout << "====================================================\n";

        cout << "1. View All Students\n";
        cout << "2. View All Teachers\n";
        cout << "3. Search Student\n";
        cout << "4. Search Teacher\n";
        cout << "5. Approve Student\n";
cout << "6. Reject Student\n";
cout << "7. Approve Teacher\n";
cout << "8. Reject Teacher\n";
cout << "9. Remove Student\n";
cout << "10. Remove Teacher\n";
cout<<"11. Assign Teacher to Student\n";
cout << "12. View All Assignments\n";
cout << "13. Reports\n";
        cout << "0. Logout\n";

        cout << "\nEnter Choice : ";
        cin >> choice;
        cin.ignore();

switch(choice)
{
case 1:
    viewStudents();
    break;

case 2:
    viewTeachers();
    break;

case 3:
    searchStudent();
    break;

case 4:
    searchTeacher();
    break;

case 5:
    approveStudent();
    break;

case 6:
    rejectStudent();
    break;

case 7:
    approveTeacher();
    break;

case 8:
    rejectTeacher();
    break;

case 9:
    removeStudent();
    break;

case 10:
    removeTeacher();
    break;
case 11:
{
    assignTeacherToStudent();
    break;
}

case 12:
{
    Assignment assignment;
    assignment.viewAllAssignments();
    break;
}

case 13:
    reports();
    break;

case 0:
    cout << "\nAdmin Logged Out.\n";
    break;

default:
    cout << "\nInvalid Choice.\n";
}

    }while(choice!=0);
}
//==========================================
// View All Students
//==========================================

void Admin::viewStudents()
{
    CSVManager csv;

    vector<vector<string>> students =
        csv.readAll("database/students.csv");

    cout << "\n";
    cout << "=============================================================================================\n";

    cout << left
         << setw(15)<<"Student ID"
         << setw(25)<<"Name"
         << setw(15)<<"Department"
         << setw(15)<<"Phone"
         << setw(30)<<"Email"
         << setw(15)<<"Status"
         << endl;

    cout << "=============================================================================================\n";

    for(size_t i=1;i<students.size();i++)
    {
        if(students[i].size()<24)
            continue;

        cout << left
             << setw(15)<<students[i][0]
             << setw(25)<<students[i][2]
             << setw(15)<<students[i][21]
             << setw(15)<<students[i][10]
             << setw(30)<<students[i][12]
             << setw(15)<<students[i][23]
             << endl;
    }

    cout << "=============================================================================================\n";
}
//==========================================
// View All Teachers
//==========================================

void Admin::viewTeachers()
{
    CSVManager csv;

    vector<vector<string>> teachers =
        csv.readAll("database/teachers.csv");

    cout << "\n";

    cout << "========================================================================================================\n";

    cout << left
         << setw(15)<<"Teacher ID"
         << setw(25)<<"Teacher Name"
         << setw(20)<<"Designation"
         << setw(15)<<"Department"
         << setw(20)<<"Subject"
         << setw(12)<<"Status"
         << endl;

    cout << "========================================================================================================\n";

    for(size_t i=1;i<teachers.size();i++)
    {
        if(teachers[i].size()<14)
            continue;

        cout << left
             << setw(15)<<teachers[i][0]
             << setw(25)<<teachers[i][2]
             << setw(20)<<teachers[i][9]
             << setw(15)<<teachers[i][10]
             << setw(20)<<teachers[i][11]
             << setw(12)<<teachers[i][13]
             << endl;
    }

    cout << "========================================================================================================\n";
}
//==========================================
// Search Student
//==========================================

void Admin::searchStudent()
{
    string studentID;

    cout << "\nEnter Student ID : ";
    getline(cin,studentID);

    Student student;

    if(student.loadStudent(studentID))
    {
        student.displayProfile();
    }
    else
    {
        cout << "\nStudent Not Found.\n";
    }
}
//==========================================
// Search Teacher
//==========================================

void Admin::searchTeacher()
{
    string teacherID;

    cout << "\nEnter Teacher ID : ";
    getline(cin, teacherID);

    Teacher teacher;

    if(teacher.loadTeacher(teacherID))
    {
        teacher.displayProfile();
    }
    else
    {
        cout << "\nTeacher Not Found.\n";
    }
}
//==========================================
// Approve Student
//==========================================

void Admin::approveStudent()
{
    string studentID;

    cout << "\nEnter Student ID : ";
    getline(cin, studentID);

    CSVManager csv;

    vector<vector<string>> students =
        csv.readAll("database/students.csv");

    bool found = false;

    for(size_t i = 1; i < students.size(); i++)
    {
        if(students[i].size() < 24)
            continue;

        if(students[i][0] == studentID)
        {
            students[i][23] = "Approved";

            csv.updateRow("database/students.csv",
                          studentID,
                          students[i]);

            cout << "\n=====================================\n";
            cout << "Admission Approved Successfully.\n";
            cout << "=====================================\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}

//==========================================
// Approve Teacher
//==========================================

void Admin::approveTeacher()
{
    string teacherID;

    cout << "\nEnter Teacher ID : ";
    getline(cin, teacherID);

    CSVManager csv;

    vector<vector<string>> teachers =
        csv.readAll("database/teachers.csv");

    bool found = false;

    for(size_t i = 1; i < teachers.size(); i++)
    {
        if(teachers[i].size() < 14)
            continue;

        if(teachers[i][0] == teacherID)
        {
            teachers[i][13] = "Active";

            csv.updateRow(
                "database/teachers.csv",
                teacherID,
                teachers[i]
            );

            cout << "\n=====================================\n";
            cout << "Teacher Approved Successfully.\n";
            cout << "=====================================\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nTeacher Not Found.\n";
    }
}
//==========================================
// Reject Teacher
//==========================================

void Admin::rejectTeacher()
{
    string teacherID;

    cout << "\nEnter Teacher ID : ";
    getline(cin, teacherID);

    CSVManager csv;

    vector<vector<string>> teachers =
        csv.readAll("database/teachers.csv");

    bool found = false;

    for(size_t i = 1; i < teachers.size(); i++)
    {
        if(teachers[i].size() < 14)
            continue;

        if(teachers[i][0] == teacherID)
        {
            teachers[i][13] = "Rejected";

            csv.updateRow(
                "database/teachers.csv",
                teacherID,
                teachers[i]
            );

            cout << "\n=====================================\n";
            cout << "Teacher Rejected Successfully.\n";
            cout << "=====================================\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nTeacher Not Found.\n";
    }
}
//==========================================
// Reject Student
//==========================================

void Admin::rejectStudent()
{
    string studentID;

    cout << "\nEnter Student ID : ";
    getline(cin, studentID);

    CSVManager csv;

    vector<vector<string>> students =
        csv.readAll("database/students.csv");

    bool found = false;

    for(size_t i = 1; i < students.size(); i++)
    {
        if(students[i].size() < 24)
            continue;

        if(students[i][0] == studentID)
        {
            students[i][23] = "Rejected";

            csv.updateRow("database/students.csv",
                          studentID,
                          students[i]);

            cout << "\n=====================================\n";
            cout << "Admission Rejected Successfully.\n";
            cout << "=====================================\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}
//==========================================
// Remove Student
//==========================================

void Admin::removeStudent()
{
    string studentID;

    cout << "\nEnter Student ID : ";
    getline(cin, studentID);

    CSVManager csv;

    if(csv.deleteRow("database/students.csv",
                     studentID))
    {
        cout << "\n=====================================\n";
        cout << "Student Removed Successfully.\n";
        cout << "=====================================\n";
    }
    else
    {
        cout << "\nStudent Not Found.\n";
    }
}
//==========================================
// Remove Teacher
//==========================================

void Admin::removeTeacher()
{
    string teacherID;

    cout << "\nEnter Teacher ID : ";
    getline(cin, teacherID);

    CSVManager csv;

    if(csv.deleteRow("database/teachers.csv",
                     teacherID))
    {
        cout << "\n=====================================\n";
        cout << "Teacher Removed Successfully.\n";
        cout << "=====================================\n";
    }
    else
    {
        cout << "\nTeacher Not Found.\n";
    }
}//==========================================
// Assign Teacher to Student
//==========================================

void Admin::assignTeacherToStudent()
{
    string studentID;

    cout << "\nEnter Student ID : ";
    getline(cin, studentID);

    CSVManager csv;

    //==============================
    // Load Student
    //==============================

    vector<vector<string>> students =
        csv.readAll("database/students.csv");

    string studentName;
    string department;

    bool foundStudent = false;

    for(size_t i=1;i<students.size();i++)
    {
        if(students[i].size()<24)
            continue;

        if(students[i][0]==studentID)
        {
            if(students[i][23]!="Approved")
            {
                cout<<"\nStudent is not Approved.\n";
                return;
            }

            studentName=students[i][2];
            department=students[i][21];

            foundStudent=true;
            break;
        }
    }

    if(!foundStudent)
    {
        cout<<"\nStudent Not Found.\n";
        return;
    }

    //==============================
    // Show Matching Teachers
    //==============================

    vector<vector<string>> teachers =
        csv.readAll("database/teachers.csv");

    vector<int> teacherIndex;

    cout<<"\n============================================\n";
    cout<<"Available Teachers\n";
    cout<<"============================================\n";

    int serial=1;

    for(size_t i=1;i<teachers.size();i++)
    {
        if(teachers[i].size()<14)
            continue;

        if(teachers[i][10]==department &&
           teachers[i][13]=="Active")
        {
            cout<<serial<<". "
                <<teachers[i][2]
                <<" ("
                <<teachers[i][11]
                <<")"<<endl;

            teacherIndex.push_back(i);

            serial++;
        }
    }

    if(teacherIndex.empty())
    {
        cout<<"\nNo Approved Teacher Available.\n";
        return;
    }

    //==============================
    // Select Teacher
    //==============================

    int choice;

    cout<<"\nSelect Teacher : ";
    cin>>choice;
    cin.ignore();

    if(choice<1 || choice>teacherIndex.size())
    {
        cout<<"\nInvalid Choice.\n";
        return;
    }

    int index = teacherIndex[choice-1];

    string teacherID = teachers[index][0];
    string teacherName = teachers[index][2];
    string subject = teachers[index][11];

    //==============================
    // Create Assignment
    //==============================

    Assignment assignment;

    assignment.createAssignment(
        studentID,
        studentName,
        department,
        teacherID,
        teacherName,
        subject
    );
}
//==========================================
// Reports
//==========================================

void Admin::reports()
{
    CSVManager csv;

    vector<vector<string>> students =
        csv.readAll("database/students.csv");

    vector<vector<string>> teachers =
        csv.readAll("database/teachers.csv");

    vector<vector<string>> assignments =
        csv.readAll("database/assignments.csv");

    int totalStudents = 0;
    int approvedStudents = 0;
    int rejectedStudents = 0;
    int pendingStudents = 0;

    int totalTeachers = 0;
    int activeTeachers = 0;

    int totalAssignments = 0;

    // Student Report
    for(size_t i = 1; i < students.size(); i++)
    {
        if(students[i].size() < 24)
            continue;

        totalStudents++;

        if(students[i][23] == "Approved")
            approvedStudents++;
        else if(students[i][23] == "Rejected")
            rejectedStudents++;
        else
            pendingStudents++;
    }

    // Teacher Report
    for(size_t i = 1; i < teachers.size(); i++)
    {
        if(teachers[i].size() < 14)
            continue;

        totalTeachers++;

        if(teachers[i][13] == "Active")
            activeTeachers++;
    }

    // Assignment Report
    for(size_t i = 1; i < assignments.size(); i++)
    {
        if(assignments[i].size() < 8)
            continue;

        totalAssignments++;
    }

    cout << "\n";
    cout << "=====================================================\n";
    cout << "              SYSTEM REPORT\n";
    cout << "=====================================================\n\n";

    cout << "Total Students          : "
         << totalStudents << endl;

    cout << "Approved Students       : "
         << approvedStudents << endl;

    cout << "Rejected Students       : "
         << rejectedStudents << endl;

    cout << "Pending Students        : "
         << pendingStudents << endl;

    cout << "\n";

    cout << "Total Teachers          : "
         << totalTeachers << endl;

    cout << "Active Teachers         : "
         << activeTeachers << endl;

    cout << "\n";

    cout << "Total Assignments       : "
         << totalAssignments << endl;

    cout << "\n=====================================================\n";
}
