#include <iostream>
#include <cmath>

using namespace std;

struct Student {
    string name;
    int age;
    string drink;
};

bool numIsSimple(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    auto* students = new Student[n];
    for (int i = 0; i < n; i++)
        cin >> students[i].name >> students[i].age >> students[i].drink;

    for (int i = 0; i < n; i++)
        if (numIsSimple(students[i].age))
            cout << students[i].name << ' ' << students[i].drink << endl;

    return 0;
}
