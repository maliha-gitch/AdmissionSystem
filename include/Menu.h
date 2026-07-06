#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include "Assignment.h"

using namespace std;

class Menu
{
private:

    Student student;
    Teacher teacher;
    Admin admin;
    Assignment assignment;

public:

    // Constructor
    Menu();

    // Main Menu
    void mainMenu();

    // Portals
    void studentMenu();

    void teacherMenu();

    void adminMenu();

    // Utility
    void clearScreen();

    void pause();

    // Destructor
    ~Menu();
};

#endif
