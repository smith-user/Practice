#include <iostream>
#include <vector>

using namespace std;

class Domino
{
public:
    int half1;
    int half2;
};

class Bank {
    vector <Domino> bank;
public:
    Bank() {
        Domino temp[28];
        int i = 0;
        for(int h = 0; h < 7; h++)
            for(int l = h; l < 7; l++, i++)
            {
                temp[i].half1 = h;
                temp[i].half2 = l;
            }
        int used[28] = {0};
        for (int j = 0; j < 36; j++) {
            int n = rand() % 28;
            while (used[n] == 1)
                n = rand() % 28;
            bank.push_back(temp[n]);
        }
    }

    Domino TakeDomino() {
        Domino domino = bank.front();
        bank.erase(bank.begin());
        return domino;
    }
    ~Bank() {};
};

class Player
{
    vector <Domino> hand;
    Bank game;
public:
    Player(Bank bank):
        game(bank)
    {
        for(int i = 0; i < 8; i++)
            hand.push_back(game.TakeDomino());
    }
    ~Player() {};

    void Collect() { hand.push_back(game.TakeDomino());  }
};

class Field
{
    int end1;
    int end2;
public:
    Field(Domino firstDomino):
        end1(firstDomino.half1),
        end2(firstDomino.half2)
        {}

    ~Field() {};

    int MakeMove(Domino domino)
    {
        if(end1 == domino.half1)
            end1 = domino.half2;
        else if(end1 == domino.half2)
            end1 = domino.half1;
        else if(end2 == domino.half1)
            end2 = domino.half2;
        else if(end2 == domino.half2)
            end2 = domino.half1;
        else
            return -1;
        return 0;
    }
};