#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name, const string& address, const string& phone);
    string get_name() const;
    string get_address() const;
    string get_phone() const;
private:
    string name_;    // Name
    string address_; // Address
    string phone_;   // Phone
};

Person::Person(const string& name, const string& address, const string& phone) :
    name_(name), address_(address), phone_(phone) {}

string Person::get_name() const {
    return name_;
}

string Person::get_address() const {
    return address_;
}

string Person::get_phone() const {
    return phone_;
}

void show_persons_data(const vector<Person>& persons) {
    cout << "[" << endl;
    for (const auto& person : persons) {
        cout << "  " << person.get_name() << " : " << person.get_address() << " : " << person.get_phone() << endl;
    }
    cout << "]" << endl;
}

void read_persons_data(const string& file_name, vector<Person>& persons) {
    ifstream infile(file_name);
    string name, address, phone;
    while (getline(infile, name) && getline(infile, address) && getline(infile, phone)) {
        persons.push_back(Person(name, address, phone));
    }
}

void sort_persons_by_name(vector<Person>& persons) {
    sort(persons.begin(), persons.end(),
        [](const Person& p1, const Person& p2) { return p1.get_name() < p2.get_name(); });
}

