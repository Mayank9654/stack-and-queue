/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
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

void minsum_bruteforce(vector<int>a)
{
    int sum=0;
    for(int i=0;i<a.size();i++)
    {
        int min_element=a[i];
        for(int j=i;j<a.size();j++)
        {
            min_element=min(min_element,a[j]);
            sum=sum+min_element;
        }
    }
    cout<<sum<<endl;
}

vector<int> previous_smaller_element(vector<int>a)
{
    vector<int>res(a.size());
    stack<int>s;
    for(int i=0;i<a.size();i++)
    {
        while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
        if(s.empty()) res[i]=-1;
        else res[i]=s.top();
        s.push(i);
    }
    return res;
}

vector<int> next_smaller_element(vector<int>a)
{
    vector<int>res(a.size());
    stack<int>s;
    for(int i=a.size()-1;i>=0;i--)
    {
        while(!s.empty()&&a[s.top()]>a[i]) s.pop();
        if(s.size()==0) res[i]=a.size();
        else res[i]=s.top();
        s.push(i);
    }
    return res;
}

long long minimumsum(vector<int>a)
{
    vector<int>pse=previous_smaller_element(a);
    vector<int>nse=next_smaller_element(a);
    long long total=0;
    for(int i=0;i<a.size();i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        total=total+(left*right*a[i]);
    }
    return total;
}

int main()
{
    vector<int>a={3,1,2,4};
    vector<int>b={1,1};
    display(a);
    cout<<minimumsum(a)<<endl;
    display(b);
    cout<<minimumsum(b)<<endl;
}