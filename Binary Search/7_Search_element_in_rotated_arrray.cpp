#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int target, int low, int high)
{
    int strt = low, end = high;
    while(end >= strt)
    {
        int mid = strt + (end - strt)/2;
        if(nums[mid] == target)return mid;
        else if(target > nums[mid])strt = mid+1;
        else end = mid-1;
    }
    return -1;
}
int k_of_rotated_array(vector<int> &nums)
{
    int n = nums.size(), strt = 0, end = n-1;
    int res = -1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[strt] <= nums[end])return strt;
        if(nums[mid] < nums[(mid-1+n)%n] && nums[mid] < nums[(mid+1)%n])return mid;
        if(nums[mid] >= nums[strt])strt = mid+1;
        if(nums[mid] <= nums[end])end = mid-1;
    }
    return res;
}
int findInRotatedArrray(vector<int> &nums, int target)
{
    int center = k_of_rotated_array(nums);
    if(center)
    {
        int res1 = binarySearch(nums,target,0,center-1);
        int res2 = binarySearch(nums,target,center, nums.size()-1);
        if(res1 != -1)return res1;
        if(res2 != -1)return res2;
        return -1;      
    }
    return binarySearch(nums,target,0,nums.size()-1);
}
    
signed main()
{
    int n;
    cin >> n;
    vector<int> nums;
    while(n--)
    {
        int k;
        cin >> k;
        nums.push_back(k);
    }
    int key;
    while(cin >> key)cout << k_of_rotated_array(nums) << " " << findInRotatedArrray(nums,key) << "\n";

}
