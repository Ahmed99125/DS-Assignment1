#ifndef SORTING_STUDENT_H
#define SORTING_STUDENT_H

#include <string>

class Student {
public:
    std::string id;
    std::string name;
    double gpa;
public:
    Student(const std::string &id, const std::string &name, const double &gpa);
    bool operator<(const Student &s);
    Student &operator=(const Student &other);
};


#endif //SORTING_STUDENT_H
