#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
// 暴力法，直接记录下所有的0位置，然后遍历整个矩阵来计算最小值即可
// 广度优先，考虑一个0时情况，只需要从0开始广度优先地遍历即可得到所有的值，而可以
// 考虑超级零点，所以先进队列的零点是第二层的0，最后往下继续遍历即可得到结果，可以使用一个数组来
// 记录已经遍历过的节点。
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    queue<pair<int, int>> Q;
    vector<vector<int>> seen(mat.size(), vector<int>(mat[0].size(), 0));
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                Q.emplace(i, j);
                seen[i][j] = 1;
            }
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (cur.first + dx[i] >= 0 && cur.first + dx[i] < mat.size() && cur.second + dy[i] >= 0 && cur.second + dy[i] < mat.size())
            {
                if (!seen[cur.first + dx[i]][cur.second + dy[i]])
                {   
                    seen[cur.first+dx[i]][cur.second+dy[i]]=1;
                    Q.emplace(cur.first + dx[i], cur.second + dy[i]);
                    mat[cur.first + dx[i]][cur.second + dy[i]] = mat[cur.first][cur.second] + 1;
                }
            }
        }
    }
    return mat;
}
// 动态规划，用目标结果来构造递归的状态转移方程
// 对于矩阵中，从一个1到达0，只有左上，左下，右上，右下，四种组合的走法，
// 因此只需要把几种方式组合一下算一遍即可
// 优化：只需要保留左上和右下即可，其实只要包含四种移动即可

int main()
{
}