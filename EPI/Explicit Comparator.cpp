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
    void display(list<Student>& stud) {
        for (auto x : stud) {
            cout << x.name << " " << x.grade_point << "\n";
        }
    }

    // void sortByGPA(vector<Student>& students) {
    //     sort(students.begin(), students.end(), [](const Student & a, const Student & b) {
    //         return a.grade_point >= b.grade_point;
    //     });
    //     cout << "Sorting by GPA:\n";
    //     display(students);
    //     cout << "\n";
    // }

    void sortByName(list<Student>& students) {
        // sort(students.begin(), students.end());
        students.sort();
        cout << "Sorting by Name:\n";
        display(students);
        cout << "\n";
    }
};

int main(void) {
    Test t;
    list<Student> arr = { Student("Sid", 22),
                          Student("Laura", 3),
                          Student("Riti", 43),
                          Student("Angel", 30),
                          Student("Laura", 2),
                        };
    // t.sortByGPA(arr);
    t.sortByName(arr);
}
