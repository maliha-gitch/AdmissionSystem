#include "../include/Menu.h"

#include <cstdlib>

using namespace std;

//==========================================
// Constructor
//==========================================

Menu::Menu()
{

}

//==========================================
// Destructor
//==========================================

Menu::~Menu()
{

}

//==========================================
// Clear Screen
//==========================================

void Menu::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//==========================================
// Pause
//==========================================

void Menu::pause()
{
    cout << "\n";
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}
//==========================================
// Student Menu
//==========================================

void Menu::studentMenu()
{
    int choice;

    do
    {
        clearScreen();

        cout << "=============================================\n";
        cout << "            STUDENT PORTAL\n";
        cout << "=============================================\n";

        cout << "1. Student Registration\n";
        cout << "2. Student Login\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
        {
            Student student;

            student.admissionForm();

            student.saveStudent();

            pause();

            break;
        }

        case 2:
        {
            Student student;

            string id;
            string password;

            cout << "\nStudent ID : ";
            getline(cin,id);

            cout << "Password : ";
            getline(cin,password);

            if(student.login(id,password))
{
    student.dashboard();
}

            pause();

            break;
        }

        case 0:

            break;

        default:

            cout << "\nInvalid Choice.\n";

            pause();
        }

    }while(choice!=0);
}
//==========================================
// Teacher Menu
//==========================================

void Menu::teacherMenu()
{
    int choice;

    do
    {
        clearScreen();

        cout << "=============================================\n";
        cout << "             TEACHER PORTAL\n";
        cout << "=============================================\n";

        cout << "1. Teacher Registration\n";
        cout << "2. Teacher Login\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";

        cin >> choice;

        cin.ignore();

        switch(choice)
        {

        case 1:
        {
            Teacher teacher;

            teacher.registrationForm();

            teacher.saveTeacher();

            pause();

            break;
        }

        case 2:
        {
            Teacher teacher;

            string id;
            string password;

            cout << "\nTeacher ID : ";
            getline(cin,id);

            cout << "Password : ";
            getline(cin,password);

            if(teacher.login(id,password))
{
    teacher.dashboard();
}

            pause();

            break;
        }

        case 0:

            break;

        default:

            cout << "\nInvalid Choice.\n";

            pause();
        }

    }while(choice!=0);
}
//==========================================
// Admin Menu
//==========================================

void Menu::adminMenu()
{
    clearScreen();

    string adminID;
    string password;

    cout << "=============================================\n";
    cout << "               ADMIN LOGIN\n";
    cout << "=============================================\n\n";

    cout << "Admin ID : ";
    getline(cin, adminID);

    cout << "Password : ";
    getline(cin, password);

    if(admin.login(adminID, password))
    {
        admin.dashboard();
    }
    else
    {
        cout << "\nLogin Failed.\n";
        pause();
    }
}

//==========================================
// Main Menu
//==========================================

void Menu::mainMenu()
{
    int choice;

    do
    {
        clearScreen();

        cout << "=====================================================\n";
        cout << "      UNIVERSITY ADMISSION MANAGEMENT SYSTEM\n";
        cout << "=====================================================\n\n";

        cout << "1. Student Portal\n";
        cout << "2. Teacher Portal\n";
        cout << "3. Admin Portal\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";

        cin >> choice;

        cin.ignore();

        switch(choice)
        {
        case 1:

            studentMenu();

            break;

        case 2:

            teacherMenu();

            break;

        case 3:

            adminMenu();

            break;

        case 0:

            cout << "\n";
            cout << "=====================================\n";
            cout << "Thank You For Using The System.\n";
            cout << "Good Bye!\n";
            cout << "=====================================\n";

            break;

        default:

            cout << "\nInvalid Choice.\n";

            pause();
        }

    }
    while(choice != 0);
}
