/*
Next Smaller element
*/
#include <bits/stdc++.h>
using namespace std;

void display(vector<int>a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector<int> next_smaller_element(vector<int>a)
{
    vector<int>res(a.size());
    stack<int>s;
    for(int i=a.size()-1;i>=0;i--)
    {
        while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
        if(s.empty()) res[i]=-1;
        else res[i]=s.top();
        s.push(i);
    }
    return res;
}

int main()
{
    vector<int> a={2,5,1,9,8,4};
    display(a);
    vector<int> res=next_smaller_element(a);
    display(res);
}