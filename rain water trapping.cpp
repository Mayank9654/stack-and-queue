// Trapping Rainwater
#include <bits/stdc++.h>
using namespace std;

int rainwatertrapped(vector<int> a)
{
    int total = 0;
    // Edge case: if the size is less than 3, no water can be trapped
    if (a.size() < 3) return 0;

    // Prefix sum array to store the max height to the left of each index
    vector<int> prefixsum(a.size());
    prefixsum[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        prefixsum[i] = max(prefixsum[i - 1], a[i]);
    }

    // Suffix sum array to store the max height to the right of each index
    vector<int> suffixsum(a.size());
    suffixsum[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--) {
        suffixsum[i] = max(suffixsum[i + 1], a[i]);
    }

    // Calculate the total trapped water
    for (int i = 0; i < a.size(); i++) {
        total += min(prefixsum[i], suffixsum[i]) - a[i];
    }

    return total;
}

int rainwatertrappedoptimised(vector<int> a)
{
    int lmax=0,rmax=0,total=0,l=0,r=a.size()-1;
    while(l<r)
    {
        if(a[l]<=a[r])
        {
            if(lmax>a[l])
                total+=lmax-a[l];
            else
                lmax=a[l];
            l++;
        }
        else
        {
            if(rmax>a[r])
                total+=rmax-a[r];
            else
                rmax=a[r];
            r=r-1;
        }
    }
    return total;
}

int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainwatertrappedoptimised(a) << endl; // Output: 6
    return 0;
}
