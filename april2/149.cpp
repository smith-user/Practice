#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;
    int* data = new int[n];
    for (int i = 0; i < n; i++)
        inputFile >> data[i];
    for (int i = n - 1; i >= 0; i--)
        outputFile << data[i] << ' ';
    outputFile << endl;
    delete[] data;
}
