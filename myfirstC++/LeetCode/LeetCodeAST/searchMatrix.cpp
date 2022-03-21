#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 矩阵的二分查找
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l = 0, r = matrix.size(), mid = 0;
    while (r-l!=1&&r!=l)
    {
        mid = (l + r) / 2;
        if (matrix[mid][0] == target)
            return true;
        if (matrix[mid][0] > target)
            r=mid;
        else
          l=mid;
    }
    // l就是所在的行
   return binary_search(matrix[l].begin(),matrix[l].end(),target);
}
int main()
{
    vector<vector<int>>matrix={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout<<searchMatrix(matrix,11);
}