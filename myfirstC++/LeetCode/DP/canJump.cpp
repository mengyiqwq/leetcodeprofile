#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 动态规划，
bool canJump(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] >= i)
            nums[i] = max(nums[i-1],nums[i]+i);
        else
            nums[i] =-1;
    }
    if (nums.back()<0)
        return false;
    return true;
}
int main()
{
}