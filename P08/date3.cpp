#include "Date3.h"
#include <string>
#include <sstream>
#include <iostream>

int Date::num_days(int year, int month) {
  if (month == 2){
    if (year % 400 == 0){
      return 28;
    } else if (year % 100 == 0){
      return 27;
    } else if (year % 4 == 0){
      return 28;
    } else {
      return 27;
    }
  }
  switch(month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    break;}
  return 30;
}

Date::Date() {
  yyyymmdd = "00010101";
}
std::string normalizeAndConcatenate(const int &year, const int& month, const int& day){
  std::string monthS = std::to_string(month);
  if (monthS.length() !=2) monthS.insert(0, "0");
  std::string yearS = std::to_string(year);
  while (yearS.length() <4) yearS.insert(0, "0");
  std::string dayS = std::to_string(day);
  if (dayS.length() != 2) dayS.insert(0, "0");
  return yearS + monthS + dayS;
}


Date::Date(int y, int m, int d) {
  int year = 0 < y && y < 10000 ? y:0;
  int month = 0 < m && m < 13 ? m : 0;
  int day = 0 < d && d <= num_days(y,m) ? d : 0;
  if (year == 0 || month == 0 || day == 0){
    year = 0;
    month = 0;
    day = 0;
  }
  yyyymmdd = normalizeAndConcatenate(year, month, day);
}

Date::Date(const std::string &year_month_day){
  int y = 0;
  int m = 0;
  int d = 0;
  char b,bb;
  std::istringstream iss(year_month_day);
  if (iss >> y >> b >> m >> bb >> d && b == '/' && bb == '/') {
    y = 0 <y && y<10000 ? y : 0;
    m = 0 < m && m < 13 ? m : 0;
    d = 0 < d && d <= num_days(y,m) ? d : 0;
    
  }
  else {y= 0 ; d = 0; m = 0;}
  if (y == 0 || m == 0 || d == 0){
    y = 0;
    m = 0;
    d = 0;
  }
    yyyymmdd = normalizeAndConcatenate(y,m,d);
}
int Date::get_year() const {
  return std::stoi(yyyymmdd.substr(0,4));
}
int Date::get_month() const {
  return std::stoi(yyyymmdd.substr(4,2));
}
int Date::get_day() const {
  return std::stoi(yyyymmdd.substr(6,2));
}
bool Date::is_valid() const {
  return (this ->get_year()!= 0 && this ->get_day() != 0 && this->get_month() !=0 ? true:false);
}

