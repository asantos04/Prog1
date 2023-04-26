#include <string>
#include <vector>

struct course {
  std::string name;
  float credits;
  short grade;
};

class Student {
public:
  Student(const std::string& id) : id_(id) {}
  
  // accessor
  std::string get_id() const { return id_; }
  

  void add(const course& c) {
    if (c.grade >= 10) {
      courses_.push_back(c);
    }
  }
  
  double avg() const {
    double total_credits = 0.0;
    double total_weighted_grade = 0.0;
    for (const auto& c : courses_) {
      total_credits += c.credits;
      total_weighted_grade += c.credits * c.grade;
    }
    if (total_credits == 0) {
      return 0.0;
    } else {
      return total_weighted_grade / total_credits;
    }
  }
  
private:
  std::string id_;
  std::vector<course> courses_;
};
