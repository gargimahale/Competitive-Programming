#include <bits/stdc++.h>
using namespace std;

struct Student {
    int age;
    string name;
    Student(int _age, string _name): age(_age), name(_name) {}
};

class Test {
public:
    void display(vector<Student>& studs) const {
        for (int i = 0; i < studs.size(); ++i) {
            cout << studs[i].age << " " << studs[i].name << "\n";
        }
    }

    void groupByAge(vector<Student>& studs) const {

        // gets the age count for students with same age
        unordered_map<int, int> age_cnt;
        for (const Student& s : studs) {
            ++age_cnt[s.age];
        }

        // gets the offset-> [start, end] for each unique age
        int offset = 0;
        unordered_map<int, int> age_offset;
        for (const auto entry : age_cnt) {
            age_offset[entry.first] = offset;
            offset += entry.second;
        }

        while (age_offset.size()) {
            auto from = age_offset.begin();
            auto to = age_offset.find(studs[from->second].age);
            swap(studs[from->second], studs[to->second]);
            --age_cnt[to->first];

            if (age_cnt[to->first] > 0) {
                ++to->second;
            }
            else {
                age_offset.erase(to);
            }
        }

        // O(N logN)
        // sort(begin(studs), end(studs), [&](const Student & a, const Student & b) {
        //     return a.age <= b.age;
        // });

        cout << "Same Entries:\n";
        display(studs);
    }
};

int main(void) {
    Test t;
    vector<Student> arr;
    for (int i = 0; i <= 5; ++i) {
        int a;
        string b;
        cin >> a >> b;
        Student ss(a, b);
        arr.push_back(ss);
    }
    t.groupByAge(arr);
}

// TC: O(N), SC: O(N)