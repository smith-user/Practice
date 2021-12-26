#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

using namespace std;

struct CellTower
{
    string name;
    int x = 0;
    int y = 0;
    int radius = 0;
    bool reliable = false;
};

bool reliableCommunication(CellTower tower, int xSubscriber, int ySubscriber)
{
    double distanceSubscriber = sqrt( pow(xSubscriber - tower.x, 2) + pow(ySubscriber - tower.y, 2) );
    return distanceSubscriber <= tower.radius;
}

int main() {
    ifstream inputFile("INPUT.TXT");
    ofstream outputFile("OUTPUT.TXT");
    if (!inputFile) {
        outputFile << "File Reading Error!" << endl;
        return 1;
    }
    
    int countCellTower;
    string name;
    int x;
    int y;
    int radius;
    inputFile >> countCellTower;
    auto *cellTowers = new CellTower[countCellTower];
    map <string, int> nameOperators;
    for (int i = 0; i < countCellTower; i++)
    {
        inputFile >> name;
        inputFile >> x;
        inputFile >> y;
        inputFile >> radius;
        cellTowers[i] = { name, x, y, radius};

    }
    int xSubscriber, ySubscriber;
    inputFile >> xSubscriber;
    inputFile >> ySubscriber;
    inputFile.close();

    map<string, bool> operators;
    for (int i = 0; i < countCellTower; i++)
    {
        cellTowers[i].reliable = reliableCommunication(cellTowers[i], xSubscriber, ySubscriber);
        operators[cellTowers[i].name] = false;
    }

    /* OUTPUT */
    outputFile << operators.size() << endl;
    for (int i = 0; i < countCellTower; i++)
    {
        if (operators[cellTowers[i].name])
            continue;
        int count = 0;
        for (int j = i; j < countCellTower; j++)
            if (cellTowers[i].name == cellTowers[j].name && cellTowers[j].reliable)
                count++;
        operators[cellTowers[i].name] = true;
        outputFile << cellTowers[i].name << " " << count << endl;
    }
    outputFile.close();
    return 0;
}