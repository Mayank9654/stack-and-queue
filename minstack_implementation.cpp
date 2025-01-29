/*
Minstack Implementation using extra space
*/
#include <bits/stdc++.h>
using namespace std;
stack<int> s,ss;
void push(int a)
{
 s.push(a);
 if(ss.size()==0||ss.top()>=a)
 {
     ss.push(a);
 }   
 
}
int pop()
{
    if(s.size()==0)
    {
        return -1;
    }
    int ans  =s.top();
    s.pop();
    if((ss.top()==ans))
    {
        ss.pop();
    }
    return ans;
}
int getMin()
{
    if(ss.size()==0)
    {
        return -1;
    }
    return ss.top();
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
    cout<<a[0]<<" "<<a[1]<<endl;
    push(a[0]);
    push(a[1]);
    return 0;
}