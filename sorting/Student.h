#ifndef SORTING_STUDENT_H
#define SORTING_STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    std::string id;
    std::string name;
    double gpa;
public:
    Student(const std::string &id, const std::string &name, const double &gpa);
    bool operator<(const Student &s);
    Student &operator=(const Student &other);
    friend std::ostream& operator<<(std::ostream& os, const Student &s);
};


#endif //SORTING_STUDENT_H
