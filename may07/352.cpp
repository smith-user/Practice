#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int maxDivisor(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    for(int i = N / 2; i > 0; i--)
        if(maxDivisor(i, N - i) == 1)
        {
            outputFile << i << ' ' << N - i << endl;
            return 0;
        }
}
