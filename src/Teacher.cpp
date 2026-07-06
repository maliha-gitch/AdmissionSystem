#include "../include/Teacher.h"
#include "../include/Assignment.h"
#include "../include/Report.h"

#include <iomanip>
#include <sstream>

using namespace std;

//========================================
// Constructor
//========================================

Teacher::Teacher()
{
    password = "";

    dateOfBirth = "";

    qualification = "";

    designation = "";

    department = "";

    subject = "";

    experience = "";

    status = "Active";
}

//========================================
// Destructor
//========================================

Teacher::~Teacher()
{

}
//========================================
// Setters
//========================================

void Teacher::setPassword(string password)
{
    this->password = password;
}

void Teacher::setDateOfBirth(string dob)
{
    this->dateOfBirth = dob;
}

void Teacher::setQualification(string qualification)
{
    this->qualification = qualification;
}

void Teacher::setDesignation(string designation)
{
    this->designation = designation;
}

void Teacher::setDepartment(string department)
{
    this->department = department;
}

void Teacher::setSubject(string subject)
{
    this->subject = subject;
}

void Teacher::setExperience(string experience)
{
    this->experience = experience;
}

void Teacher::setStatus(string status)
{
    this->status = status;
}

//========================================
// Getters
//========================================

string Teacher::getPassword() const
{
    return password;
}

string Teacher::getDateOfBirth() const
{
    return dateOfBirth;
}

string Teacher::getQualification() const
{
    return qualification;
}

string Teacher::getDesignation() const
{
    return designation;
}

string Teacher::getDepartment() const
{
    return department;
}

string Teacher::getSubject() const
{
    return subject;
}

string Teacher::getExperience() const
{
    return experience;
}

string Teacher::getStatus() const
{
    return status;
}
//========================================
// Generate Teacher ID
//========================================

string Teacher::generateTeacherID()
{
    CSVManager csv;

    vector<vector<string>> teachers;

    teachers = csv.readAll("database/teachers.csv");

    int count = 0;

    if(teachers.size() > 1)
    {
        count = teachers.size() - 1;
    }

    count++;

    stringstream ss;

    ss << "TEA-2026-"
       << setw(4)
       << setfill('0')
       << count;

    return ss.str();
}
//========================================
// Teacher Registration Form
//========================================

void Teacher::registrationForm()
{
    cout << "\n";
    cout << "=============================================\n";
    cout << "         TEACHER REGISTRATION FORM\n";
    cout << "=============================================\n\n";

    // Auto Generate Teacher ID
    id = generateTeacherID();

    cout << "Teacher ID : " << id << endl << endl;

    cout << "Create Password : ";
    getline(cin, password);

    cout << "\n========== Personal Information ==========\n";

    cout << "Teacher Name : ";
    getline(cin, name);

    cout << "Gender : ";
    getline(cin, gender);

    cout << "Date of Birth (DD-MM-YYYY) : ";
    getline(cin, dateOfBirth);

    cout << "Phone Number : ";
    getline(cin, phone);

    cout << "Email : ";
    getline(cin, email);

    cout << "Address : ";
    getline(cin, address);

    cout << "\n========== Professional Information ==========\n";

    cout << "Qualification : ";
    getline(cin, qualification);

    cout << "Designation : ";
    getline(cin, designation);

    cout << "\nDepartments\n";
    cout << "1. Science\n";
    cout << "2. Commerce\n";
    cout << "3. Arts\n";

    int choice;

    cout << "\nSelect Department : ";
    cin >> choice;
    cin.ignore();

    switch(choice)
    {
        case 1:
            department = "Science";
            break;

        case 2:
            department = "Commerce";
            break;

        case 3:
            department = "Arts";
            break;

        default:
            department = "Not Assigned";
    }

    cout << "Subject : ";
    getline(cin, subject);

    cout << "Experience (Years) : ";
    getline(cin, experience);

    status = "Pending";

    cout << "\n=========================================\n";
    cout << "Registration Form Completed Successfully.\n";
    cout << "Teacher Status : " << status << endl;
    cout << "=========================================\n";
}
//========================================
// Save Teacher Information
//========================================

