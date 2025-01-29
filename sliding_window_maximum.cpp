/*
Sliding Window Maximum
Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position. Return the max sliding window.

Example 1:
Input: arr = [4,0,-1,3,5,3,6,8], k = 3
Output: [4,3,5,5,6,8]

Explanation: 
Window position                   Max
------------------------         -----
[4  0  -1] 3  5  3  6  8           4
 4 [0  -1  3] 5  3  6  8           3
 4  0 [-1  3  5] 3  6  8           5
 4  0  -1 [3  5  3] 6  8           5
 4  0  -1  3 [5  3  6] 8           6
 4  0  -1  3  5 [3  6  8]          8

For each window of size k=3, we find the maximum element in the window and add it to our output array.

Example 2:
Input: arr= [20,25], k = 2
Output: [25]
Explanation: There’s just one window is size 2 that is possible and the maximum of the two elements is our answer.
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

void bruteforce(vector<int>a, int k)
{
    for(int i=0;i<=a.size()-k;i++)
    {
        int maxi=a[i];
        for(int j=i;j<i+k;j++)
        {
            maxi=max(maxi,a[j]);
        }
        cout<<maxi<<" ";
    }
    cout<<endl;
}

void optimised(vector<int>a, int k)
{
    deque<int>dq;
    for(int i=0;i<a.size();i++)
    {
        if(!dq.empty()&&dq.front()<=i-k) dq.pop_front();
        while(!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)
        {
            cout<<a[dq.front()]<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    vector<int>a={1,3,-1,-3,5,3,2,1,6};
    display(a);
    bruteforce(a,3);
    optimised(a,3);
}

