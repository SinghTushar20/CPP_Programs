// Minimum difference element is a problem in which we have to return a number which is
// closest to a goven target number 

// Approach : If we are searching a number in binary search and if the number is not 
// present in the array 
// At the end of the While loop of binary search high and low are the neighbouring positon

#include<bits/stdc++.h>
using namespace std;
int closestNumber(vector<int> &nums, int target)
{
    int strt = 0, end = nums.size()-1;
    if(target < nums[strt])return nums[strt];
    else if(target > nums[end])return nums[end];
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == target)return nums[mid];
        else if(target > nums[mid])strt = mid+1;
        else end = mid-1;
    }
    return min(nums[end],nums[strt]);
}
signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)cin >> nums[i];
    int key;
    while(cin >> key)
    {
        cout << closestNumber(nums,key) << "\n"; 
    }

}
