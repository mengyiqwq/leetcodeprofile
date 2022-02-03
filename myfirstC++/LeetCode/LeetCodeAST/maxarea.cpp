#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// DFS解法,先不管重复搜索，直接遍历dfs
int dfs(int x, int y, vector<vector<int>> &grid) //递归写法dfs
{
    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
    {
        if (grid[x][y] == 1)
        {
            grid[x][y]=0;
            return 1 + dfs(x - 1, y, grid) + dfs(x+1,y,grid)+dfs(x,y-1,grid)+dfs(x,y+1,grid);
        }
    }
    return 0;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                maxArea = max(maxArea, dfs(i, j, grid)); //
            }
        }
    }
    return maxArea;
}
// 方法二，深度搜索加栈，关键在于将周围的为1土地压入栈中，然后之后每次取出栈顶即可
// 方法三，广度优先，维持一个队列即可
// 小技巧，可以利用两个数组arr1=[0,0,1,-1],arr2=[1,-1,0,0]来简化代码
int main()
{
}