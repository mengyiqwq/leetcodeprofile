#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 动态规划，该好好学习dp了,关键在于建立一个记录局部目标结果的数组、变量
int minCostClimbingStairs(vector<int>&cost)
{
    int length=cost.size();
    vector<int>dp(length+1);
    dp[0]=dp[1]=0;
    for(int i=2;i<=length;i++)
    {
        dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    return dp[length];
}
int main()
{
}