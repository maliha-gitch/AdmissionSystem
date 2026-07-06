#include "../include/Student.h"
#include "../include/Assignment.h"
#include "../include/Report.h"

#include <iomanip>
#include <sstream>

using namespace std;

//========================================
// Default Constructor
//========================================


Student::Student()
{
    password = "";

    fatherName = "";
    motherName = "";

    dateOfBirth = "";
    bloodGroup = "";
    religion = "";
    nationality = "";

    guardianPhone = "";

    presentAddress = "";
    permanentAddress = "";

    sscRoll = "";
    sscRegistration = "";
    sscGPA = "";

    hscRoll = "";
    hscRegistration = "";
    hscGPA = "";

    department = "";
    groupName = "";

    admissionStatus = "Pending";
    cout << "\n******** NEW STUDENT.CPP ********\n";
}

//========================================
// Destructor
//========================================

Student::~Student()
{

}
//========================================
// Setters
//========================================

void Student::setPassword(string password)
{
    this->password = password;
}

void Student::setFatherName(string fatherName)
{
    this->fatherName = fatherName;
}

void Student::setMotherName(string motherName)
{
    this->motherName = motherName;
}

void Student::setDateOfBirth(string dob)
{
    this->dateOfBirth = dob;
}

void Student::setBloodGroup(string bloodGroup)
{
    this->bloodGroup = bloodGroup;
}

void Student::setReligion(string religion)
{
    this->religion = religion;
}

void Student::setNationality(string nationality)
{
    this->nationality = nationality;
}

void Student::setGuardianPhone(string guardianPhone)
{
    this->guardianPhone = guardianPhone;
}

void Student::setPresentAddress(string address)
{
    this->presentAddress = address;
}

void Student::setPermanentAddress(string address)
{
    this->permanentAddress = address;
}

void Student::setSSCRoll(string roll)
{
    this->sscRoll = roll;
}

void Student::setSSCRegistration(string reg)
{
    this->sscRegistration = reg;
}

void Student::setSSCGPA(string gpa)
{
    this->sscGPA = gpa;
}

void Student::setHSCRoll(string roll)
{
    this->hscRoll = roll;
}

void Student::setHSCRegistration(string reg)
{
    this->hscRegistration = reg;
}

void Student::setHSCGPA(string gpa)
{
    this->hscGPA = gpa;
}

void Student::setDepartment(string department)
{
    this->department = department;
}

void Student::setGroupName(string groupName)
{
    this->groupName = groupName;
}

void Student::setAdmissionStatus(string status)
{
    this->admissionStatus = status;
}

//========================================
// Getters
//========================================

string Student::getPassword() const
{
    return password;
}

string Student::getFatherName() const
{
    return fatherName;
}

string Student::getMotherName() const
{
    return motherName;
}

string Student::getDateOfBirth() const
{
    return dateOfBirth;
}

string Student::getBloodGroup() const
{
    return bloodGroup;
}

string Student::getReligion() const
{
    return religion;
}

string Student::getNationality() const
{
    return nationality;
}

string Student::getGuardianPhone() const
{
    return guardianPhone;
}

string Student::getPresentAddress() const
{
    return presentAddress;
}

string Student::getPermanentAddress() const
{
    return permanentAddress;
}

string Student::getSSCRoll() const
{
    return sscRoll;
}

string Student::getSSCRegistration() const
{
    return sscRegistration;
}

string Student::getSSCGPA() const
{
    return sscGPA;
}

string Student::getHSCRoll() const
{
    return hscRoll;
}

string Student::getHSCRegistration() const
{
    return hscRegistration;
}

string Student::getHSCGPA() const
{
    return hscGPA;
}

string Student::getDepartment() const
{
    return department;
}

string Student::getGroupName() const
{
    return groupName;
}

string Student::getAdmissionStatus() const
{
    return admissionStatus;
}
//========================================
// Generate Student ID
//========================================

string Student::generateStudentID()
{
    CSVManager csv;

    vector<vector<string>> students;

    students = csv.readAll("database/students.csv");

    int count = 0;

    if(students.size() > 1)
    {
        count = students.size() - 1;
    }

    count++;

    stringstream ss;

    ss << "STU-2026-"
       << setw(4)
       << setfill('0')
       << count;

    return ss.str();
}

//========================================
// Student Admission Form
//========================================

