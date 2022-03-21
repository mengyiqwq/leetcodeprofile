#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int size = nums.size();
    int lPtr, rPtr;
    long long temp = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < size - 3; i++)
    {
        if (i != 0)
        {
            if (nums[i] == nums[i - 1])
                continue;
        }
        for (int j = i+1; j < size - 2; j++)
        {
            if (nums[j] == nums[j - 1] && j != i+1)
                continue;
            lPtr = j + 1;
            rPtr = size - 1;
            while (lPtr < rPtr)
            {
                temp = nums[i] + nums[j] + nums[lPtr] + nums[rPtr];
                if (temp == target)
                {
                    res.push_back({nums[i], nums[j], nums[lPtr], nums[rPtr]});
                    lPtr++;
                    while (lPtr<size-1&&nums[lPtr]==nums[lPtr-1])
                    {
                       lPtr++;
                    }
                }
                else if (temp < target)
                    lPtr++;
                else
                    rPtr--;
            }
        }
    }
    return res;
}
int main()
{
}