#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int k, p;
    inputFile >> k >> p;
    map<int, long long> mp;
    mp[2] = 1;
    if (k == 1) {
        outputFile << 0;
        return 0;
    }
    for (int i = 3; i <= k; i++) {
        if (i % 2 == 1) {
            mp[i] = mp[i - 1] % p;
        }
        else {
            mp[i] = (mp[i - 1] + mp[i / 2]) % p;
            mp.erase(i / 2);
        }
    }
    outputFile << mp[k];
    return 0;
}