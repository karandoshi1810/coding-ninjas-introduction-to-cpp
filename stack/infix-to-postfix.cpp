#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precdence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

void infixToPostfix(string expression)
{
    stack<char> st;
    string result = "";
    for (unsigned int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                char top = st.top();
                result += top;
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precdence(c) <= precdence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    cout<<"Emptying the stack"<<endl;
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << "After Postfix:" << endl;
    cout << result << endl;
}

int main()
{
    //string s = "a+b*(c^d-e)^(f+g*h)-i";
    string s = "x+y*z/w+u";
    infixToPostfix(s);
    return 0;
}
