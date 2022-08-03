// This problem is very similar to the ceil wala problem 
// In this we are having charachters we have to print the next character present in the array

#include<bits/stdc++.h>
using namespace std;
char nextAlphabet(vector<char> &arr, char key)
{
    int strt = 0, end = arr.size()-1, res = 0;
    while(end >= strt)
    {
        int mid = strt + (end-strt)/2;
        if(key >= arr[mid])strt = mid+1;
        else if(key < arr[mid])
        {
            res = mid;
            end = mid-1;
        }
    }
    return arr[res];
}
signed main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];
    char key;
    while(cin >> key)cout << nextAlphabet(v,key) << "\n";
    
}
