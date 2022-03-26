#include <iostream>
#include <list>
#include <cstdarg>

using namespace std;

///The class object stores information about the operation.
class Log
{
public:
    string funcName;
    int val;

    Log(string funcName, int val):
            val(val),
            funcName(funcName){}
    ~Log(){}
};

class VersionedStack
{
private:
    list<int> listCurrent;
    list<int> listBase;
    list<Log> logs;

    ///Copying StackOut to StackIn.
    void CopyStack(list<int>& stackOut, list<int>& stackIn)
    {
        stackIn.clear();
        for(auto elem : stackOut)
            stackIn.push_back(elem);
    }

    ///Saving log.
    void SafeChange(const string& funcName, int val)
    {
        auto log = Log(funcName, val);
        logs.push_back(log);
    }

    ///Deleting last log.
    void DeleteLastLog()
    {
        logs.pop_back();
    }

public:
    VersionedStack(){}
    ~VersionedStack(){}
    VersionedStack(int n, ...)
    {
        va_list list;
        va_start(list, n);
        for(int i = 0; i < n; i++)
            listCurrent.push_back(va_arg(list, int));
        va_end(list);
        CopyStack(listCurrent, listBase);
    }

    ///Returns and delete top element of the stack.
    int Pop()
    {
        int result = listCurrent.back();
        listCurrent.pop_back();
        SafeChange("Pop", result);
        return result;
    }

    ///Adds element in the stack.
    void Push(int elem)
    {
        listCurrent.push_back(elem);
        SafeChange("Push", elem);
    }

    ///Returning to state 'version'.
    int Rollback(int version)
    {
        if(version > logs.size())
            return -1;

        SafeChange("Rollback", version);
        CopyStack(listBase, listCurrent);

        int i = 0;
        for(auto log : logs)
        {
            if (i > version)
                break;
            if(log.funcName == "Pop")
                Pop();
            else if (log.funcName == "Push")
                Push(log.val);
            else
                Rollback(log.val);
            DeleteLastLog();
            i++;
        }
        return 0;
    }

    ///Deleting the entire history of changes.
    void Forget()
    {
        logs.clear();
        CopyStack(listCurrent, listBase);
    }

    ///Printing elements starting from the top element.
    void Print()
    {
        string result;
        for(auto elem : listCurrent)
            result =  to_string(elem) + " " + result;
        cout << result << endl;
    }
};