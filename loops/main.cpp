#include <iostream>

using namespace std;

int task19() {
    for (int number1 = 10; number1 < 100; number1++)
        for (int number2 = 10; number2 < 100; number2++)
            if ((number1 * 100 + number2) % (number1 * number2) == 0)
                cout << (number1 * 100 + number2) << endl;
    return 0;
}

int task20() {
    for (int number1 = 10; number1 < 100; number1++)
        for (int number2 = 10; number2 < 100; number2++)
            if (((number1 * 100 + number2) % 99 == 0) && ((number2 * 100 + number1) % 49 == 0))
                cout << "A = " << number1 << " B = " << number2 << endl;
    return 0;
}

int task21() {
    int n;
    cin >> n;
    double result = 0.0;
    for (int i = 1; i <= n; i++)
        result += (1.0 / (2 * i * i));
    cout << result << endl;
    return 0;
}

int task22() {
    int n;
    cin >> n;
    double result = 0.0;
    for (int i = 1; i <= n; i++)
        result += (1.0 / i);
    cout << result << endl;
    return 0;
}

int main() {
    cout << "Задание 19" << endl;
    task19();
    cout << "Задание 20" << endl;
    task20();
    cout << "Задание 21" << endl;
    task21();
    cout << "Задание 22" << endl;
    task22();
    return 0;
}