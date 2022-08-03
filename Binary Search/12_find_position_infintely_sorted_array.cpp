#include<bits/stdc++.h>
using namespace std;
int searchInInfinteSortedArray(vector<int> &nums, int target)
{
    int strt = 0, end = 1;
    while(target < nums[end])
    {
        strt = end;
        end *= 2;
    }
    cout << strt << " " << end << '\n';
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(nums[mid] == target)return mid;
        else if(target > nums[mid])strt = mid+1;
        else end = mid-1;
    }
    return -1;
}
signed main()
{
int n;
cin >> n;
vector<int> nums(n);
for(int i = 0; i < n; i++)cin >> nums[i];
int key;
while(cin >> key)cout <<searchInInfinteSortedArray(nums,key) <<"\n";

}