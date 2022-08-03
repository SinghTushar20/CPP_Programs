// NEARLY SORTED ARRAY MEANS THE ELEMENT AT POSITION i may be present at POSITION 
// (i+1) or i or (i-1).
#include<bits/stdc++.h>
using namespace std;
int searchInNearlySortedArray(vector<int> &nums, int target)
{
    int n = nums.size(), strt = 0, end = n-1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == target)return mid;
        if(nums[(mid+1)%n] == target)return (mid+1)%n;
        if(nums[(mid+n-1)%n] == target)return (mid+n-1)%n;
        else if(nums[mid] < target)strt = mid+2;
        else if(nums[mid] > target)end = mid-2;
    }
    return -1;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> v;
    while(n--)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }
    int key;
    while(cin >> key)cout << searchInNearlySortedArray(v,key) << "\n";
}
