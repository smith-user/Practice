#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int x;

    inputFile >> x;
    inputFile.close();

    outputFile << x << endl;
    outputFile.close();
}
