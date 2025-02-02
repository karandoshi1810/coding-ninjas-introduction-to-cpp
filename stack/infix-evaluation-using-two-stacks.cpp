#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

unsigned int calculationUtil(unsigned int op1, unsigned int op2, char opr)
{
    switch (opr)
    {
    case '+':
    {
        return op2 + op1;
        break;
    }
    case '-':
    {
        return op2 - op1;
        break;
    }
    case '*':
    {
        return op2 * op1;
        break;
    }
    case '/':
    {
        if (op1 == 0)
        {
            cout << "Cannot divide by 0";
            return 0;
            break;
        }
        return op2 / op1;
        break;
    }
    case '^':
    {
        return (unsigned int)(pow(op2, op1));
        break;
    }
    }
    return 0;
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    return -1;
}

void infixToPostfix(string s)
{
    stack<unsigned int> operand;
    stack<char> optr;

    for (unsigned int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        cout<<"Current operator:"<<c<<endl;
        if (isdigit(c))
        {
            unsigned int num = 0;
            while (isdigit(c))
            {
                num = num * 10 + (unsigned int)(c - '0');
                i++;
                if (i < s.length())
                {
                    c = s[i];
                }
                else
                {
                    break;
                }
            }
            cout<<"Pushing an operand:"<<num<<endl;
            i--;
            operand.push(num);
        }
        else if (c == '(')
        {
            cout<<"Pushing an operator:"<<c<<endl;
            optr.push(c);
        }
        else if (s[i] == ')')
        {
            while (optr.top() != '(')
            {
                unsigned int op1 = operand.top();
                operand.pop();
                unsigned int op2 = operand.top();
                operand.pop();
                char opr = optr.top();
                optr.pop();
                unsigned int output = calculationUtil(op1, op2, opr);
                cout << "opd1:" << op1 << " opd2:" << op2 << " optr:" << opr << " result:" << output <<endl;
                operand.push(output);
            }

            optr.pop();
        }
        else
        {
            while (!optr.empty() && precedence(c) <= precedence(optr.top()))
            {
                unsigned int op1 = operand.top();
                operand.pop();
                unsigned int op2 = operand.top();
                operand.pop();
                char opr = optr.top();
                optr.pop();
                unsigned int output = calculationUtil(op1, op2, opr);
                cout << "opd1:" << op1 << " opd2:" << op2 << " optr:" << opr << " result:" << output << endl;
                operand.push(output);
            }
            cout<<"Pushing an operator:"<<c<<endl;
            optr.push(c);
        }
    }

    while (!optr.empty())
    {
        unsigned int op1 = operand.top();
        operand.pop();
        unsigned int op2 = operand.top();
        operand.pop();
        char opr = optr.top();
        optr.pop();
        unsigned int output = calculationUtil(op1, op2, opr);
        cout << "opd1:" << op1 << " opd2:" << op2 << " optr:" << opr << " result:" << output << endl;
        operand.push(output);
    }

    cout << "Evaluated output:" << operand.top() << endl;
    operand.pop();
}

int main()
{
    string s = "2*(5*(3+6))/5-2";
    infixToPostfix(s);
    return 0;
}
