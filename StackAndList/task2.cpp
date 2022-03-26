#include <stack>
#include <cstdarg>

using namespace std;

class Queue
{
private:
    stack<int> stackOut;
    stack<int> stackIn;

    void Move()
    {
        while(!stackIn.empty())
        {
            int elem = stackIn.top();
            stackOut.push(elem);
            stackIn.pop();
        }
    }
public:
    Queue()= default;
    ~Queue()= default;

    Queue(int n, ...)
    {
        va_list list;
        va_start(list, n);
        for(int i = 0; i < n; i++)
            Push(va_arg(list,int));
        va_end(list);
    }

    ///Adds element in the queue.
    void Push(int elem)
    {
        stackIn.push(elem);
    }

    ///Returns and delete first element of the queue.
    int Pop()
    {
        int elem = Front();
        stackOut.pop();
        return elem;
    }

    ///Returns first element of the queue.
    int Front()
    {
        if(stackOut.empty())
            Move();
        return stackOut.top();
    }

    ///Returns true if the queue is empty.
    bool IsEmpty()
    {
        return stackIn.empty() and stackOut.empty();
    }

    ///Returns the number of elements in the queue.
    size_t Size()
    {
        return stackIn.size() + stackOut.size();
    }
};