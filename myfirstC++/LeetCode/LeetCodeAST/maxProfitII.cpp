#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 股票问题I，记录每次子问题的最小值来进行转移
// 股票问题II
// 动态规划时可以采用二维矩阵来求，而对每一天，情况有当天有股票和当天没股票对应的两种情况,分别求
// 两种情况下的状态转移情况
// dp[i][0]=max(dp[i-1][0],dp[i-1][1]+profile) dp[i][1]=max(dp[i-1][0]-profile,dp[i-1][1])
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> DP(prices.size(), vector<int>(2, 0));
    DP[0][0] = 0, DP[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + prices[i]);
        DP[i][1] = max(DP[i - 1][0] - prices[i], DP[i - 1][1]);
    }
    return DP[prices.size() - 1][0];
}
// 优化写法
int maxProfit(vector<int> &prices)
{
    int DP0 = 0, DP1 = -prices[0], tempDP0 = DP0, tempDP1 = DP1;
    for (int i = 1; i < prices.size(); i++)
    {
        tempDP0 = DP0, tempDP1 = DP1;
        DP0 = max(tempDP0, DP1 + prices[i]);
        DP1 = max(tempDP1, tempDP0 - prices[i]);
    }
    return DP0;
}
// 贪心法，每次只要今天比昨天高就卖出
int main()
{
}