#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 再多加一个状态即可,0代表无股票且非冷冻，1代表有股票，2代表无股票且冷冻
int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    vector<vector<int>> DP(size, vector<int>(3, 0));
    DP[0][0] = 0;//不在冷冻期
    DP[0][1] = -prices[0];
    DP[0][2] = 0;//在冷冻期
    for (int i = 1; i < size; i++)
    {
     DP[i][1]=max(DP[i-1][0]-prices[i],DP[i-1][1]);
     DP[i][0]=max(DP[i-1][2],DP[i-1][0]);
     DP[i][2]=DP[i-1][1]+prices[i];
    }
    return max(DP[size - 1][0], DP[size - 1][2]);
}
int main()
{
}