void Student::admissionForm()
{
    cout << "\n";
    cout << "=============================================\n";
    cout << "       STUDENT ADMISSION APPLICATION\n";
    cout << "=============================================\n\n";

    // Auto Generate Student ID
    id = generateStudentID();

    cout << "Student ID : " << id << endl << endl;

    cout << "Create Password : ";
    getline(cin, password);

    cout << "\n========== Personal Information ==========\n";

    cout << "Student Name : ";
    getline(cin, name);

    cout << "Father Name : ";
    getline(cin, fatherName);

    cout << "Mother Name : ";
    getline(cin, motherName);

    cout << "Date of Birth (DD-MM-YYYY) : ";
    getline(cin, dateOfBirth);

    cout << "Gender : ";
    getline(cin, gender);

    cout << "Blood Group : ";
    getline(cin, bloodGroup);

    cout << "Religion : ";
    getline(cin, religion);

    cout << "Nationality : ";
    getline(cin, nationality);

    cout << "\n========== Contact Information ==========\n";

    cout << "Phone Number : ";
    getline(cin, phone);

    cout << "Guardian Phone : ";
    getline(cin, guardianPhone);

    cout << "Email : ";
    getline(cin, email);

    cout << "Present Address : ";
    getline(cin, presentAddress);

    cout << "Permanent Address : ";
    getline(cin, permanentAddress);

    cout << "\n========== SSC Information ==========\n";

    cout << "SSC Roll : ";
    getline(cin, sscRoll);

    cout << "SSC Registration : ";
    getline(cin, sscRegistration);

    cout << "SSC GPA : ";
    getline(cin, sscGPA);

    cout << "\n========== HSC Information ==========\n";

    cout << "HSC Roll : ";
    getline(cin, hscRoll);

    cout << "HSC Registration : ";
    getline(cin, hscRegistration);

    cout << "HSC GPA : ";
    getline(cin, hscGPA);

    cout << "\n========== Department ==========\n";

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
        department = "Not Selected";
    }

    cout << "Group / Combined Subject : ";
    getline(cin, groupName);

    admissionStatus = "Pending";

    cout << "\n---------------------------------------------\n";
    cout << "Admission Form Completed Successfully.\n";
    cout << "Status : " << admissionStatus << endl;
    cout << "---------------------------------------------\n";
}

//========================================
// Save Student Information to CSV
//========================================

bool Student::saveStudent()
{
    CSVManager csv;

    string fileName = "database/students.csv";

    // Create file if it does not exist
    if (!csv.fileExists(fileName))
    {
        csv.createFile(fileName);
    }

    // If file is empty, write the header
    if (csv.totalRecords(fileName) == 0)
    {
        vector<string> header =
        {
            "StudentID",
            "Password",
            "StudentName",
            "FatherName",
            "MotherName",
            "DateOfBirth",
            "Gender",
            "BloodGroup",
            "Religion",
            "Nationality",
            "Phone",
            "GuardianPhone",
            "Email",
            "PresentAddress",
            "PermanentAddress",
            "SSCRoll",
            "SSCRegistration",
            "SSCGPA",
            "HSCRoll",
            "HSCRegistration",
            "HSCGPA",
            "Department",
            "Group",
            "AdmissionStatus"
        };

        csv.writeHeader(fileName, header);
    }

    // Student data
    vector<string> row;

    row.push_back(id);
    row.push_back(password);
    row.push_back(name);
    row.push_back(fatherName);
    row.push_back(motherName);
    row.push_back(dateOfBirth);
    row.push_back(gender);
    row.push_back(bloodGroup);
    row.push_back(religion);
    row.push_back(nationality);
    row.push_back(phone);
    row.push_back(guardianPhone);
    row.push_back(email);
    row.push_back(presentAddress);
    row.push_back(permanentAddress);
    row.push_back(sscRoll);
    row.push_back(sscRegistration);
    row.push_back(sscGPA);
    row.push_back(hscRoll);
    row.push_back(hscRegistration);
    row.push_back(hscGPA);
    row.push_back(department);
    row.push_back(groupName);
    row.push_back(admissionStatus);
    cout << "\nRow Size = " << row.size() << endl;

for(int i=0;i<row.size();i++)
{
    cout << i << " -> " << row[i] << endl;
}

    if (csv.appendRow(fileName, row))
    {
        cout << "\n========================================\n";
        cout << "Student Registration Successful.\n";
        cout << "Student ID : " << id << endl;
        cout << "Admission Status : " << admissionStatus << endl;
        cout << "========================================\n";

        return true;
    }

    cout << "\nError! Unable to save student information.\n";

    return false;
}

//========================================
// Student Login
//========================================

