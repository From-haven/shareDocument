// ============================================================
// SORT OBJECT - CÁC KỸ THUẬT
// ============================================================

class Student {
public:
    string name;
    int age;

    // 1. operator<
    bool operator<(const Student& other) const {
        return age < other.age;
    }
};


// ============================================================
// 2. LAMBDA
// ============================================================

sort(v.begin(), v.end(),
    [](const Student& a, const Student& b) {
        return a.age < b.age;
    }
);


// ============================================================
// 3. BOOL FUNCTION
// ============================================================

bool compareAge(
    const Student& a,
    const Student& b
) {
    return a.age < b.age;
}

sort(v.begin(), v.end(), compareAge);


// ============================================================
// 4. CUSTOM SORT + COMPARATOR
// ============================================================

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

            if (comp(v[j + 1], v[j]))
                swap(v[j], v[j + 1]);
        }
    }
}


// ============================================================
// BẢN CHẤT
// ============================================================
//
// Lambda:
//     [](a, b) { return a.age < b.age; }
//
// Function:
//     bool compareAge(a, b)
//
// operator<:
//     a < b
//
// Tất cả đều trả lời:
//
//     "a có nên đứng trước b không?"
// ============================================================