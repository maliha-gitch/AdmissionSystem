#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "CSVManager.h"

using namespace std;

class Student : public Person
{
private:

    // Login Information
    string password;

    // Parents Information
    string fatherName;
    string motherName;

    // Personal Information
    string dateOfBirth;
    string bloodGroup;
    string religion;
    string nationality;

    // Contact Information
    string guardianPhone;
    string presentAddress;
    string permanentAddress;

    // Academic Information
    string sscRoll;
    string sscRegistration;
    string sscGPA;

    string hscRoll;
    string hscRegistration;
    string hscGPA;

    // Admission Information
    string department;
    string groupName;
    string admissionStatus;

public:

    Student();
    void dashboard();

    // Registration
    void registerStudent();

    // Login
    bool login(string studentID, string password);

    // Profile
    void displayProfile();

    // Save Data
    bool saveStudent();

    // Load Data
    bool loadStudent(string studentID);

    // Update
    bool updateStudent();

    // Input Admission Form
    void admissionForm();

    // Generate Student ID
    string generateStudentID();

    // Setters

    void setPassword(string password);
    void setFatherName(string fatherName);
    void setMotherName(string motherName);
    void setDateOfBirth(string dob);
    void setBloodGroup(string bloodGroup);
    void setReligion(string religion);
    void setNationality(string nationality);
    void setGuardianPhone(string guardianPhone);
    void setPresentAddress(string address);
    void setPermanentAddress(string address);
    void setSSCRoll(string roll);
    void setSSCRegistration(string reg);
    void setSSCGPA(string gpa);
    void setHSCRoll(string roll);
    void setHSCRegistration(string reg);
    void setHSCGPA(string gpa);
    void setDepartment(string department);
    void setGroupName(string groupName);
    void setAdmissionStatus(string status);

    // Getters

    string getPassword() const;
    string getFatherName() const;
    string getMotherName() const;
    string getDateOfBirth() const;
    string getBloodGroup() const;
    string getReligion() const;
    string getNationality() const;
    string getGuardianPhone() const;
    string getPresentAddress() const;
    string getPermanentAddress() const;
    string getSSCRoll() const;
    string getSSCRegistration() const;
    string getSSCGPA() const;
    string getHSCRoll() const;
    string getHSCRegistration() const;
    string getHSCGPA() const;
    string getDepartment() const;
    string getGroupName() const;
    string getAdmissionStatus() const;

    // Destructor
    ~Student();
};

#endif
