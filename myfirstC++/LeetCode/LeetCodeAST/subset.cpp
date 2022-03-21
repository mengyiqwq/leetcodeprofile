#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 回溯法枚举这个过程
vector<vector<int>>res={{}};
vector<int>temp;
void dfs(int cur,vector<int>&nums)
{
    for(int i=cur;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
        res.push_back(temp);
        dfs(i+1,nums);
        temp.pop_back();
    }
    return;
}
vector<vector<int>> subsets(vector<int> &nums)
{
    dfs(0,nums);
    return res;
}
// 迭代法：每遇到一个数由前面的子集加上该数以及该数和前面所有元素构成的得
// 到目标子集
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>>res={{},{nums[0]}};
    vector<int>temp;
    for(int i=1;i<nums.size();i++)
    {
      for(int j=res.size()-1;j>=0;j--)
      {
         temp=res[j];
         temp.push_back(nums[i]);
         res.push_back(temp);
      }
    }
    return res;
}
int main()
{
}