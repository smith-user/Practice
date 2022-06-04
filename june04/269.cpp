#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int* d1 = new int[];
    int* d2 = new int[];
    string t1, t2;
    in >> t1 >> t2;
    for (int i = 0; i < size(t1); ++i) {
        d1.push_back(t1[i] - '0');
    }
    for (int i = 0; i < size(t2); ++i) {
        d2.push_back(t2[i] - '0');
    }

    while (d1coun != 0 || d2coun != d2.size()) {
        sum = 0;
        Flag = 0;
        it1 = d1coun;
        it2 = d2coun;
        while (it1 != d1.size() && it2 != d2.size()) {
            if (d1[it1] + d2[it2] > 3) {
                Flag = 1;
            }
            ++it1;
            ++it2;
            sum++;
        }
        if (d1coun != 0) {
            d1coun--;
        }
        else {
            d2coun++;
        }
    }
}