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
    vector <int> v;
    for (int i = 100000; i >= 0; i--) v.push_back(i);
    Sort <int> sort1("sortByName");
    cout << endl;
    sort1.sort(v, "mergesort", comp);
}