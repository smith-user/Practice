#include <iostream>
#include <vector>

using namespace std;

enum class Suit { Diamonds, Hearts, Clubs, Spades };
enum class Value { Six, Seven, Eight, Nine, Ten, J, Q, K, A };

class Card
{
public:
    Suit suit;
    Value value;
    bool trump = false;

    Card() {};
    Card(Suit suit, Value value):
        suit(suit),
        value(value)
    {}
    ~Card() {};
};

class Bank {
    vector <Card> bank;

public:
    Bank() {
        Card temp[36];
        int i = 0;
        for (int n = 0; n < 9; n++)
            for (int s = 0; s < 4; s++)
                temp[i] = Card((Suit)s, (Value)n );
        int used[36] = {0};
        for (int j = 0; j < 36; j++) {
            int n = rand() % 36;
            while (used[n] == 1)
                n = rand() % 36;
            bank[j] = temp[n];
        }
        auto trump = bank.back();
        for (int j = 0; j < 36; j++)
            bank[j].trump = bank[j].suit == trump.suit;
    }
    ~Bank() {};

    Card TakeCard() {
        Card card = bank.front();
        bank.erase(bank.begin());
        return card;
    }
};

class Player
{
public:
    vector<Card> hand;
    Player(Bank bank)
    {
        for(int i = 0; i < 6; i++)
            hand.push_back(bank.TakeCard());
    }
    ~Player() {};

    void Collect(Bank bank)
    {
        hand.push_back(bank.TakeCard());
    }

    void Collect(Card card)
    {
        hand.push_back(card);
    }
};


class Game {
    vector<Card> desk;
public:
    Game() {};
    ~Game() {};
    void Move(Card card) {
        desk.push_back(card);
    }

    int Answer(Card card) {
        auto deskCard = desk.back();
        if ((card.suit == deskCard.suit and card.value > deskCard.value) \
        or (card.trump and not deskCard.trump) ){
            desk.push_back(card);
            return 0;
        }
        else
            return -1;
    }
};