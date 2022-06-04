#include <iostream>
#include <fstream>

using namespace std;

struct Cell
{
    Cell() {};
    Cell(int value):
            value(value)
    {}
    int value;
    bool step = false;
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    Cell** data = new Cell*[N];

    string values;
    for (int i = 0; i < N; i++)
    {
        data[i] = new Cell[N];
        inputFile >> values;
        for(int j = 0; j < N; j++)
            data[i][j] = Cell(values[j] - 48);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i > 0 and j > 0)
                data[i][j].value += min(data[i - 1][j].value, data[i][j - 1].value);
            else if (i == 0 and j > 0)
                data[i][j].value += data[i][j - 1].value;
            else if (i > 0 and j == 0)
                data[i][j].value += data[i - 1][j].value;

    int x, y;
    x = y = N - 1;
    data[x][y].step = true;
    while (x != 0 or y != 0)
    {
        if (x != 0 and (y == 0 or data[x - 1][y].value < data[x][y - 1].value))
            x--;
        else
            y--;
        data[x][y].step = true;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (data[i][j].step)
                outputFile << '#';
            else
                outputFile << '.';
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();
}
