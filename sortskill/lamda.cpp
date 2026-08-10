#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string name, int age)
        : name(name), age(age) {}
};

int main()
{
    vector<Student> students = {
        {"An", 20},
        {"Binh", 18},
        {"Cuong", 22}
    };

    // Sort bằng lambda
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.age < b.age;
        }
    );

    // Giảm dần:
    // return a.age > b.age;
}