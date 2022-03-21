#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 回溯法感觉需要建个哈希表，此处迭代处理,每次重复时取前一个重复
// 元素满足的所有子集来添加
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {{}, {nums[0]}};
    vector<int> temp;
    int preLen = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        { 
            preLen = res.size();
            for (int j = preLen - 1; j >= 0; j--)
            {
                temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        else
        {
            int templen=res.size();
            for (int j = templen - 1; j >= templen - preLen; j--)
            {
                temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
    }
    return res;
}
int main()
{
    vector<int>nums={1,1,2,2};
    subsetsWithDup(nums);
}