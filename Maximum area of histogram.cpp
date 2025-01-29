/*
Maximum area of a histogram
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
vector<int> nsl(vector<int>a,int n)
{
    vector<int> left;
    stack<pair<int,int>> s1;
    for(int i=0;i<n;i++)
    {
        if(s1.size()==0)
        {
            left.push_back(-1);
        }
        else if(s1.size()!=0&&s1.top().first<a[i])
        {
            left.push_back(s1.top().second);
        }
        else
        {
            while(s1.size()!=0&&s1.top().first>=a[i])
            {
                s1.pop();
            }
             if (s1.size() == 0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(s1.top().second);
            }
        }
        s1.push({a[i],i});
    }
    display(left);
    return left;
}
vector<int> nsr(vector<int>a, int n)
{
    vector<int> right;
    stack<pair<int, int>> s2;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.size() == 0)
        {
            right.push_back(n);
        }
        else if (s2.size() != 0 && s2.top().first < a[i])
        {
            right.push_back(s2.top().second);
        }
        else
        {
            while (s2.size() != 0 && s2.top().first >= a[i])
            {
                s2.pop();
            }
            if (s2.size() == 0)
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(s2.top().second);
            }
        }
        s2.push({a[i], i});
    }
    reverse(right.begin(),right.end());
    display(right);
    return right;
}
int maxArea(vector<int>a, int n)
{
    vector<int> left, right, area, width;
    left = nsl(a, n);
    right = nsr(a, n);
    for (int i = 0; i < n; i++)
    {
        width.push_back((right[i] - left[i]) - 1);
    }
    display(width);
    for (int i = 0; i < n; i++)
    {
        area.push_back (a[i] * width[i]);
    }
    display(area);
    sort(area.begin(), area.end());
    return area[n - 1];
}
int main()
{
    vector<int> a={5,2,4,7,8};
    int n=a.size();
    cout<<maxArea(a,n)<<endl;
    return 0;
}