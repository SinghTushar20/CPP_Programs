// The array was sorted and then it is rotated with some value k 
// Find the value of k by which the array is rotated

// LOGIC: for example the array is {3, 3, 5, 6, 78, 98, 103, 548};
//After rotation the array will become {98, 103, 548, 3, 3, 5, 6};

// The first occurrence of the minimum value will give the result k

#include<bits/stdc++.h>
using namespace std;
int numberRotated(vector<int> &nums)
{
    int N = nums.size();
    int strt = 0, end = nums.size()-1;
    int res = -1;
    if(nums[strt] <= nums[end])return N;
    while(end >= strt)
    {
        int mid = strt + (end - strt)/2;
        if(nums[strt] <= nums[end])return strt;//Base condition to find if the start index is start of soted array
        if(nums[mid] < nums[(mid+1)%N] && nums[mid] < nums[(mid+N-1)%N])return mid; // If the element is pivot element
        if(nums[strt] <= nums[mid])strt = mid+1; // If left part of mid is sorted then search in right part
        else if(nums[end] >= nums[mid])end = mid-1;//If right part is sorted then search in left portion
    }
    return res;
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
    cout << numberRotated(nums);
}