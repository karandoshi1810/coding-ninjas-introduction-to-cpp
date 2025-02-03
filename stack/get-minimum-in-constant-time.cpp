#include <iostream>
#include <stack>

using namespace std;

struct Stack
{
    stack<int> elements;
    stack<int> min;

    void push(int val)
    {
        if(elements.empty()&&min.empty())
        {
            elements.push(val);
            min.push(val);
            return;
        }
        else if(!elements.empty() && !min.empty() && min.top() > val)
        {
            elements.push(val);
            min.push(val);
            return;
        }
    }

    void pop()
    {
        if((elements.empty() || min.empty()) || (elements.empty() && min.empty()))
        {
            cout<<"Stack is empty... Please consider adding some elements"<<endl;
            return;
        }
        else
        {
            cout<<"Popping:"<<elements.top()<<" Min:"<<min.top()<<endl;
            elements.pop();
            min.pop();
            return;
        }
    }


    void getMin()
    {
        if((elements.empty() || min.empty()) || (elements.empty() && min.empty()))
        {
            cout<<"Stack is empty... Please consider adding some elements"<<endl;
            return;
        }
        else
        {
            cout<<" Min:"<<min.top()<<endl;
            return;
        }
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(6);
    s.getMin();
    s.push(4);
    s.getMin();
    s.push(1);
    s.getMin();
    s.push(5);
    return 0;
}