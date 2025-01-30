/*
Maximum area of a histogram
*/
#include <bits/stdc++.h>
using namespace std;

// Utility function to display a vector
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

// Function to calculate the maximum area of the histogram
int maxArea(vector<int> a, int n)
{
    vector<int> left = previous_smaller_element(a);
    vector<int> right = next_smaller_element(a);

    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;  // Calculate width of the rectangle
        int area = a[i] * width;            // Calculate area of the rectangle
        max_area = max(max_area, area);     // Update maximum area
    }
    return max_area;
}

// Driver function
int main()
{
    vector<int> a = {5, 2, 4, 7, 8};
    int n = a.size();
    cout << "Maximum Area: " << maxArea(a, n) << endl;
    return 0;
}
