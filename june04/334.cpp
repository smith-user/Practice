#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    long N;
    inputFile >> N;
    vector<long long> data(N);
    for (long i = 0; i < N; i++)
        inputFile >> data[i];

    sort(data.begin(), data.end());
    long long result = max(data[N - 1] * data[0] * data[1], data[N - 1] * data[N - 3] * data[N - 2]);
    outputFile << result << endl;
    inputFile.close();
    outputFile.close();
}
