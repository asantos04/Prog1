
#include <iostream>
#include <iomanip>

using namespace std;


class Date {
  public:
    Date();                             
    Date(int year, int month, int day); 
    int get_year() const;               
    int get_month() const;              
    int get_day() const;                
    void write() const;                 
  private:
    int year;   
    int month;  
    int day;    
};


Date::Date() {
  year = 1;
  month = 1;
  day = 1;
}


Date::Date(int year, int month, int day) {
  this->year = year;
  this->month = month;
  this->day = day;
}


int Date::get_year() const {
  return year;
}


int Date::get_month() const {
  return month;
}


int Date::get_day() const {
  return day;
}


void Date::write() const {
  cout << setfill('0') << setw(4) << year << "/"
       << setw(2) << month << "/"
       << setw(2) << day;
}


bool is_before(const Date& date1, const Date& date2) {
  if (date1.get_year() < date2.get_year()) {
    return true;
  } else if (date1.get_year() > date2.get_year()) {
    return false;
  } else {  
    if (date1.get_month() < date2.get_month()) {
      return true;
    } else if (date1.get_month() > date2.get_month()) {
      return false;
    } else {  
      if (date1.get_day() < date2.get_day()) {
        return true;
      } else {
        return false;
      }
    }
  }
}
