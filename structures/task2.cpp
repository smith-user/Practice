#include <iostream>

using namespace std;

struct Student {
    string name;
    int age;
    string drink;
};

int main() {
    int n;
    cin >> n;
    auto* students = new Student[n];
    for (int i = 0; i < n; i++)
        cin >> students[i].name >> students[i].age >> students[i].drink;

    int maxAge = 0;
    for (int i = 0; i < n; i++)
        if (students[i].age > maxAge)
            maxAge = students[i].age;
    cout << maxAge << endl;

    return 0;
}