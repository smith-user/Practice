#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    vector<pair<int,int>> data;

    int n;
    inputFile >> n;
    int num;
    for(int i = 1; i <= n; i++)
    {
        inputFile >> num;
        data.push_back(pair<int, int> (num, i));
    }

    sort(data.begin(), data.end());

    int idx1, idx2;
    int minDiff = (int)10e+9;
    for(int i = 0; i < data.size() - 1; i++)
        if(data[i + 1].first - data[i].first < minDiff)
        {
            minDiff = data[i + 1].first - data[i].first;
            idx1 = data[i + 1].second;
            idx2 = data[i].second;
        }
    outputFile << minDiff << endl;
    outputFile << idx2 << ' ' << idx1 << endl;

    inputFile.close();
    outputFile.close();
}