bool Student::login(string studentID, string password)
{
CSVManager csv;

vector<vector<string>> students =
        csv.readAll("database/students.csv");

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i][0] == studentID &&
            students[i][1] == password)
        {
            // Load student information
            id = students[i][0];
            this->password = students[i][1];
            name = students[i][2];
            fatherName = students[i][3];
            motherName = students[i][4];
            dateOfBirth = students[i][5];
            gender = students[i][6];
            bloodGroup = students[i][7];
            religion = students[i][8];
            nationality = students[i][9];
            phone = students[i][10];
            guardianPhone = students[i][11];
            email = students[i][12];
            presentAddress = students[i][13];
            permanentAddress = students[i][14];
            sscRoll = students[i][15];
            sscRegistration = students[i][16];
            sscGPA = students[i][17];
            hscRoll = students[i][18];
            hscRegistration = students[i][19];
            hscGPA = students[i][20];
            department = students[i][21];
           groupName = students[i][22];
           admissionStatus = students[i][23];
            // ===== Status Check =====

            if(admissionStatus=="Pending")
            {
                cout << "\n=====================================\n";
                cout << " Admission is Pending.\n";
                cout << " Please wait for Admin Approval.\n";
                cout << "=====================================\n";
                return false;
            }

           if(admissionStatus=="Rejected")
            {
                cout << "\n=====================================\n";
                cout << " Admission Rejected.\n";
                cout << " Contact Admission Office.\n";
                cout << "=====================================\n";
                return false;
            }

            cout << "\n=====================================\n";
            cout << " Login Successful.\n";
            cout << "=====================================\n";

            return true;
        }
    }

    cout << "\nInvalid Student ID or Password.\n";

    return false;
}

//========================================
// Display Student Profile
//========================================

void Student::displayProfile()
{
    cout << "\n";
    cout << "=====================================================\n";
    cout << "                STUDENT PROFILE\n";
    cout << "=====================================================\n";

    cout << "Student ID          : " << id << endl;
    cout << "Student Name        : " << name << endl;
    cout << "Father Name         : " << fatherName << endl;
    cout << "Mother Name         : " << motherName << endl;
    cout << "Date of Birth       : " << dateOfBirth << endl;
    cout << "Gender              : " << gender << endl;
    cout << "Blood Group         : " << bloodGroup << endl;
    cout << "Religion            : " << religion << endl;
    cout << "Nationality         : " << nationality << endl;

    cout << "\n--------------- Contact Information -----------------\n";

    cout << "Phone               : " << phone << endl;
    cout << "Guardian Phone      : " << guardianPhone << endl;
    cout << "Email               : " << email << endl;

    cout << "Present Address     : " << presentAddress << endl;
    cout << "Permanent Address   : " << permanentAddress << endl;

    cout << "\n--------------- Academic Information ----------------\n";

    cout << "SSC Roll            : " << sscRoll << endl;
    cout << "SSC Registration    : " << sscRegistration << endl;
    cout << "SSC GPA             : " << sscGPA << endl;

    cout << "HSC Roll            : " << hscRoll << endl;
    cout << "HSC Registration    : " << hscRegistration << endl;
    cout << "HSC GPA             : " << hscGPA << endl;

    cout << "\n--------------- Admission Information ---------------\n";

    cout << "Department          : " << department << endl;
    cout << "Group               : " << groupName << endl;
    cout << "Admission Status    : " << admissionStatus << endl;

    cout << "=====================================================\n";
}

//========================================
// Load Student Information by Student ID
//========================================

bool Student::loadStudent(string studentID)
{
    CSVManager csv;

    vector<vector<string>> students = csv.readAll("database/students.csv");

    for(size_t i = 1; i < students.size(); i++)
    {
        if(students[i].size() < 24)
            continue;

        if(students[i][0] == studentID)
        {
            id = students[i][0];
            password = students[i][1];
            name = students[i][2];
            fatherName = students[i][3];
            motherName = students[i][4];
            dateOfBirth = students[i][5];
            gender = students[i][6];
            bloodGroup = students[i][7];
            religion = students[i][8];
            nationality = students[i][9];
            phone = students[i][10];
            guardianPhone = students[i][11];
            email = students[i][12];
            presentAddress = students[i][13];
            permanentAddress = students[i][14];
            sscRoll = students[i][15];
            sscRegistration = students[i][16];
            sscGPA = students[i][17];
            hscRoll = students[i][18];
            hscRegistration = students[i][19];
            hscGPA = students[i][20];
            department = students[i][21];
            groupName = students[i][22];
            admissionStatus = students[i][23];

            return true;
        }
    }

    return false;
}

//========================================
// Update Student Information
//========================================

