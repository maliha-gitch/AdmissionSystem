#include "../include/Person.h"

using namespace std;

// Default Constructor
Person::Person()
{
    id = "";
    name = "";
    gender = "";
    phone = "";
    email = "";
    address = "";
}

// Parameterized Constructor
Person::Person(
    string id,
    string name,
    string gender,
    string phone,
    string email,
    string address)
{
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

// ======================
// Setters
// ======================

void Person::setID(string id)
{
    this->id = id;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setGender(string gender)
{
    this->gender = gender;
}

void Person::setPhone(string phone)
{
    this->phone = phone;
}

void Person::setEmail(string email)
{
    this->email = email;
}

void Person::setAddress(string address)
{
    this->address = address;
}

// ======================
// Getters
// ======================

string Person::getID() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

string Person::getGender() const
{
    return gender;
}

string Person::getPhone() const
{
    return phone;
}

string Person::getEmail() const
{
    return email;
}

string Person::getAddress() const
{
    return address;
}

// ======================
// Input Function
// ======================

void Person::input()
{
    cout << "\n========== Personal Information ==========\n";

    cout << "ID              : ";
    getline(cin, id);

    cout << "Name            : ";
    getline(cin, name);

    cout << "Gender          : ";
    getline(cin, gender);

    cout << "Phone           : ";
    getline(cin, phone);

    cout << "Email           : ";
    getline(cin, email);

    cout << "Address         : ";
    getline(cin, address);
}

// ======================
// Display Function
// ======================

void Person::display() const
{
    cout << "\n========== Personal Information ==========\n";

    cout << "ID              : " << id << endl;
    cout << "Name            : " << name << endl;
    cout << "Gender          : " << gender << endl;
    cout << "Phone           : " << phone << endl;
    cout << "Email           : " << email << endl;
    cout << "Address         : " << address << endl;
}

// ======================
// Destructor
// ======================

Person::~Person()
{
    // Nothing to clean up for now
}
