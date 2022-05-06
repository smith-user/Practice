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
    long long longN = 0;
    for(char digit : strN)
        longN = (longN * 10 + (int)(digit - 48)) % longK;
    outputFile << longN << endl;
}