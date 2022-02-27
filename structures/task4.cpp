#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int age;
    string drink;
};

string reverseString(string line) {
    string result;
    for(char i : line)
        result = i + result;
    return result;
}

int main() {
    int n;
    cin >> n;
    auto* students = new Student[n];
    for (int i = 0; i < n; i++)
        cin >> students[i].name >> students[i].age >> students[i].drink;

    vector <string> names;
    for (int i = 0; i < n; i++)
        names.push_back(reverseString(students[i].name));
    sort(names.begin(), names.end());
    for(auto name : names)
        cout << name << " - " << reverseString(name) << endl;
    return 0;
}