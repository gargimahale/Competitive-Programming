#include <bits/stdc++.h>
using namespace std;

#define NAME_SIZE 50

class Person{
    int id;
    char name[NAME_SIZE];

public:
    void aboutMe(){
        cout << "I am a Person\n";
    }
};

class Student: public Person{
public:
    void aboutMe(){
        cout << "I am a Student\n";
    }
};

int main(){
    Student *p = new Student();
    p->aboutMe();
    delete p;
    return 0;
}