#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> temp;
int tempsum = 0;
// set<int>temp;
vector<vector<int>> res;
// void dfs(int cur, vector<int> &nums)
// {
//     if (temp.size() == 3)
//     {
//         if (tempsum == 0)
//             res.push_back(temp);
//         return;
//     }
//     if (cur > nums.size() - 1)
//         return;
//     for (int i = cur; i < nums.size(); i++)
//     {
//         temp.push_back(nums[i]);
//         tempsum += nums[i];
//         dfs(i + 1, nums);
//         temp.pop_back();
//         tempsum -= nums[i];
//     }
//     return;
// }
// // 回溯法,不好，对这个问题来说时间空间复杂度都太高了
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     if (nums.size() < 3)
//         return {};
//     dfs(0, nums);
//     return res;
// }
// 双指针加排序
vector<vector<int>> threeSum(vector<int> &nums)
{
    int length = nums.size();
    if (length < 3)
        return {};
    vector<vector<int>> res;
    int temp;
    sort(nums.begin(), nums.end());
    int lPtr, rPtr = length - 1;
    for (int first = 0; first < length - 2; first++)
    {
        if (first >= 1)
        {
            temp = nums[first - 1];
            while (first < length - 2)
            {
                if (nums[first] == temp)
                    first++;
                else
                    break;
            }
        }
        lPtr = first + 1;
        while (lPtr < rPtr)
        {
            temp = nums[lPtr] + nums[rPtr] + nums[first];
            if (temp == 0)
            {
                res.push_back({nums[first], nums[lPtr], nums[rPtr]});
                temp = nums[lPtr];
                while (rPtr > lPtr)
                {
                    if (nums[lPtr] == temp)
                    {
                        lPtr++;
                    }
                    else
                        break;
                }
            }
            else if (temp > 0)
            {
                temp = nums[rPtr];
                while (rPtr > lPtr)
                {
                    if (nums[rPtr] == temp)
                    {
                        rPtr--;
                    }
                    else
                        break;
                }
            }
            else
            {
                temp = nums[lPtr];
                while (rPtr > lPtr)
                {
                    if (nums[lPtr] == temp)
                    {
                        lPtr++;
                    }
                    else
                        break;
                }
            }
        }
        rPtr = length - 1;
    }
    return res;
}
int main()
{
    vector<int> nums = {0, 0, 0, 0};
    threeSum(nums);
    cout << "aa";
}