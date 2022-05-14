#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    cin >> N;
    int** arr = new int*[N + 1];
    arr[0] = new int[N + 1];
    for(int i = 1; i < N + 1; i++)
    {
        arr[i] = new int[N + 1];
        for (int j = 1; j < N + 1; j++)
            inputFile >> arr[i][j];
    }


    int minValue = -INT32_MAX;
    int** maxValues = new int*[N+1];
    for(int i = 1; i < N + 1; i++)
    {
        maxValues[i] = new int[N + 1];
        for (int j = 1; j < N + 1; j++)
            maxValues[i][j] = minValue;
    }
    maxValues[0][0] = 0;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j <  N + 1; j++) {
            maxValues[i][j] = maxValues[i - 1][j];
            for (int k = 1; k <= j; k++)
                maxValues[i][j] = max(maxValues[i][j], maxValues[k][i] + maxValues[i - 1][j - k]);
        }
    }

    outputFile << maxValues[N][N] << endl;
}