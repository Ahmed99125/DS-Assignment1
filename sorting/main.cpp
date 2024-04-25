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

int main() {
    vector <Student> v = {Student("1", "c", 3.7), Student("2", "t", 4), Student("3", "b", 3.8)};
    Sort <Student> sort1("sortByName");
    cout << endl;
    sort1.sort(v, "shellsort", compName);
    for (auto i : v)
        cout << i.id << ' ' << i.name << ' ' << i.gpa << endl;
}