#include <iostream>
#include "Student.h"
#include "Sort.h"
#include <vector>
#include <fstream>

using namespace std;

bool compName(const Student &s1, const Student &s2) {
    return s1.name < s2.name;
}

bool compGpa(const Student &s1, const Student &s2) {
    return s1.gpa < s2.gpa;
}

bool comp(const int &s1, const int &s2) {
    return s1 < s2;
}

int main() {
    ifstream file("../students.txt");
    vector <Student> students;
    int n = 0;
    file >> n;
    while (n--) {
        string id, name, gpa;
        getline(file >> ws, name);
        getline(file >> ws, id);
        getline(file >> ws, gpa);
        students.push_back(Student(id, name, stod(gpa)));
    }

    Sort<Student> sort("sortByName");
    sort.sort(students, "mergesort", compGpa);
    file.close();
}