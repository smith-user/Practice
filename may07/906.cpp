#include <iostream>
#include <fstream>

using namespace std;

long defaultValue = -INT64_MAX;
long values[21][21][21];

long F(long a, long b, long c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
    {
        if (values[20][20][20] == defaultValue)
            values[20][20][20] = F(20, 20, 20);
        return values[20][20][20];
    }
    else
    {
        if (values[a][b][c] == defaultValue)
        {
            if (a < b && b < c)
                values[a][b][c] = F(a, b, c-1) + F(a, b-1, c-1) - F(a, b-1, c);
            else
                values[a][b][c] = F(a-1, b, c) + F(a-1, b-1, c) + F(a-1, b, c-1) - F(a-1, b-1, c-1);
        }
        return values[a][b][c];
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    for(int i = 0; i < 21; i++)
        for(int j = 0; j < 21; j++)
            for(int k = 0; k < 21; k++)
                values[i][j][k] = defaultValue;

    long a, b, c;
    inputFile >> a >> b >> c;
    outputFile << F(a, b, c) << endl;
    return 0;
}
