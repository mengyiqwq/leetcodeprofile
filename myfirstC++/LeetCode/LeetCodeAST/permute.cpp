#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 回溯法开写
vector<int> temp;
vector<int> chosen;
vector<vector<int>> res;
void dfs(int cnt, vector<int> &nums) //最关键的dfs函数，
{
    if (cnt == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (chosen[i])
            continue;
        temp.push_back(nums[i]);
        chosen[i] = 1;
        dfs(cnt - 1, nums);
        temp.pop_back();
        chosen[i] = 0;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    for (int i : nums)
       chosen.push_back(0);
    dfs(nums.size(),nums);
    return res;
}
int main()
{
    vector<vector<int>>res;
    vector<int>nums={1,2,3};
   res=permute(nums);
}