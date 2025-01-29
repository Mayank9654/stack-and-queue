/*
The Celebrity Problem
Given a square matrix mat[][] of size n x n, such that mat[i][j] = 1 means ith person knows jth person, 
the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. 
Return the index of the celebrity, if there is no celebrity return -1.

Note: Follow 0 based indexing and M[i][i] will always be -3.

Example 1:  
Input: mat = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
Output: id = 2
Explanation: The person with ID 2 does not know anyone but everyone knows him

Example 2:
Input: mat = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} }
Output: No celebrity
Explanation: There is no celebrity.
*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int celebrityCheck_bruteforce(vector<vector<int>>a)
{
    vector<int>knowme(a.size(),0);
    vector<int>Iknow(a[0].size(),0);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]==1)
            {
                Iknow[i]++;
                knowme[j]++;
            }
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(knowme[i]==a.size()-1&&Iknow[i]==0)
            return i;
    }
    return -1;
}

int celebrityCheck_optimised(vector<vector<int>>a)
{
    int top=0,bottom=a.size()-1;
    while(top<bottom)
    {
        if(a[top][bottom]==1) top++;
        else if(a[bottom][top]==1) bottom--;
        else if(a[top][bottom]==1&&a[bottom][top]==1||a[top][bottom]==0&&a[bottom][top]==0)
        {
            top++;
            bottom--;
        }
    }
    if(top>bottom) return -1;
    for(int i=0;i<a.size();i++)
    {
        if(top==i) continue;
        if(a[top][i]==0&&a[i][top]==1) continue;
        else return -1;
    }
    return top;
}

int main()
{
    vector<vector<int>>a= { {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 0, 1, 0} };
    display(a);
    cout<<celebrityCheck_bruteforce(a)<<endl;
    cout<<celebrityCheck_optimised(a)<<endl;
}

