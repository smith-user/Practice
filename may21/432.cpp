#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

vector<string> vect;
int n,m;
const char check = '#';
const char uncheck = '.';

struct point
{
    int x,y;
    point(){}
    point(int X, int Y) :
    x(X), y(Y) {}
};

int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, -1, 0, 1};

bool correct(int x, int y)
{
    if (x < 0 || y < 0)
        return false;
    if (x >= n || y >= m)
        return false;
    return true;
}

void dfs(int fx, int fy)
{
    stack<point> s;
    s.push(point(fx, fy));
    while (!s.empty())
    {
        point cur = s.top();
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];
            if (correct(x,y) && vect[x][y] == check)
            {
                vect[x][y] = uncheck;
                s.push(point(x, y));
            }
        }
    }
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    inputFile >> n >> m;
    vect.resize(n);
    for (int i = 0; i < n; i++)
        inputFile >> vect[i];
    int amount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (vect[i][j] == check)
            {
                dfs(i, j);
                amount++;
            }
    outputFile << amount;
    return 0;
}
