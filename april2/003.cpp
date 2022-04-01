#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int A;
    inputFile >> A;
    A /= 10;
    int result = A * (A + 1);
    if (result != 0)
        outputFile << result;
    outputFile << "25" << endl;

    inputFile.close();
    outputFile.close();
}