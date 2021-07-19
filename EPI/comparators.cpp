#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    double grade_point_average;
    Student(string _name, double _grade) : name(_name), grade_point_average(_grade) {}
};

const static function<bool(const Student &, const Student&)> CompGPA = [](const Student & a, const Student & b) {
    if (a.grade_point_average != b.grade_point_average) {
        return a.grade_point_average > b.grade_point_average;
    }
    return a.name < b.name;
};

class Search {
public:
    bool search(const vector<Student>& students, const Student& target,
                const function<bool(const Student&, const Student&)> CompGPA) {
        return binary_search(begin(students), end(students), target, CompGPA);
    }
};

int main() {
    Search se;
    Student s("C", 20.0);
    vector<Student> arr;
    string name;
    int grade;

    for (int i = 0; i < 5; ++i) {
        cin >> name >> grade;
        Student a(name, grade);
        arr.push_back(a);
    }
    cout << se.search(arr, s, CompGPA);
    return 0;
}