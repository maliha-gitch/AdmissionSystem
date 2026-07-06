#ifndef TEACHER_H
#define TEACHER_H

#include<iostream>
#include<string>
#include<vector>

#include "Person.h"
#include "CSVManager.h"

using namespace std;

class Teacher : public Person
{

private:

    string password;

    string dateOfBirth;

    string qualification;

    string designation;

    string department;

    string subject;

    string experience;

    string status;

public:

    Teacher();

    // Registration
    void registrationForm();

    bool saveTeacher();

    // Login
    bool login(string teacherID,
               string password);
    void dashboard();

    // Profile
    void displayProfile();

    bool loadTeacher(string teacherID);

    bool updateTeacher();

    // ID Generation
    string generateTeacherID();

    // Setters

    void setPassword(string);
    void setDateOfBirth(string);
    void setQualification(string);
    void setDesignation(string);
    void setDepartment(string);
    void setSubject(string);
    void setExperience(string);
    void setStatus(string);

    // Getters

    string getPassword() const;
    string getDateOfBirth() const;
    string getQualification() const;
    string getDesignation() const;
    string getDepartment() const;
    string getSubject() const;
    string getExperience() const;
    string getStatus() const;

    ~Teacher();

};

#endif
