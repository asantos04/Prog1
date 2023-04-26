#include <iostream>
#include "Date2.h"
#include <sstream>
using namespace std;

Date::Date(): year(1), month(1), day(1){}

int Date::num_days(int year, int month)

{
static const int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int num_days = days_per_month[month - 1];
if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
num_days = 29;
}
return num_days;
}
Date::Date(int year, int month, int day): year(year), month(month), day(day)
{
if(!is_valid())
{
this->year = 0;
this->month = 0;
this->day = 0;
}
}
Date::Date(const std::string& year_month_day)
{
char c1, c2;
istringstream iss(year_month_day);
if(!(iss >> year >> c1 >> month >> c2 >> day) || !is_valid() || c1 != '/' || c2 != '/')
{
year = 0;
month = 0;
day = 0;
}
}

bool Date:: is_valid() const {
if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month)) {
return true;
}

return false;
}