bool Teacher::saveTeacher()
{
    CSVManager csv;

    string fileName = "database/teachers.csv";

    // Create file if it does not exist
    if (!csv.fileExists(fileName))
    {
        csv.createFile(fileName);
    }

    // Write header if file is empty
    if (csv.totalRecords(fileName) == 0)
    {
        vector<string> header =
        {
            "TeacherID",
            "Password",
            "TeacherName",
            "Gender",
            "DateOfBirth",
            "Phone",
            "Email",
            "Address",
            "Qualification",
            "Designation",
            "Department",
            "Subject",
            "Experience",
            "Status"
        };

        csv.writeHeader(fileName, header);
    }

    // Teacher Information
    vector<string> row;

    row.push_back(id);
    row.push_back(password);
    row.push_back(name);
    row.push_back(gender);
    row.push_back(dateOfBirth);
    row.push_back(phone);
    row.push_back(email);
    row.push_back(address);
    row.push_back(qualification);
    row.push_back(designation);
    row.push_back(department);
    row.push_back(subject);
    row.push_back(experience);
    row.push_back(status);

    if(csv.appendRow(fileName, row))
    {
        cout << "\n=========================================\n";
        cout << "Teacher Registration Successful.\n";
        cout << "Teacher ID : " << id << endl;
        cout << "Department : " << department << endl;
        cout << "Subject    : " << subject << endl;
        cout << "Status     : " << status << endl;
        cout << "=========================================\n";

        return true;
    }

    cout << "\nError! Failed to save teacher information.\n";

    return false;
}
//========================================
// Teacher Login
//========================================

bool Teacher::login(string teacherID,
                    string password)
{
    CSVManager csv;

    vector<vector<string>> teachers;

    teachers = csv.readAll("database/teachers.csv");

    // Skip header row
    for(size_t i = 1; i < teachers.size(); i++)
    {
        if(teachers[i].size() < 14)
            continue;

        if(teachers[i][0] == teacherID &&
           teachers[i][1] == password)
        {
            id = teachers[i][0];
this->password = teachers[i][1];
name = teachers[i][2];
gender = teachers[i][3];
dateOfBirth = teachers[i][4];
phone = teachers[i][5];
email = teachers[i][6];
address = teachers[i][7];
qualification = teachers[i][8];
designation = teachers[i][9];
department = teachers[i][10];
subject = teachers[i][11];
experience = teachers[i][12];
status = teachers[i][13];

            if(status == "Pending")
{
    cout << "\n=====================================\n";
    cout << " Registration is Pending.\n";
    cout << " Please wait for Admin Approval.\n";
    cout << "=====================================\n";

    return false;
}

if(status == "Rejected")
{
    cout << "\n=====================================\n";
    cout << " Registration Rejected.\n";
    cout << " Contact System Administrator.\n";
    cout << "=====================================\n";

    return false;
}

cout << "\n=====================================\n";
cout << " Login Successful.\n";
cout << " Welcome, " << name << "!\n";
cout << "=====================================\n";

            return true;
        }
    }

    cout << "\nInvalid Teacher ID or Password.\n";

    return false;
}
//========================================
// Display Teacher Profile
//========================================

void Teacher::displayProfile()
{
    cout << "\n";
    cout << "==============================================\n";
    cout << "             TEACHER PROFILE\n";
    cout << "==============================================\n";

    cout << "Teacher ID      : " << id << endl;
    cout << "Name            : " << name << endl;
    cout << "Gender          : " << gender << endl;
    cout << "Date of Birth   : " << dateOfBirth << endl;

    cout << "\n----------- Contact Information -------------\n";

    cout << "Phone           : " << phone << endl;
    cout << "Email           : " << email << endl;
    cout << "Address         : " << address << endl;

    cout << "\n-------- Professional Information -----------\n";

    cout << "Qualification   : " << qualification << endl;
    cout << "Designation     : " << designation << endl;
    cout << "Department      : " << department << endl;
    cout << "Subject         : " << subject << endl;
    cout << "Experience      : " << experience << " Years" << endl;
    cout << "Status          : " << status << endl;

    cout << "==============================================\n";
}
//========================================
// Load Teacher Information
//========================================

