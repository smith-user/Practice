#include <iostream>
#include <fstream>

using namespace std;

int N;
void feelMatrix(int** matrix, int value, int coord) {
    if(value > N * N)
        return;
    for(int i = coord; i < N - coord; i++)
        matrix[coord][i] = value++;
    for(int i = coord + 1; i < N - coord; i++)
        matrix[i][N - coord - 1] = value++;
    for(int i = N - coord - 2; i >= coord; i--)
        matrix[N - coord - 1][i] = value++;
    for(int i = N - coord - 2; i > coord; i--)
        matrix[i][coord] = value++;
    feelMatrix(matrix, value, coord + 1);
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;
    N = n;
    int** matrix = new int*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new int[N];
    feelMatrix(matrix, 1, 0);

    string spaces;
    for(int i = 0; i < N*N; i++)
        spaces += ' ';

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            outputFile << spaces.substr(0,to_string(N*N).length() - to_string(matrix[i][j]).length()) << matrix[i][j] << ' ';
        outputFile << endl;
    }
}