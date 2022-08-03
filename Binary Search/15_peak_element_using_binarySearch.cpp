// This problem belongs to BINARY SEARCH IN UNSORTED ARRAY (BINARY SEARCH ON ANSWER CONCEPT)
// In this we checked for the peak element which is strictly greater than the neighbouring 
// elements 
// Approach: Simply Checking the neigbours of mid and then moving to part in which there is 
// more possibility.


#include<bits/stdc++.h>
using namespace std;
int peakElement(vector<int> &nums)
{
    int n = nums.size();
    int strt = 0, end = nums.size()-1;
    if(n == 1)return 0;
    if(nums[strt] > nums[(strt+1)%n])return strt;
    else if(nums[end] > nums[(end+n-1)%n])return end;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] > nums[(mid+1)%n] && nums[mid] > nums[(mid+n-1)%n])return mid;
        else if(nums[mid] < nums[(mid+1)%n])strt = mid+1;
        else if(nums[mid] < nums[(mid-1+n)%n])end = mid-1;
    }
    return -1;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)cin >> nums[i];
    cout << peakElement(nums) << "\n";

}
