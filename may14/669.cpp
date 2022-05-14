#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

bool IsPrime(const int &num)
{
    if(num == 1)
        return false;
    for (int i = 2; i <= (int)sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int M;
    inputFile >> M;

    if(IsPrime(M) && M > 10)
    {
        outputFile << -1 << ' ' << -1 << endl;
        return 0;
    }

    int num = M;
    vector<int> divisorsMin;
    for(int i = 9; i > 1; i--)
        while(num % i == 0)
        {
            num /= i;
            divisorsMin.push_back(i);
        }

    if(num != 1)
    {
        outputFile << -1 << ' ' << -1 << endl;
        return 0;
    }

    num = M;
    vector<int> divisorsMax;
    for(int i = 2; i < 10; i++)
        while(num % i == 0)
        {
            num /= i;
            divisorsMax.push_back(i);
        }

    string resultMin;
    string resultMax;
    for(auto digit : divisorsMin)
        resultMin = to_string(digit) + resultMin;

    for(auto digit : divisorsMax)
        resultMax = to_string(digit) + resultMax;

    outputFile << resultMin << ' ' << resultMax << endl;
}