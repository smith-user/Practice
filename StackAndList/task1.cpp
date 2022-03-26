#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

double doOperation(char oper, double num1, double num2) {
    double result;
    switch (oper) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '^':
            result = pow(num1, num2);
            break;
    }
    return result;
}

int getPriority(char c) {
    int p;
    switch (c)
    {
        case '+':
        case '-':
            p = 0;
            break;
        case '*':
        case '/':
            p = 1;
            break;
        case '^':
            p = 2;
            break;
    }
    return p;
}

string getReversePolishNotation(const string& input)
{
    stack<char> st;
    string output;
    for(auto symbol : input) {
        if (isdigit(symbol))
            output+=symbol;
        else if ((symbol == '(') or (symbol == ')'))
        {
            if (symbol == '(')
                st.push(symbol);
            else
            {
                while (st.top() != '(')
                {
                    output+=st.top();
                    st.pop();
                }
                st.pop();
            }
        }
        else {
            while ((!st.empty()) and\
            ((getPriority(symbol) <= getPriority(st.top()))\
            or (symbol == '^' && getPriority(symbol) < getPriority(st.top()))))
            {
                output+=st.top();
                st.pop();
            }
            st.push(symbol);
        }
    }
    while (!st.empty())
    {
        output+=st.top();
        st.pop();
    }

    return output;
}

double calculate(string sRPL)
{
    stack<double> num;
    for (auto elem : sRPL)
    {
        if (isdigit(elem))
            num.push(int(elem - 48));
        else
        {
            double num1 = num.top();
            num.pop();
            double num2 = num.top();
            num.pop();
            num.push(doOperation(elem,num2,num1));
        }
    }
    return num.top();
}

int main() {
    string input;
    cin >> input;
    string sRPL = getReversePolishNotation(input);
    double result = calculate(sRPL);
    cout << sRPL << " = " << result << endl;
}