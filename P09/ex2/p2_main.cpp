#include <vector> 
#include "Person.h"
 #include "Date.h" 
#include <iostream> 
void born_before(const std::vector<Person>& persons, const Date& date) { Person current;
Date current_birtdate;
date.show(); std::cout<< ": ";
for (unsigned long i = 0; i < persons.size(); i++) {
current = persons.at(i);
 current_birtdate = current.get_birth_date();
 if (current_birtdate.is_before(date)) { 
current.show(); std::cout<< " "; 
}
}
}
