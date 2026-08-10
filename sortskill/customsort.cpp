#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename Compare>
void bubbleSort(
    vector<T>& v,
    int left,
    int right,
    Compare comp
) {
    for (int i = left; i <= right; ++i) {

        for (int j = left;
             j < right - (i - left);
             ++j) {

            // comp(a, b):
            // a có nên đứng trước b?
            if (comp(v[j + 1], v[j])) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}


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

    bubbleSort(
        students,
        0,
        students.size() - 1,

        [](const Student& a, const Student& b) {
            return a.age < b.age;
        }
    );
}