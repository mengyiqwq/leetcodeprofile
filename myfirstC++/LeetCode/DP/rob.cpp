#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 结果数组dp
int rob(vector<int>&nums)
{
  vector<int>dp(nums.size()+2,0);
// 状态转移方程  dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
  for(int i=2;i<nums.size()+2;i++)
  {
    dp[i]=max(dp[i-1],dp[i-2]+nums[i-2]);
  }
  return dp[nums.size()+1];
}
int main()
{
}