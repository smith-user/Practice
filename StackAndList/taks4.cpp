#include <iostream>

using namespace std;

///Linked List item.
class Node
{
public:
    int data;
    Node* pNext;
    Node(int data):
        data(data),
        pNext(nullptr){}
};

///Looped linked list.
class RoundOfStones
{
private:
    Node* pCurrent;
    Node* pEnd;

    ///Returning reference to stone with the maximum number less than the current one
    /// (else stone with the maximum number). Search from pNode to pCurrent.
    Node* MaxElem(Node* pNode)
    {
        Node* pResult = nullptr;
        Node* pMax = nullptr;
        while(pNode != pCurrent)
        {
            if(pNode->data < pCurrent->data and (!pResult or pNode->data > pResult->data))
                pResult = pNode;
            else if (!pMax or pNode->data > pMax->data)
                pMax = pNode;
            pNode = pNode->pNext;
        }
        if(pResult)
            return pResult;
        else
            return pMax;
    }

public:
    RoundOfStones()= default;
    ~RoundOfStones()
    {
        if(Empty())
            return;
        Node* pTemp = pCurrent;
        do {
            Node* pDelNode = pTemp;
            pTemp = pTemp->pNext;
            delete pDelNode;
        } while (pTemp != pCurrent);
    }

    ///Returns true if the round is empty.
    bool Empty() { return !pCurrent; }

    ///Adding stone in the round.
    void AddStone(int elem)
    {
        Node* pTemp = new Node(elem);
        if (Empty())
            pCurrent = pTemp;
        else
            pEnd->pNext = pTemp;
        pEnd = pTemp;
        pEnd->pNext = pCurrent;
    }

    ///Doing move.
    void Move()
    {
        //Taking three stones after the current one.
        Node* firstStoneTaken = pCurrent->pNext;                // The 1st stone in a hand.
        Node* thirdStoneTaken = pCurrent->pNext->pNext->pNext;  // The 3rd stone in a hand.
        pCurrent->pNext = thirdStoneTaken->pNext;               // Linking current with stone after 3rd.

        //Putting three stones after the maximum one.
        Node* pMaxStone = MaxElem(thirdStoneTaken->pNext);
        pCurrent = pMaxStone->pNext;                            // Now, next stone after the maximum one is current stone.
        pMaxStone->pNext = firstStoneTaken;                     // After maximum, put 1st stone. (Links of 1st with 2nd, 2nd with 3rd doesn't change)
        thirdStoneTaken->pNext = pCurrent;                      // After the 3rd stone laid, the current stone goes.
        pEnd = thirdStoneTaken;                                 // The 3rd stone is the last in the round.
    }

    ///Printing numbers clockwise starting from the current stone.
    void Print()
    {
        if(Empty())
            return;
        Node* pTemp = pCurrent;
        do {
            cout << pTemp->data << ' ';
            pTemp = pTemp->pNext;
        } while (pTemp != pCurrent);
        cout << endl;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    RoundOfStones stones = RoundOfStones();
    for(int i = 0; i < n; i++)
    {
        int stone;
        cin >> stone;
        stones.AddStone(stone);
    }
    for(int i = 0; i < m; i++)
        stones.Move();
    stones.Print();
    return 0;
};