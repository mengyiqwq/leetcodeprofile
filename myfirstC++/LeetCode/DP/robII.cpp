#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
      if(nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0],nums[1]);
    vector<int> dp(nums.size() + 2, 0);
    int maxValue = 0;
    // 状态转移方程  dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    for (int i = 2; i < nums.size() + 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2]);
    maxValue = dp[nums.size()];
    for (int i = 0; i < dp.size(); i++)
        dp[i] = 0;
    for (int i = 3; i < nums.size() + 2; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2]);
    cout << dp[0] << dp[1] << dp[2] << dp[3];
    maxValue = max(dp[nums.size() + 1], maxValue);
    return maxValue;
}

int main()
{
    vector<int> nums = {2, 3, 2};
    rob(nums);
}