#include "Person.h"
#include <iostream>

using namespace std;

class Student : public Person
{
public:
    Student(int id, const string &name, const string &course) : Person(id, name), course_(course) {}
    const string &course() const;
    string to_string() const;

private:
    const string course_;
};

class ErasmusStudent : public Student
{
public:
    ErasmusStudent(int id, const string &name, const string &course, const string &country) : Student(id, name, course), country_(country) {}
    const string &country() const;
    string to_string() const;

private:
    const string country_;
};

const string &Student::course() const
{
    return this->course_;
}

string Student::to_string() const
{
    return Person::to_string() + '/' + this->course_;
}

const string &ErasmusStudent::country() const
{
    return this->country_;
}

string ErasmusStudent::to_string() const
{
    return Student::to_string() + '/' + this->country_;
}