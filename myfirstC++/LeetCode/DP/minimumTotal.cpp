#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 状态转移方程第i层的最短路径与第i-1层最短路径的关系
// 直接求出来
// 自底向上最后直接返回第一个元素可以不用找最小值
int minimumTotal(vector<vector<int>> &triangle)
{
    int length;
    for (int i = 1; i < triangle.size(); i++)
    {
        length = triangle[i].size();
        for (int j = 0; j < length; j++)
        {

            if (j == 0)
            {
                triangle[i][j] += triangle[i - 1][0];
                continue;
            }
            if (j == length - 1)
            {
                triangle[i][j] += triangle[i - 1][j-1];
                continue;
            }
            triangle[i][j] += min(triangle[i - 1][j-1], triangle[i - 1][j]);
        }
    }
    length=INT32_MAX;
    for(int i:triangle[triangle.size()-1])
    {
       length=min(length,i);
    }
    return length;
}
int main()
{
}