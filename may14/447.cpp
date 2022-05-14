#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    long long result = 1;
    inputFile >> N;
    for(int i = 2; i <= N; i++)
    {
        result *= i;
        while(result % 10 == 0)
            result /= 10;
        result %= 1000000;
    }
    result %= 10;
    outputFile << result << endl;
}