/*
Nearest Greater to left
*/
#include <bits/stdc++.h>
using namespace std;
void display(vector<int> &v)
{
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> a = {7,5,4,9,2};
    int n=a.size();
    vector<int> v;
    stack<int> s;
    for(int i = 0;i<n;i++)
    {
        if(s.size()==0)
        {
            v.push_back(-1);
        }
        else if(s.size()>0&&s.top()>a[i])
        {
            v.push_back(s.top());
        }
        else{
            while(s.size()!=0&&s.top()<=a[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }

        }
        s.push(a[i]);
    }
    display(v);
return 0;
}