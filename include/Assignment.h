#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <vector>

#include "CSVManager.h"

using namespace std;

class Assignment
{
private:

    string assignmentID;

    string studentID;
    string studentName;
    string department;

    string teacherID;
    string teacherName;
    string subject;

    string status;

public:

    Assignment();
    ~Assignment();

    string generateAssignmentID();

    bool createAssignment(string studentID,
                          string studentName,
                          string department,
                          string teacherID,
                          string teacherName,
                          string subject);

    void viewAllAssignments();

    void viewStudentAssignments(string studentID);

    void viewTeacherAssignments(string teacherID);
};

#endif
