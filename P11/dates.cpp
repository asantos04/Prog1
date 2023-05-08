#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Date {
public:
  Date(int year = 1, int month = 1, int day = 1) 
     : year_(year), month_(month), day_(day) {}
  int getYear() const { return year_; }
  int getMonth() const { return month_; }
  int getDay() const { return day_; }
  bool operator<(const Date& other) const {
    if (year_ != other.year_)
      return year_ < other.year_;
    if (month_ != other.month_)
      return month_ < other.month_;
    return day_ < other.day_;
  }
  friend ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year_ << '/'
       << setw(2) << date.month_ << '/'
       << setw(2) << date.day_;
    return os;
  }
private:
  int year_, month_, day_;
};

int main() {
  vector<Date> dates{{2022, 5, 7}, {2021, 12, 31}, {2022, 1, 1}};
  
  // sort the dates in ascending order
  sort(dates.begin(), dates.end());
  
  // print the sorted dates
  for (const auto& d : dates) 
    cout << d << endl;
  
  return 0;
}