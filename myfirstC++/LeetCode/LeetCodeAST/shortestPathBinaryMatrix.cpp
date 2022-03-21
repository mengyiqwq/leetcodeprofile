#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 如果找某一结果时dfs更快，如果是找所有结果中最。。。的，则bfs更快
// 使用bfs，关键在于终点的确定，可以使用层序遍历的思路
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0] != 0)
        return -1;
    int maxX = grid.size(), maxY = maxX;
    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    grid[0][0] = 1;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (cur.first == maxX - 1 && cur.second == maxY - 1)
            return grid[cur.first][cur.second];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int x = dx[i] + cur.first, y = cur.second + dy[j];
                if (x >= 0 && x < maxX && y >= 0 && y < maxY)
                {
                    if (!grid[x][y])
                    {
                        grid[x][y] = grid[cur.first][cur.second]+1;
                        Q.emplace(x,y);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
}