#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:

    string id;
    string name;
    string gender;
    string phone;
    string email;
    string address;

public:

    Person();

    Person(
        string id,
        string name,
        string gender,
        string phone,
        string email,
        string address
    );

    // Setters
    void setID(string id);
    void setName(string name);
    void setGender(string gender);
    void setPhone(string phone);
    void setEmail(string email);
    void setAddress(string address);

    // Getters
    string getID() const;
    string getName() const;
    string getGender() const;
    string getPhone() const;
    string getEmail() const;
    string getAddress() const;

    virtual void input();
    virtual void display() const;

    virtual ~Person();
};

#endif