bool Student::updateStudent()
{
    cout << "\n";
    cout << "=========================================\n";
    cout << "       UPDATE STUDENT PROFILE\n";
    cout << "=========================================\n";

    cout << "Student ID : " << id << endl;
    cout << "Admission Status : " << admissionStatus << endl;

    cout << "\nLeave a field empty if you don't want to change it.\n\n";

    string input;

    cout << "Student Name (" << name << ") : ";
    getline(cin, input);
    if(!input.empty())
        name = input;

    cout << "Father Name (" << fatherName << ") : ";
    getline(cin, input);
    if(!input.empty())
        fatherName = input;

    cout << "Mother Name (" << motherName << ") : ";
    getline(cin, input);
    if(!input.empty())
        motherName = input;

    cout << "Date of Birth (" << dateOfBirth << ") : ";
    getline(cin, input);
    if(!input.empty())
        dateOfBirth = input;

    cout << "Gender (" << gender << ") : ";
    getline(cin, input);
    if(!input.empty())
        gender = input;

    cout << "Blood Group (" << bloodGroup << ") : ";
    getline(cin, input);
    if(!input.empty())
        bloodGroup = input;

    cout << "Religion (" << religion << ") : ";
    getline(cin, input);
    if(!input.empty())
        religion = input;

    cout << "Nationality (" << nationality << ") : ";
    getline(cin, input);
    if(!input.empty())
        nationality = input;


            cout << "Phone (" << phone << ") : ";
    getline(cin, input);
    if(!input.empty())
        phone = input;

    cout << "Guardian Phone (" << guardianPhone << ") : ";
    getline(cin, input);
    if(!input.empty())
        guardianPhone = input;

    cout << "Email (" << email << ") : ";
    getline(cin, input);
    if(!input.empty())
        email = input;

    cout << "Present Address (" << presentAddress << ") : ";
    getline(cin, input);
    if(!input.empty())
        presentAddress = input;

    cout << "Permanent Address (" << permanentAddress << ") : ";
    getline(cin, input);
    if(!input.empty())
        permanentAddress = input;

    cout << "\n=========== SSC Information ===========\n";

    cout << "SSC Roll (" << sscRoll << ") : ";
    getline(cin, input);
    if(!input.empty())
        sscRoll = input;

    cout << "SSC Registration (" << sscRegistration << ") : ";
    getline(cin, input);
    if(!input.empty())
        sscRegistration = input;

    cout << "SSC GPA (" << sscGPA << ") : ";
    getline(cin, input);
    if(!input.empty())
        sscGPA = input;

    cout << "\n=========== HSC Information ===========\n";

    cout << "HSC Roll (" << hscRoll << ") : ";
    getline(cin, input);
    if(!input.empty())
        hscRoll = input;

    cout << "HSC Registration (" << hscRegistration << ") : ";
    getline(cin, input);
    if(!input.empty())
        hscRegistration = input;

    cout << "HSC GPA (" << hscGPA << ") : ";
    getline(cin, input);
    if(!input.empty())
        hscGPA = input;

    cout << "\nDepartment (" << department << ") : ";
    getline(cin, input);
    if(!input.empty())
        department = input;

    cout << "Group (" << groupName << ") : ";
    getline(cin, input);
    if(!input.empty())
        groupName = input;

    cout << "Password : ";
    getline(cin, input);
    if(!input.empty())
        password = input;

            CSVManager csv;

    vector<string> row;

    row.push_back(id);
    row.push_back(password);
    row.push_back(name);
    row.push_back(fatherName);
    row.push_back(motherName);
    row.push_back(dateOfBirth);
    row.push_back(gender);
    row.push_back(bloodGroup);
    row.push_back(religion);
    row.push_back(nationality);
    row.push_back(phone);
    row.push_back(guardianPhone);
    row.push_back(email);
    row.push_back(presentAddress);
    row.push_back(permanentAddress);
    row.push_back(sscRoll);
    row.push_back(sscRegistration);
    row.push_back(sscGPA);
    row.push_back(hscRoll);
    row.push_back(hscRegistration);
    row.push_back(hscGPA);
    row.push_back(department);
    row.push_back(groupName);
    row.push_back(admissionStatus);

    if(csv.updateRow("database/students.csv", id, row))
    {
        cout << "\n=====================================\n";
        cout << "Student Profile Updated Successfully.\n";
        cout << "=====================================\n";

        return true;
    }

    cout << "\nFailed to update profile.\n";

    return false;
}
void Student::dashboard()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "=====================================\n";
        cout << "        STUDENT DASHBOARD\n";
        cout << "=====================================\n";
        cout << "1. View Profile\n";
        cout << "2. View Assignments\n";
        cout << "3. View Reports\n";
        cout << "4. Update Profile\n";
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
            assignment.viewStudentAssignments(id);
            break;
        }

        case 3:
        {
            Report report;
            report.viewStudentReports(id);
            break;
        }

        case 4:
            updateStudent();
            break;

        case 0:
            cout << "\nLogged Out.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    }while(choice != 0);
}
