//
// Created by at991 on 4/23/2024.
//

#include "Student.h"


Student::Student(const std::string &id, const std::string &name, const double &gpa)
: id{id}, name{name}, gpa{gpa} {

}

bool Student::operator<(const Student &s) {
    return this->name < s.name;
}

Student &Student::operator=(const Student &other) {
    this->name = other.name;
    this->id = other.id;
    this->gpa = other.gpa;

    return *this;
}