// FLOOR means just smaller (in case of array we have to return the element which is just
// smaller than or equal to the target).
#include<bits/stdc++.h>
using namespace std;
int floorInSortedArray(vector<int> &nums, int target)
{
    int strt = 0, end = nums.size()-1, res = -1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == target)return mid;
        else if(nums[mid] < target)
        {
            strt = mid+1;
            res = mid;
        }
        
        else if(nums[mid] > target)end = mid-1;

    }
    return res;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int k;
        cin >> k;
        nums.push_back(k);
    }
    int key;
    while(cin >> key)cout << floorInSortedArray(nums,key) << "\n";
    
    
} 


