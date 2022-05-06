#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    int** matrix = new int*[N];
    int noEdge = 10e6;
    for(int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
        for(int j = 0; j < N; j++)
        {
            inputFile >> matrix[i][j];
            if(matrix[i][j] == -1)
                matrix[i][j] = noEdge;
        }
    }

    for(int i = 0; i < N; i++)
        for(int u = 0; u < N; u++)
            for(int v = 0; v < N; v++)
                matrix[u][v] = min(matrix[u][v], matrix[u][i] + matrix[i][v]);

    int result = -1;
    for(int u = 0; u < N; u++)
        for(int v = 0; v < N; v++)
            if(matrix[u][v] != noEdge)
                result = max(result, matrix[u][v]);
    outputFile << result << endl;
}