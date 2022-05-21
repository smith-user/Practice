#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    long AB, BC, AC;
    long n;
    inputFile >> n >> AB >> BC >> AC;
    long arr[6] = {};
    long t = min(min(AB, BC), AC) / 2;
    for (int i = 0; i < 6; i += 2)
        arr[i]=t;
    AB -= t * 2;
    BC -= t * 2;
    AC -= t * 2,
            n -= t * 3;
    n -= AB + BC + AC;
    arr[1] = AB; arr[3] = BC; arr[5] = AC;

    if(AB != 0 || BC != 0 || AC != 0 || n != 0)
        outputFile << "NO" << endl;
    else {
        outputFile << "YES" << endl;
        for (auto c : arr)
            outputFile << c << " ";
    }
}