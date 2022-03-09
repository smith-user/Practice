class Ship
{
    int hit = 0;
    int deck = 0;
public:
    Ship() = default;
    Ship(int deck):
    deck(deck){}
    ~Ship() = default;

    bool Shoot()
    {
        hit++;
        return hit == deck;
    }

    bool isKill() { return hit == deck; }
};

class Cell
{
public:
    Ship* ship;
    bool bShip = false;
    bool hit = false;
    bool miss = false;

    Cell():
        ship(nullptr){}
    Cell(Ship& ship):
        ship(&ship),
        bShip(true){}

    int Shoot()
    {
        hit = bShip;
        if(hit) {
            if(ship->Shoot())
                return 1; // Kill
            else
                return 0; // Hurt
        } else {
            miss = true;
            return -1; // Miss
        }
    }
    ~Cell() = default;
};

class Field
{
public:
    Cell field[10][10];
    Field() = default;
    ~Field() = default;
};

class Player
{
    Ship ships[10];
    Field field;
public:
    Player()
    {
        int i = 0;
        for(int deck = 1; deck < 5; deck++)
            for(int k = 1; k <= 5 - deck; k++, i++)
                ships[i] = Ship(deck);
    };
    ~Player() = default;
};

