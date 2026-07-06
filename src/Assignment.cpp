#include "../include/Assignment.h"

#include <iomanip>
#include <sstream>

using namespace std;

Assignment::Assignment()
{
    assignmentID="";
    studentID="";
    studentName="";
    department="";
    teacherID="";
    teacherName="";
    subject="";
    status="Assigned";
}

Assignment::~Assignment()
{

}
string Assignment::generateAssignmentID()
{
    CSVManager csv;

    vector<vector<string>> data;

    data = csv.readAll("database/assignments.csv");

    int count = 0;

    if(data.size()>1)
        count=data.size()-1;

    count++;

    stringstream ss;

    ss<<"ASG-2026-"
      <<setw(4)
      <<setfill('0')
      <<count;

    return ss.str();
}
//========================================
// View All Assignments
//========================================

void Assignment::viewAllAssignments()
{
    CSVManager csv;

    vector<vector<string>> assignments =
        csv.readAll("database/assignments.csv");

    cout << "\n";

    cout << "========================================================================================================\n";

    cout << left
         << setw(15) << "Assign ID"
         << setw(15) << "Student ID"
         << setw(20) << "Student Name"
         << setw(15) << "Teacher ID"
         << setw(20) << "Teacher Name"
         << setw(15) << "Subject"
         << setw(12) << "Status"
         << endl;

    cout << "========================================================================================================\n";

    for(size_t i=1;i<assignments.size();i++)
    {
        if(assignments[i].size()<8)
            continue;

        cout << left
             << setw(15) << assignments[i][0]
             << setw(15) << assignments[i][1]
             << setw(20) << assignments[i][2]
             << setw(15) << assignments[i][4]
             << setw(20) << assignments[i][5]
             << setw(15) << assignments[i][6]
             << setw(12) << assignments[i][7]
             << endl;
    }

    cout << "========================================================================================================\n";
}

bool Assignment::createAssignment(string studentID,
                                  string studentName,
                                  string department,
                                  string teacherID,
                                  string teacherName,
                                  string subject)
{
    CSVManager csv;

    string fileName="database/assignments.csv";

    if(!csv.fileExists(fileName))
        csv.createFile(fileName);

    if(csv.totalRecords(fileName)==0)
    {
        vector<string> header=
        {
            "AssignmentID",
            "StudentID",
            "StudentName",
            "Department",
            "TeacherID",
            "TeacherName",
            "Subject",
            "Status"
        };

        csv.writeHeader(fileName,header);
    }

    assignmentID=generateAssignmentID();

    vector<string> row;

    row.push_back(assignmentID);
    row.push_back(studentID);
    row.push_back(studentName);
    row.push_back(department);
    row.push_back(teacherID);
    row.push_back(teacherName);
    row.push_back(subject);
    row.push_back("Assigned");

    if(csv.appendRow(fileName,row))
    {
        cout<<"\n========================================\n";
        cout<<"Assignment Created Successfully.\n";
        cout<<"Assignment ID : "<<assignmentID<<endl;
        cout<<"========================================\n";

        return true;
    }

    return false;
}

//========================================
// View Teacher Assignments
//========================================

void Assignment::viewTeacherAssignments(string teacherID)
{
    CSVManager csv;

    vector<vector<string>> assignments =
        csv.readAll("database/assignments.csv");

    cout << "\n";
    cout << "===============================================================\n";
    cout << "                 TEACHER ASSIGNMENTS\n";
    cout << "===============================================================\n";

    bool found = false;

    for(size_t i=1;i<assignments.size();i++)
    {
        if(assignments[i].size()<8)
            continue;

        if(assignments[i][4]==teacherID)
        {
            found=true;

            cout<<"Assignment ID : "<<assignments[i][0]<<endl;
            cout<<"Student ID    : "<<assignments[i][1]<<endl;
            cout<<"Student Name  : "<<assignments[i][2]<<endl;
            cout<<"Department    : "<<assignments[i][3]<<endl;
            cout<<"Subject       : "<<assignments[i][6]<<endl;
            cout<<"Status        : "<<assignments[i][7]<<endl;

            cout<<"-----------------------------------------------------\n";
        }
    }

    if(!found)
    {
        cout<<"No Assignment Found for this Teacher.\n";
    }

    cout<<"===============================================================\n";
}
//========================================
// View Student Assignments
//========================================

void Assignment::viewStudentAssignments(string studentID)
{
    CSVManager csv;

    vector<vector<string>> assignments =
        csv.readAll("database/assignments.csv");

    cout << "\n";
    cout << "===============================================================\n";
    cout << "                 STUDENT ASSIGNMENTS\n";
    cout << "===============================================================\n";

    bool found=false;

    for(size_t i=1;i<assignments.size();i++)
    {
        if(assignments[i].size()<8)
            continue;

        if(assignments[i][1]==studentID)
        {
            found=true;

            cout<<"Assignment ID : "<<assignments[i][0]<<endl;
            cout<<"Teacher ID    : "<<assignments[i][4]<<endl;
            cout<<"Teacher Name  : "<<assignments[i][5]<<endl;
            cout<<"Subject       : "<<assignments[i][6]<<endl;
            cout<<"Status        : "<<assignments[i][7]<<endl;

            cout<<"-----------------------------------------------------\n";
        }
    }

    if(!found)
    {
        cout<<"No Assignment Found.\n";
    }

    cout<<"===============================================================\n";
}
