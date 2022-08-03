#include<bits/stdc++.h>
using namespace std;
int binarySearchInReverseSortedArray(vector<int> &nums, int target)
{
    int strt = 0, end = nums.size()-1;
    while(end >= strt)
        {
            int mid = strt + (end-strt)/2;
            if(nums[mid] == target)return mid;
            else if(target > nums[mid])end = mid-1;
            else strt = mid+1;
        }
    return -1;
}
signed main()
{
// driver code here
}
