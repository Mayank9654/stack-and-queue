#include <bits/stdc++.h>
using namespace std;

class queueUsingStack
{
    public:
    stack<int>s1,s2;
    void pushQueue(int val)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void popQueue() 
    {
        s1.pop();
    }
    int topQueue() 
    {
        return s1.top();
    }
    int sizeQueue() 
    {
        return s1.size();
    }
};

class queueUsingStackOptimised
{
    public:
    stack<int>s1,s2;
    void pushQueue(int val)
    {
        s1.push(val);
    }
    void popQueue() 
    {
        if(!s2.empty()) s2.pop();
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int topQueue() 
    {
        if(!s2.empty()) return s2.top();
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    int sizeQueue() 
    {
        return s2.size();
    }
};


int main()
{
    queueUsingStackOptimised ob;
    ob.pushQueue(7);
    ob.pushQueue(2);
    ob.pushQueue(3);
    ob.pushQueue(6);
    cout<<ob.topQueue()<<" ";
    ob.popQueue();
    cout<<ob.topQueue()<<" ";
    ob.popQueue();
    ob.popQueue();
    cout<<ob.topQueue()<<" ";
    cout<<endl<<ob.sizeQueue()<<endl;
}