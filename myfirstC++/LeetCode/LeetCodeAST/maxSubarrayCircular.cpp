#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySumCircular(vector<int> &nums)
{
    if(nums.size()==1) return nums[0];
    int dp=nums[0],sum=nums[0],maxValue=nums[0],minValue=nums[0];
    for(int i=1;i<nums.size();i++)
    {
      dp=max(nums[i],nums[i]+dp);
      sum+=nums[i];
      maxValue=max(maxValue,dp);
    }
    dp=nums[0];
    for(int i=1;i<nums.size()-1;i++)
    {
        dp=min(nums[i],nums[i]+dp);
        minValue=min(minValue,dp);
    }
    return max(maxValue,sum-minValue);
}
int main()
{
}