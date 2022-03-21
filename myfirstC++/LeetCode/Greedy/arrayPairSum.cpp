#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 按照贪心思想，排序后即可求
int arrayPairSum(vector<int> &nums)
{
  sort(nums.begin(),nums.end());
  int count=0;
  for(int i=0;i<nums.size();i+=2)
  {
      count+=min(nums[i],nums[i+1]);
  }
  return count;
}
int main()
{
}