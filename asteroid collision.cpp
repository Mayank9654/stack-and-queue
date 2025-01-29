/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction 
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/

#include <bits/stdc++.h>
using namespace std;

void asteroidcollision(vector<int> a)
{
    list<int> st;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>0)
            st.push_back(a[i]);
        else
        {
            while(!st.empty()&&st.back()>0&&st.back()<abs(a[i]))
                st.pop_back();
            if(!st.empty()&&st.back()==abs(a[i]))
                st.pop_back();
            else if(st.empty()||st.back()<0)
                st.push_back(a[i]);
        }
    }
    for(auto val:st)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> a={4,7,1,2,-3,-7,17,15,-16};
    asteroidcollision(a);
}