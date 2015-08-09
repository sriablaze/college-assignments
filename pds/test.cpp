#include<iostream>
using namespace std;

class Student {
    int rollNo;
    string name;

    public: Student() {
        rollNo = 5;
        name = "Mukund";
    }

    void display() {
        cout << "Name is " << name;
    }
};

int main() {
    Student s;
    s.display();
    return 0;
}


