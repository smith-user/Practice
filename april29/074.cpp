#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, M;
    inputFile >> N >> M;

    int count = 0;
    while(M % 2 != 0 && N > 1)
    {
        count += N/2;
        N = N - N/2;
        M = M - M/2;
    }
    if (M == 1)
        count += 1;
    else
        count += M/2;

    outputFile << count << endl;
    inputFile.close();
    outputFile.close();
}