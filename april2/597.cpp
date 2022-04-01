#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int r1, r2, r3;
    inputFile >> r1 >> r2 >> r3;

    if (r1 >= r2 + r3)
        outputFile << "YES" << endl;
    else
        outputFile << "NO" << endl;
}
