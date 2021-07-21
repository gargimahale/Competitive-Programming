#include <bits/stdc++.h>
using namespace std;

struct Student {
    bool operator<(const Student& a) const {return name < a.name;}
    string name;
    double grade_point;
    Student(string _name, double _grade) : name(_name), grade_point(_grade) {}
};

class Test {
public:
    void display(vector<Student>& stud) {
        for (auto x : stud) {
            cout << x.name << " " << x.grade_point << "\n";
        }
    }

    void sortByGPA(vector<Student>& students) {
        sort(students.begin(), students.end(), [](const Student & a, const Student & b) {
            return a.grade_point >= b.grade_point;
        });
        cout << "Sorting by GPA:\n";
        display(students);
        cout << "\n";
    }

    void sortByName(vector<Student>& students) {
        sort(students.begin(), students.end());
        cout << "Sorting by Name:\n";
        display(students);
        cout << "\n";
    }
};

int main(void) {
    Test t;
    vector<Student> arr;
    for (int i = 0; i < 5; ++i) {
        string n;
        int g;
        cin >> n >> g;
        Student ss(n, g);
        arr.emplace_back(ss);
    }
    cout << "\n";
    t.sortByGPA(arr);
    t.sortByName(arr);
}
