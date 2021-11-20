#include <iostream>

using namespace std;

void taskL() {
    string number;
    cin >> number;
    if (number == "0") {
        return;
    }
    cout << number << endl;

    cin >> number;
    if (number == "0")
        return;
    taskL();
}

void taskP(int &maxN, int &countN) {
    int number;
    cin >> number;
    if (number == 0) {
        return;
    }

    if (number == maxN)
        countN++;
    else if (number > maxN) {
        maxN = number;
        countN = 1;
    }
    taskP(maxN, countN);
}

int main() {
    // -----taskL-----
    taskL();
    // -----taskL-----


    // -----taskP-----
    int number;
    cin >> number;
    int count = 1;
    taskP(number, count);
    cout << count << endl;
    // -----taskP-----
}