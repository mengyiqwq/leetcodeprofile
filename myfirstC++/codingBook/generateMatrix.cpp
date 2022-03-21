#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void nextPosi(pair<int, int> &cur, int state)
{
    if (state == 0)
        cur.second++;
    else if (state == 1)
        cur.first++;
    else if (state == 2)
        cur.second--;
    else
        cur.first--;
}
vector<vector<int>> generateMatrix(int n)
{
    // 模拟法,定义一个状态
    int state = 0;
    pair<int, int> cur = {0, 0};
    pair<int, int> prePoint;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 1; i <= n * n; i++)
    {
        mat[cur.first][cur.second] = i;
        prePoint = cur;
        // 试图找到下一个正确位置
        nextPosi(cur, state);
        if (cur.first >= n || cur.second >= n||cur.first<0||cur.second<0)
        {
            cur = prePoint;
            state = (state + 1) % 4;
            nextPosi(cur, state);
        }
        else if (mat[cur.first][cur.second])
        {
            cur = prePoint;
            state = (state + 1) % 4;
            nextPosi(cur, state);
        }
    }
    return mat;
}
int main()
{
    generateMatrix(3);
}