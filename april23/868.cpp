#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, M;
    inputFile >> N >> M;
    int** data = new int*[N];

    int maxElem = 0;
    int maxElemLine;
    int maxElemColumn;
    for (int i = 0; i < N; i++)
    {
        data[i] = new int[M];
        for(int j = 0; j < M; j++)
        {
            inputFile >> data[i][j];
            if (data[i][j] > maxElem)
            {
                maxElem = data[i][j];
                maxElemLine = i;
                maxElemColumn = j;
            }
        }
    }

    int minElem = data[maxElemLine][0];
    int column;
    for(int j = 1; j < M; j++)
        if(data[maxElemLine][j] < minElem)
        {
            minElem = data[maxElemLine][j];
            column = j;
        }

    minElem = data[0][maxElemColumn];
    int line;
    for(int i = 0; i < N; i++)
        if(data[i][maxElemColumn] < minElem)
        {
            minElem = data[i][maxElemColumn];
            line = i;
        }

    outputFile << data[line][column] << endl;
    inputFile.close();
    outputFile.close();
}
