/*
Sum of Subarray Ranges
You are given an integer array nums. The range of a subarray of nums is the difference 
between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Example 3:
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
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

vector<int> previous_greater_element(vector<int>a)
{
    vector<int>res(a.size());
    stack<int>s;
    for(int i=0;i<a.size();i++)
    {
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
        if(s.empty()) res[i]=-1;
        else res[i]=s.top();
        s.push(i);
    }
    return res;
}

vector<int> next_greater_element(vector<int>a)
{
    vector<int>res(a.size());
    stack<int>s;
    for(int i=a.size()-1;i>=0;i--)
    {
        while(!s.empty()&&a[s.top()]<a[i]) s.pop();
        if(s.size()==0) res[i]=a.size();
        else res[i]=s.top();
        s.push(i);
    }
    return res;
}

int maxSum(vector<int>a)
{
    vector<int>pse=previous_greater_element(a);
    vector<int>nse=next_greater_element(a);
    long long total=0;
    for(int i=0;i<a.size();i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        total=total+(left*right*a[i]);
    }
    return total;
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

int minSum(vector<int>a)
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
    display(a);
    cout<<maxSum(a)<<endl<<minSum(a)<<endl;
    cout<<maxSum(a)-minSum(a)<<endl;
}