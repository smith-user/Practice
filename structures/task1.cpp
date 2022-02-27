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
    for (int i = 0; i < n; i++)
        cout << students[i].name << ' ' << students[i].age << ' ' << students[i].drink << endl;

    return 0;
}
