#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string strN;
    long long longK;
    inputFile >> strN >> longK;

    string result;
    long long longN = 0;
    int i = 0;
    while(i < strN.length() && longN < longK)
    {
        longN = longN * 10 + (int)(strN[i] - 48);
        i++;
    }

    if(i == strN.length())
    {
        outputFile << to_string(longN / longK) << endl;
        return 0;
    }

    for(; i < strN.length(); i++)
    {
        longN = longN * 10 + (int)(strN[i] - 48);
        result += to_string(longN / longK);
        longN %= longK;
    }

    outputFile << result << endl;
}