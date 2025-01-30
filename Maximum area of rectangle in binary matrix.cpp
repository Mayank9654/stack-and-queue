/*
Maximum area of a rectangle in a binary matrix
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
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
// Function to calculate the indices of the previous smaller element for each bar
vector<int> previous_smaller_element(vector<int> a)
{
    vector<int> res(a.size());
    stack<int> s;

    for (int i = 0; i < a.size(); i++)
    {
        while (!s.empty() && a[s.top()] >= a[i]) 
            s.pop();

        res[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }
    return res;
}

// Function to calculate the indices of the next smaller element for each bar
vector<int> next_smaller_element(vector<int> a)
{
    vector<int> res(a.size());
    stack<int> s;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i]) 
            s.pop();

        res[i] = (s.empty()) ? a.size() : s.top();  // Set to 'a.size()' if no smaller element exists
        s.push(i);
    }
    return res;
}

int maxArea(vector<int> a, int n)
{
    vector<int> left, right, area, width;
    left = previous_smaller_element(a);
    right = next_smaller_element(a);
    for (int i = 0; i < n; i++)
    {
        width.push_back((right[i] - left[i]) - 1);
    }
    // display(width);
    for (int i = 0; i < n; i++)
    {
        area.push_back(a[i] * width[i]);
    }
    // display(area);
    return *max_element(area.begin(), area.end());
    // sort(area.begin(), area.end());
    // return area[n - 1];
}

int main()
{
    vector<vector<int>>a={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,0,0,1}};
    int n=a.size();
    int m=a[0].size();
    vector<int> v, max;
    for (int j = 0; j < n; j++)
    {
        v.push_back(a[0][j]);
        //    ar.push_back( maxAH(v,m));
    }
    // display(v);
    max.push_back(maxArea(v, n));
    // cout<<MAH(v,n);
    // cout << endl;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + a[i][j];
            }
        }
        // display(v);
        max.push_back(maxArea(v, n));
        // cout<<MAH(v,n);
        // cout << endl;
    }
    cout << *max_element(max.begin(), max.end()) << endl;
    return 0;
}