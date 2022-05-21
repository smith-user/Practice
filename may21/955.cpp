#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void f(vector<vector<int>> &vec, int x, int y, int n, int m) {
    if (vec[x][y] != 0) {
        return;
    }
    vec[x][y] = 1;
    if (x + 1 < n) {
        if (vec[x + 1][y] == 0) {
            f(vec, x + 1, y, n, m);
        }
    }
    if (y - 1 >= 0) {
        if (vec[x][y - 1] == 0) {
            f(vec, x, y - 1, n, m);
        }
    }
    if (y + 1 < m) {
        if (vec[x][y + 1] == 0) {
            f(vec, x, y + 1, n, m);
        }
    }
    if (x - 1 >= 0) {
        if (vec[x - 1][y] == 0) {
            f(vec, x - 1, y, n, m);
        }
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int ans = 0;
    int n, m, k, x, y;
    inputFile >> n >> m;
    vector<vector<int>> vect;
    vector<int> plug;
    for (int i = 0; i < n; ++i) {
        plug.clear();
        for (int j = 0; j < m; ++j) {
            plug.push_back(0);
        }
        vect.push_back(plug);
    }
    inputFile >> k;
    for (int i = 0; i < k; ++i) {
        inputFile >> x >> y;
        vect[x - 1][y - 1] = 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vect[i][j] == 0) {
                ans++;
                f(vect, i, j, n, m);
            }
        }
    }
    outputFile << ans;
    return 0;
}