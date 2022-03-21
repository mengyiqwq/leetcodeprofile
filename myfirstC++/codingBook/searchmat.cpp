#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 从左下角开始比较
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int sizex = matrix[0].size(), sizey = matrix.size();
    int col = 0, row = sizey - 1;
    while (col >= 0 && col < sizex && row >= 0 && row < sizey)
    {
        if (target == matrix[row][col])
            return true;
        else if (target < matrix[row][col])
        {
            row--;
        }
        else
            col++;
    }
    return false;
}
int main()
{
}