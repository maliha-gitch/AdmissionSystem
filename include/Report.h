#ifndef REPORT_H
#define REPORT_H

#include "CSVManager.h"
#include <string>

using namespace std;

class Report
{
private:

    string reportID;

    string teacherID;
    string teacherName;

    string studentID;
    string studentName;

    string title;
    string description;
    string date;

public:

    Report();
    ~Report();

    string generateReportID();

    bool createReport(string teacherID);

    bool saveReport();

    void viewStudentReports(string studentID);

    void viewTeacherReports(string teacherID);
};

#endif
