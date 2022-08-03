/* You are given a 2D matrix which is sorted Row wise as well as coloumn wise we have to
search the given key in the matrix */

/*APPROACH : We will start from top right corner and then mive either left(j--)
or down(i++) by checking the position
IN Worst case time complexity will be O(M+N) whereas in brute force approach O(N*M)*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> searchInMatrix(vector<vector<int>> &matrix, int target)
{
    int i = 0, j = matrix[0].size()-1;
    while(i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size())
    {
        if(matrix[i][j] == target)return {i,j};
        else if(target > matrix[i][j])i++;
        else if(target < matrix[i][j])j--;
    }
    return {-1,-1};
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for(int i = 0; i < n; i++)
    {
        vector<int> numrow;
        for(int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            numrow.push_back(k);
        }
        matrix.push_back(numrow);
    }
    int key;
    while(cin >> key)
    {
        pair<int,int> pr = searchInMatrix(matrix, key);
        cout << pr.first << " " << pr.second << "\n";
    }

}
