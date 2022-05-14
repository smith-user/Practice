#include <iostream>
#include <fstream>
#include <cmath>

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

    int K;
    inputFile >> K;
    int simpleK = 0;
    int superSimpleK = 0;

    int i = 1;
    while(superSimpleK != K)
    {
        i++;
        if (IsPrime(i)) {
            simpleK++;
            if (IsPrime(simpleK))
                superSimpleK++;
        }
    }
    outputFile << i << endl;
}