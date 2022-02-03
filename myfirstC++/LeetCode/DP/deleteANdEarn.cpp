#include <iostream>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
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
// 打家劫舍变式，将值的邻近问题转化为打家劫舍问题即可
int deleteAndEarn(vector<int>&nums)
{
   int maxValue=0;
   for(int i:nums)
   maxValue=max(maxValue,i);
   vector<int>dp(maxValue+1,0);
   for(int i:nums)
   dp[i]+=i;
   return rob(dp);
}
// 排序+动态规划
// 就是将数组割成一个个相差只有1的子数组，然后按照打家劫舍做。
int main()
{
}