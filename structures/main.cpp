#include <iostream>

using namespace std;

struct Student {
    string name;
    string element;
    int victories;
};

int main() {
    int n;
    cin >> n;
    auto* students = new Student[n];
    string t;
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].element;
    }

}

