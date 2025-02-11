#include<iostream>
#include<queue>

using namespace std;

struct Queue
{
    private:
    queue<int>  q1,q2;
    public:
    void push(int x)
    {
        q1.push(x);
        return;
    }

    void pop()
    {
        if(q1.empty())
        {
            cout<<"Stack is empty..."<<endl;
            return;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int stackTop = q1.front();
        q1.pop();
        swap(q2,q1);
        cout<<"Popped element:"<<stackTop<<endl;
        return;
    }

    void top()
    {
        if(q1.empty())
        {
            cout<<"Stack is empty..."<<endl;
            return;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int stackTop = q1.front();
        q2.push(stackTop);
        q1.pop();
        swap(q2,q1);
        cout<<"Top element:"<<stackTop<<endl;
        return;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.top();
    q.pop();
    q.top();
    return 0;
}