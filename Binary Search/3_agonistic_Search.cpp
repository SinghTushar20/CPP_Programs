// In agonostic search we do not know weather the array is sorted in ascending order 
// decending order but it is sure that the array is sorted.

//APROACH : We will first check by comparing the first and last element

#include<bits/stdc++.h>
using namespace std;
bool isAcending(vector<int> &nums)
{
    return nums[nums.size()-1] >= nums[0];
}
int binarySearch(vector<int> &nums, int target)
{
    int strt = 0, end = nums.size()-1;
    if(isAcending(nums))
    {
        while(end >= strt)
        {
            int mid = strt + (end-strt)/2;
            if(nums[mid]== target)return mid;
            else if(target > nums[mid])strt = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    else 
    {
        while(end >= strt)
        {
            int mid = strt + (end-strt)/2;
            if(nums[mid] == target)return mid;
            else if(target > nums[mid])end = mid-1;
            else strt = mid+1;
        }
        return -1;
    }
    return -1;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)cin >> nums[i];
    int target;
    while(cin >> target)cout << isAcending(nums) << " " << binarySearch(nums, target) << "\n";

}
