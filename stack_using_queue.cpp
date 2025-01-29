#include <bits/stdc++.h>
using namespace std;

class stackUsingQueue
{
    public:
    queue<int>q;
    void pushStack(int val)
    {
        q.push(val);
        for(int i=1;i<q.size();i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void popStack() 
    {
        q.pop();
    }
    int topStack() 
    {
        return q.front();
    }
    int sizeStack() 
    {
        return q.size();
    }
};

int main()
{
    stackUsingQueue ob;
    ob.pushStack(7);
    ob.pushStack(2);
    ob.pushStack(3);
    ob.pushStack(6);
    cout<<ob.topStack()<<" ";
    ob.popStack();
    cout<<ob.topStack()<<" ";
    ob.popStack();
    ob.popStack();
    cout<<ob.topStack()<<" ";
}