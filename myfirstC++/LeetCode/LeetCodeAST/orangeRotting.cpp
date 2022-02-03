#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
// 先广度优先烂一遍，再遍历一次看看有没有剩下
int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> Q;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                Q.emplace(i, j);
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (cur.first + dx[i] >= 0 && cur.second + dy[i] < n && cur.first + dx[i] < m && cur.second + dy[i] >= 0)
            {
                if (grid[cur.first + dx[i]][cur.second + dy[i]] == 1)
                {
                    Q.emplace(cur.first + dx[i], cur.second + dy[i]);
                    grid[cur.first + dx[i]][cur.second + dy[i]] = grid[cur.first][cur.second] + 1;
                }
            }
        }
    }
    int maxValue = -1;
    for (auto i : grid)
    {
        for (int j : i)
        {
            if (j == 1)
                return -1;
            maxValue = j > maxValue ? j : maxValue;
        }
    }
    return maxValue-2>=0?maxValue-2:0;
}
int main()
{
}