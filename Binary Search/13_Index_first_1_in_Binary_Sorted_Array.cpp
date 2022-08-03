// We will be given a BINARY SORTED ARRAY (monotonic array with 0's ans 1's)
// Return the index of first occurrence of 1(where the  monotonic curve is changing)

// APPROACH : This problem is combination of infinite sorted array and first occurrence

#include<bits/stdc++.h>
using namespace std;
pair<int,int> highLow(vector<bool> &nums)
{
    int strt = 0, end = 1;
    while(nums[end] == false)
    {
        strt = end;
        end *= 2;
    }
    return {strt, end}; 
}
int firstOccurrence(vector<bool> &nums, int high, int low)
{
    int strt = low, end = high;
    int res = -1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid])
        {
            res = mid;
            end = mid-1;
        }
        else if(!nums[strt])strt = mid+1;
        else if(nums[mid])end = mid-1;
    }
    return res;
}
int search(vector<bool> &nums)
{
    int l = highLow(nums).first, h = highLow(nums).second;
    return firstOccurrence(nums,h,l);
}

signed main()
{ 
    int n;
    cin >> n;
    vector<bool> v;
    for(int i = 0; i < n; i++)
    {
        bool k;
        cin >> k;
        v.push_back(k);
    }
    cout << search(v) << "\n";

}


