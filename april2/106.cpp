#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    int reverse = 0;
    while(!inputFile.eof())
    {
        int t;
        inputFile >> t;
        reverse += t;
    }

    int result = min(N - reverse, reverse);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();
}