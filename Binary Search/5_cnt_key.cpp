#include<bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int>&nums,int key)
{
    int strt = 0, end = nums.size()-1;
    int res =-1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == key)
        {
            res = mid;
            end = mid-1;                    //We will keep searching in left half and
        }                                   // updating the result to get first occurence
        else if(nums[mid] > key)end = mid-1;
        else strt = mid+1;
    }
    return res;
}

int lastOccurrrence(vector<int> &nums, int key)
{
    int strt = 0, end = nums.size()-1;
    int res = -1;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == key)
        {
            res = mid;
            strt = mid+1;              //We will keep searching in right half and 
        }                              //updating the result
        else if(nums[mid] > key)end = mid-1;
        else strt = mid+1;
    }
    return res;
}
int cntKey(vector<int> &nums, int key)
{
    if(lastOccurrrence(nums,key) == -1 && firstOccurrence(nums,key) == -1)return 0;
    int ans = lastOccurrrence(nums,key)-firstOccurrence(nums,key)+1;
    return ans;
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
    cin >> key;
    cout << firstOccurrence(nums,key) << " " << lastOccurrrence(nums,key) << "\n";
    cout << cntKey(nums,key);

}
