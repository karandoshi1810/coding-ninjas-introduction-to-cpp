#include<iostream>
#include<stack>

using namespace std;

struct Stack
{
    private:
    stack<int> st;
    public:
    void push(int val)
    {
        cout<<"Pushing val:"<<val<<endl;
        st.push(val);
        return;
    }

    void pop()
    {
        if(st.empty())
        {
            cout<<"Stack is empty..."<<endl;
        }
        cout<<"Popping:"<<st.top();
        st.pop();
        return;
    }

    void reverse()
    {
        cout<<"Reversing..."<<endl;
        if(st.empty())
        {
            return;
        }
        int curr = st.top();
        st.pop();
        reverse();
        cout<<"Insert at bottom:"<<curr<<endl;
        insertAtBottom(curr);
        return;
    }

    void insertAtBottom(int curr)
    {
        if(st.empty())
        {
            cout<<"Inserting at bottom:"<<curr<<endl;
            st.push(curr);
            return;
        }
        int x = st.top();
        cout<<"Popped value:"<<x<<endl;
        st.pop();
        insertAtBottom(curr);
        st.push(x);
        return;
    }

    void printStack()
    {
        if(st.empty())
        {
            cout<<"Stack is empty..."<<endl;
        }
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
};

int main()
{
    Stack st;
    st.push(2);
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(5);
    st.reverse();
    st.printStack();

    return 0;
}