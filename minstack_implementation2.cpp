/*
Minstack implementation using extra space
*/
#include <bits/stdc++.h>
using namespace std;
int minEle = 0;
stack<int> s;
int getMin()
{
    if (s.size() == 0)
        return -1;

    return minEle;
}

void push(int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        minEle = x;
    }
    else
    {
        if (x >= minEle)
        {
            s.push(x);
        }
        else // (x<minEle)
        {
            s.push((2 * x) - minEle);
            minEle = x;
        }
    }
}
void pop(void)
{
    if (s.size() == 0)
    {
        cout<<-1<<endl;
    }
    else
    {
        if (s.top() >= minEle)
        {
            s.pop();
        }
        else // (s.top()<minEle)
        {
            minEle = 2 * minEle - s.top();
            s.pop();
        }
    }
}
int top()
{
    if(s.size()==0)
    {
        return -1;
    }
    else
    {
        if(s.top()>=minEle)
        {
            return s.top();
        }
        else // (s.top()<minEle)
        {
            return minEle;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    return 0;
}