#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int task1() {
    string fileName;
    cout << "File's name: ";
    cin >> fileName;
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "File Reading Error!" << endl;
        return 1;
    }
    list<double> data;
    double num;
    double amount = 0.0;
    while (!inputFile.eof()) {
        inputFile >> num;
        amount += num;
    }
    inputFile.close();

    data.sort();
    cout << "Average: " << amount / static_cast<int>(data.size()) << endl;
    for(auto elem : data)
        cout << elem << endl;
    return 0;
}

int task2() {
    list<int> data;
    int amount = 0;
    for (int i = 0; i < 10000; i++)
    {
        int num = rand() % 200 - 100;
        amount += num;
        data.push_back(num);
    }
    cout << "Average: " << amount / 10000.0 << endl;
    for(auto elem : data)
        cout << elem << endl;
    return 0;
}