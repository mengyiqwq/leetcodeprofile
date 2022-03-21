#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 动态规划摆烂写法,超时qwq
int maxScoreSightseeingPair(vector<int> &values)
{
    int dp = values[0], newdp = dp;
    for (int i = 1; i < values.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            newdp = max(newdp, values[i] + values[j] + j - i);
        }
        dp = max(dp, newdp);
    }
    return dp;
}
// 动态规划,状态转移方程，应该定义dp为前面子数组中value+i最大的值
int maxScoreSightseeingPair(vector<int> &values)
{
    int maxValue = values[0], maxScore = values[0];
    for (int i = 1; i < values.size(); i++)
    {
        maxScore = max((maxValue + values[i] - i), maxScore);
        maxValue = max(values[i]+i, maxValue);
    }
    return maxScore;
}
int main()
{
}