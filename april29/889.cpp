#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int currentPos, count;
    inputFile >> currentPos >> count;
    vector<pair<int, int>> web;
    while(!inputFile.eof())
    {
        int P, H;
        inputFile >> P >> H;
        web.push_back(pair<int, int>(H, P));
    }
    sort(web.rbegin(), web.rend());

    for(int i = 0; i < count; i++)
        if(web[i].second == currentPos)
            currentPos++;
        else if(web[i].second + 1 == currentPos)
            currentPos--;

    outputFile << currentPos << endl;
    inputFile.close();
    outputFile.close();
}