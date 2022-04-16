#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("INPUT.txt");
    ofstream outputFile("OUTPUT.txt");
    int n;
    inputFile >> n;
    int t = (n * n + 1) / 2;
    outputFile << (t - 1) / 9 * 10 + (t - 1) % 9 + 1;
    return 0;
}