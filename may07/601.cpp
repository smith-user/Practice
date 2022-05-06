#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n, m;
    inputFile >> n >> m;
    auto maze = new map<int, int>[n];
    int room1, room2, color;
    for(int i = 0; i < m; i++)
    {
        inputFile >> room1 >> room2 >> color;
        maze[room1 - 1][color] = room2 - 1;
        maze[room2 - 1][color] = room1 - 1;
    }

    int k;
    inputFile >> k;
    int currentRoom = 0;
    int c;
    for(int i = 0; i < k; i++)
    {
        inputFile >> c;
        if(maze[currentRoom].find(c) == maze[currentRoom].end())
        {
            outputFile << "INCORRECT" << endl;
            return 0;
        }
        currentRoom = maze[currentRoom][c];
    }
    outputFile << currentRoom + 1 << endl;
}
