#include <iostream>

using namespace std;

int task7() {
    string input, substr, newSubstr;
    cout << "Исходная строка: ";
    cin >> input;
    cout << "Подстрока, которую нужно заменить: ";
    cin >> substr;
    cout << "Новая подстрока: ";
    cin >> newSubstr;
    string result;
    int j;
    int i = 0;
    while(i <= (input.length() - substr.length()))
    {
        j = 0;
        while(j < substr.length() && input[i + j] == substr[j])
            j++;
        if (j == substr.length())
        {
            result += newSubstr;
            i += substr.length();
        }
        else
        {
            result += input[i];
            i++;
        }
    }
    cout << "Полученная строка: ";
    cout << result << endl;
    return 0;
}

int task13() {
    string input1, input2;
    cout << "Первая строка: ";
    cin >> input1;
    cout << "Вторая строка: ";
    cin >> input2;
    string result;
    for (char c : input1)
        if (result.find(c) == -1 && input2.find(c) == -1)
            result += c;
    for (char c : input2)
        if (result.find(c) == -1 && input1.find(c) == -1)
            result += c;
    cout << "Полученная строка: ";
    cout << result << endl;
    return 0;
}

int main() {
    task7();
    task13();
    return 0;
}
