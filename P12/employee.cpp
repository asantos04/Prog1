#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Employee.h"
#include <vector>
#include <iostream>

using namespace std;

void HourlyEmployee::calculate_net_pay()
{
    Employee::set_net_pay(get_hours() * get_rate());
}

void SalariedEmployee::calculate_net_pay()
{
    Employee::set_net_pay(get_salary());
}

void read_hours_worked(vector<Employee *> &employees)
{
    double hours;
    for (Employee *employee : employees)
    {
        cin >> hours;
        HourlyEmployee *hourlyEmployee = dynamic_cast<HourlyEmployee *>(employee);
        if (hourlyEmployee)
        {
            hourlyEmployee->set_hours(hours);
        }
    }
}

void calculate_pay(vector<Employee *> &employees)
{
    for (Employee *employee : employees)
    {
        employee->calculate_net_pay();
    }
}

void print_checks(const vector<Employee *> &employees)
{
    for (Employee *employee : employees)
    {
        cout << "| ";
        employee->print_check();
        cout << " ";
    }
    cout << "|";
}