bool Teacher::loadTeacher(string teacherID)
{
    CSVManager csv;

    vector<vector<string>> teachers =
        csv.readAll("database/teachers.csv");

    for(size_t i=1;i<teachers.size();i++)
    {
        if(teachers[i].size() < 14)
            continue;

        if(teachers[i][0] == teacherID)
        {
            id = teachers[i][0];
            password = teachers[i][1];
            name = teachers[i][2];
            gender = teachers[i][3];
            dateOfBirth = teachers[i][4];
            phone = teachers[i][5];
            email = teachers[i][6];
            address = teachers[i][7];
            qualification = teachers[i][8];
            designation = teachers[i][9];
            department = teachers[i][10];
            subject = teachers[i][11];
            experience = teachers[i][12];
            status = teachers[i][13];

            return true;
        }
    }

    return false;
}
//========================================
// Update Teacher Information
//========================================

bool Teacher::updateTeacher()
{
    cout << "\n";
    cout << "=========================================\n";
    cout << "       UPDATE TEACHER PROFILE\n";
    cout << "=========================================\n";

    string input;

    cout << "Name (" << name << ") : ";
    getline(cin,input);
    if(!input.empty())
        name = input;

    cout << "Gender (" << gender << ") : ";
    getline(cin,input);
    if(!input.empty())
        gender = input;

    cout << "Date of Birth (" << dateOfBirth << ") : ";
    getline(cin,input);
    if(!input.empty())
        dateOfBirth = input;

    cout << "Phone (" << phone << ") : ";
    getline(cin,input);
    if(!input.empty())
        phone = input;

    cout << "Email (" << email << ") : ";
    getline(cin,input);
    if(!input.empty())
        email = input;

    cout << "Address (" << address << ") : ";
    getline(cin,input);
    if(!input.empty())
        address = input;

    cout << "Qualification (" << qualification << ") : ";
    getline(cin,input);
    if(!input.empty())
        qualification = input;

    cout << "Designation (" << designation << ") : ";
    getline(cin,input);
    if(!input.empty())
        designation = input;

    cout << "Department (" << department << ") : ";
    getline(cin,input);
    if(!input.empty())
        department = input;

    cout << "Subject (" << subject << ") : ";
    getline(cin,input);
    if(!input.empty())
        subject = input;

    cout << "Experience (" << experience << ") : ";
    getline(cin,input);
    if(!input.empty())
        experience = input;

    cout << "Password : ";
    getline(cin,input);
    if(!input.empty())
        password = input;

    CSVManager csv;

    vector<string> row;

    row.push_back(id);
    row.push_back(password);
    row.push_back(name);
    row.push_back(gender);
    row.push_back(dateOfBirth);
    row.push_back(phone);
    row.push_back(email);
    row.push_back(address);
    row.push_back(qualification);
    row.push_back(designation);
    row.push_back(department);
    row.push_back(subject);
    row.push_back(experience);
    row.push_back(status);

    if(csv.updateRow("database/teachers.csv", id, row))
    {
        cout << "\n=====================================\n";
        cout << "Teacher Profile Updated Successfully.\n";
        cout << "=====================================\n";

        return true;
    }

    cout << "\nFailed to Update Teacher Profile.\n";

    return false;
}
void Teacher::dashboard()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "=====================================\n";
        cout << "        TEACHER DASHBOARD\n";
        cout << "=====================================\n";
        cout << "1. View Profile\n";
        cout << "2. View Assignments\n";
        cout << "3. Create Report\n";
        cout << "4. View My Reports\n";
        cout << "5. Update Profile\n";
        cout << "0. Logout\n";

        cout << "\nEnter Choice : ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
            displayProfile();
            break;

        case 2:
        {
            Assignment assignment;
            assignment.viewTeacherAssignments(id);
            break;
        }

        case 3:
        {
            Report report;
            report.createReport(id);
            break;
        }

        case 4:
        {
            Report report;
            report.viewTeacherReports(id);
            break;
        }

        case 5:
            updateTeacher();
            break;

        case 0:
            cout << "\nLogged Out.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    }while(choice != 0);
}
