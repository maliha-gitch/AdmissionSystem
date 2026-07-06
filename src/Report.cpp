#include "../include/Report.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Report::Report()
{

}

Report::~Report()
{

}
string Report::generateReportID()
{
    CSVManager csv;

    vector<vector<string>> reports =
        csv.readAll("database/reports.csv");

    int count = 0;

    if(reports.size()>1)
        count = reports.size()-1;

    count++;

    stringstream ss;

    ss<<"REP-2026-"
      <<setw(4)
      <<setfill('0')
      <<count;

    return ss.str();
}
bool Report::saveReport()
{
    CSVManager csv;

    string fileName = "database/reports.csv";

    if(!csv.fileExists(fileName))
    {
        csv.createFile(fileName);
    }

    if(csv.totalRecords(fileName)==0)
    {
        vector<string> header;

        header.push_back("ReportID");
        header.push_back("TeacherID");
        header.push_back("TeacherName");
        header.push_back("StudentID");
        header.push_back("StudentName");
        header.push_back("Title");
        header.push_back("Description");
        header.push_back("Date");

        csv.writeHeader(fileName,header);
    }

    vector<string> row;

    row.push_back(reportID);
    row.push_back(teacherID);
    row.push_back(teacherName);
    row.push_back(studentID);
    row.push_back(studentName);
    row.push_back(title);
    row.push_back(description);
    row.push_back(date);

    return csv.appendRow(fileName,row);
}

bool Report::createReport(string teacherID)
{
    CSVManager csv;

    vector<vector<string>> assignments =
        csv.readAll("database/assignments.csv");

    if(assignments.size() <= 1)
    {
        cout << "\nNo Assignment Found.\n";
        return false;
    }

    vector<vector<string>> myStudents;

    cout << "\n============================================\n";
    cout << "          MY ASSIGNED STUDENTS\n";
    cout << "============================================\n";

    for(size_t i=1;i<assignments.size();i++)
    {
        if(assignments[i].size() < 8)
            continue;

        if(assignments[i][4] == teacherID)
        {
            myStudents.push_back(assignments[i]);

            cout << "Student ID   : " << assignments[i][1] << endl;
            cout << "Student Name : " << assignments[i][2] << endl;
            cout << "Department   : " << assignments[i][3] << endl;
            cout << "--------------------------------------------\n";
        }
    }

    if(myStudents.empty())
    {
        cout << "\nNo Student Assigned.\n";
        return false;
    }

    this->teacherID = teacherID;

    cout << "\nEnter Student ID : ";
    getline(cin, studentID);

    bool found = false;

    for(size_t i=0;i<myStudents.size();i++)
    {
        if(myStudents[i][1] == studentID)
        {
            studentID = myStudents[i][1];
            studentName = myStudents[i][2];
            teacherName = myStudents[i][5];

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nInvalid Student ID.\n";
        return false;
    }

    reportID = generateReportID();

    cout << "\nReport Title : ";
    getline(cin,title);

    cout << "Report Description : ";
    getline(cin,description);

    cout << "Date : ";
    getline(cin,date);

    if(saveReport())
    {
        cout << "\n=====================================\n";
        cout << "Report Created Successfully.\n";
        cout << "Report ID : " << reportID << endl;
        cout << "=====================================\n";

        return true;
    }

    cout << "\nFailed to Save Report.\n";

    return false;
}
void Report::viewStudentReports(string studentID)
{
    CSVManager csv;

    vector<vector<string>> reports =
        csv.readAll("database/reports.csv");

    cout << "\n";
    cout << "=============================================================\n";
    cout << "                  MY REPORTS\n";
    cout << "=============================================================\n";

    bool found = false;

    for(size_t i = 1; i < reports.size(); i++)
    {
        if(reports[i].size() < 8)
            continue;

        if(reports[i][3] == studentID)
        {
            found = true;

            cout << "Report ID     : " << reports[i][0] << endl;
            cout << "Teacher       : " << reports[i][2] << endl;
            cout << "Title         : " << reports[i][5] << endl;
            cout << "Date          : " << reports[i][7] << endl;
            cout << "---------------------------------------------\n";
            cout << reports[i][6] << endl;
            cout << "=============================================================\n";
        }
    }

    if(!found)
    {
        cout << "\nNo Report Found.\n";
    }
}

void Report::viewTeacherReports(string teacherID)
{
    CSVManager csv;

    vector<vector<string>> reports =
        csv.readAll("database/reports.csv");

    cout << "\n";
    cout << "=============================================================\n";
    cout << "                MY CREATED REPORTS\n";
    cout << "=============================================================\n";

    bool found = false;

    for(size_t i = 1; i < reports.size(); i++)
    {
        if(reports[i].size() < 8)
            continue;

        if(reports[i][1] == teacherID)
        {
            found = true;

            cout << "Report ID     : " << reports[i][0] << endl;
            cout << "Student ID    : " << reports[i][3] << endl;
            cout << "Student Name  : " << reports[i][4] << endl;
            cout << "Title         : " << reports[i][5] << endl;
            cout << "Date          : " << reports[i][7] << endl;
            cout << "---------------------------------------------\n";
            cout << reports[i][6] << endl;
            cout << "=============================================================\n";
        }
    }

    if(!found)
    {
        cout << "\nNo Report Found.\n";
    }
}
