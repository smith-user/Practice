#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    long long int mult = 1;
    while(N > 4)
    {
        mult *= 3;
        N -= 3;
    }
    mult *= N;
    outputFile << mult << endl;
}