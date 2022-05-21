#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Print(const vector <long long> &vec)
{
    for (auto c : vec)
        cout << c << " ";
    cout << endl;
}

int main() {
    char C;
    long long N, r;
    long weight = 1;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    inputFile >> C >> N;
    vector <long long> L, R;
    while(N > 0)
    {
        r = N % 3;
        if (r == 2) {
            L.push_back(weight);
            N += 3;
        }
        else if (r == 1)
            R.push_back(weight);
        weight *= 3;
        N /= 3;
    }
    if (C == 'L')
    {
        outputFile << "L:";
        Print(L);
        outputFile << "R:";
        Print(R);
    }
    else
    {
        outputFile << "L:";
        Print(R);
        outputFile << "R:";
        Print(L);
    }
    return 0;
}