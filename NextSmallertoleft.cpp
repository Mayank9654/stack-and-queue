/*
Nearest Smaller to left
*/
#include <bits/stdc++.h>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    vector<int> a={5,2,4,7,8};
    vector<int> v;
    int n=a.size();
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if(s.size()!=0&&s.top()<a[i])
        {
            v.push_back(s.top());
        }
        else{
            while (s.size() > 0 && s.top() >= a[i])
            {
                s.pop();
            }
            if (s.size() == 0)
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