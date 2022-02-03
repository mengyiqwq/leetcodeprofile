#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
    int temp = 0;
    vector<vector<int>> record;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                record.push_back({i, j});
            }
        }
    }
    for (auto x : record)
    {
        for (temp = 0; temp < matrix.size(); temp++)
            matrix[temp][x[1]] = 0;
        for (temp = 0; temp < matrix[0].size(); temp++)
            matrix[x[0]][temp] = 0;
    }
}
// 更加巧妙的方法，将第一行和第一列的来作为标记本行、列是否置0，然后使用两个变量来标记
// 原先的第一行和第一列是否为0
int main()
{
}