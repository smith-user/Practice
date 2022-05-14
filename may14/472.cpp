#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, M;
    inputFile >> N >> M;
    vector<int> gifts(N);
    for (int i = 0; i < N; i++)
        inputFile >> gifts[i];
    sort(gifts.begin(), gifts.end());

    int i;
    for(i = 0; i < N - 1; i++)
    {
        if (gifts[i] == gifts[i + 1])
            continue;

        if( (gifts[i+1] - gifts[i]) * ( i + 1) > M )
        {
            outputFile << gifts[i] + M / (i + 1);
            return 0;
        }
        else
            M -= (gifts[i + 1] - gifts[i]) * (i + 1);
    }

    outputFile << gifts[i]+ M / N << endl;
}