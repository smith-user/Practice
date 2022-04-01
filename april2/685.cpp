#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    const int N = 3;
    vector<int> prices(N);
    vector<int> containers(N);

    for(int i = 0; i < N; i++)
        inputFile >> prices[i];
    for(int i = 0; i < N; i++)
        inputFile >> containers[i];

    sort(prices.begin(), prices.end());
    sort(containers.begin(), containers.end());

    int result = 0;
    for(int i = 0; i < N; i++)
        result += prices[i] * containers[i];
    outputFile << result << endl;
}
