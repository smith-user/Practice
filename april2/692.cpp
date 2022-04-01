#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;
    if (n == 0)
    {
        outputFile << "NO" << endl;
        inputFile.close();
        outputFile.close();
        return 0;
    }

    double degree = log(n)/log(2);
    if (degree - (int)degree < 10e-6)
        outputFile << "YES" << endl;
    else
        outputFile << "NO" << endl;

    inputFile.close();
    outputFile.close();
}
