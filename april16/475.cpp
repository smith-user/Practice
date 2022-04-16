#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    vector<int> data;

    int num;
    while(!inputFile.eof())
    {
        inputFile >> num;
        data.push_back(num);
    }

    sort(data.begin(), data.end());

    int d = data[1] - data[0];
    bool bFlag = true;
    for(int i = 1; i < data.size() - 1 and bFlag; i++)
        bFlag = data[i + 1] - data[i] == d;
    if (bFlag)
        outputFile << "Yes";
    else
        outputFile << "No";

    inputFile.close();
    outputFile.close();
}