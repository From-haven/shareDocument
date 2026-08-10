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

    // Định nghĩa ý nghĩa của:
    // a < b
    bool operator<(const Student& other) const
    {
        return age < other.age;
    }
};

int main()
{
    vector<Student> students = {
        {"An", 20},
        {"Binh", 18},
        {"Cuong", 22}
    };

    // Không cần truyền comparator
    sort(
        students.begin(),
        students.end()
    );
}