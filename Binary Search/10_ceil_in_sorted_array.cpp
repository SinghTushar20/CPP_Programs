// CEIL in sorted array is the number which is next greater than or equal element present 
// in the array

#include<bits/stdc++.h>
using namespace std;
int ceilInSortedArray(vector<int> &nums, int target)
{
    int strt = 0, end = nums.size()-1;
    int res = -1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == target)return mid;
        else if(target > nums[mid])strt = mid+1;
        else if(target < nums[mid])
        {
            end = mid-1;
            res = mid;
        } 
    }
    return res;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)cin >> nums[i];
    int key;
    while(cin >> key)cout << ceilInSortedArray(nums,key) << "\n";
}
