#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, M;
    inputFile >> N >> M;
    long long numerator = 1;
    long long denominator = 1;
    int k = 1;
    for(int i = 1; N != M; N--, i++)
    {
        numerator *= N;
        denominator *= i;
        k += (int)(numerator / denominator);
    }
    outputFile << k << endl;
}