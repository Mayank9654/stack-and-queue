/*
Remove K Digits
Given string num representing a non-negative integer num, and an integer k, return the smallest 
possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
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

string removekdigits(string a, int k)
{
    stack<char>s;
    string res="";
    for(int i=0;i<a.size();i++)
    {
        while(!s.empty()&&k>0&&(s.top()-'0')>(a[i]-'0')) 
        {
            s.pop();
            k--;
        }
        s.push(a[i]);
    }
    while(k>0){s.pop();k--;}
    if(s.empty()) return "0";
    while(!s.empty())
    {
        res=res+s.top();
        s.pop();
    }
    while(res.size()!=0&&res.back()=='0') res.pop_back();
	reverse(res.begin(), res.end());
    if(res=="") return "0";
    return res;
}

int main()
{
    string a="1432219";
    cout<<a<<endl<<removekdigits(a,3)<<endl;
}