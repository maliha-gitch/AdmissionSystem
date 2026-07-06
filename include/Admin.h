#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Assignment.h"
#include "CSVManager.h"

using namespace std;

class Admin : public Person
{
private:

    string password;

public:

    // Constructor
    Admin();

    // Login
    bool login(string adminID, string password);

    // Dashboard
    void dashboard();

    // Student Management
    void viewStudents();
    void searchStudent();
    void approveStudent();
    void rejectStudent();
    void removeStudent();

    // Teacher Management
    void viewTeachers();
    void searchTeacher();
    void removeTeacher();
    void approveTeacher();
    void rejectTeacher();
    void assignTeacherToStudent();

    // Reports
    void reports();

    // Setter
    void setPassword(string password);

    // Getter
    string getPassword() const;

    // Destructor
    ~Admin();
};

#endif
