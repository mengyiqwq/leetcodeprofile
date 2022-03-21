#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &nums)
{
    // 只有取与不取两种状态,一个二维数组,这是一个01背包问题
    // 背包问题最大的问题在于二维数组表示什么，即dp[i][j]为从0到i个物体选择后是否等于j

    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1)
        return false;
    int target = sum / 2;
    int max_value = *max_element(nums.begin(), nums.end());
    if (max_value > target)
        return false;
    int size = nums.size();
    vector<vector<int>> DP(size, vector<int>(target + 1, 0));
    for (int i = 0; i < size; i++)
        DP[i][0] = true;   //从0到i全不取时即可达到j值为0
    DP[0][nums[0]] = true; //在dp数组中刚好取nums[0]时对应的j值为true
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (nums[i] <= j)
            {
               DP[i][j]= DP[i-1][j-nums[i]]|DP[i-1][j];//取或者没取这个数的或
            }
            else
            {
                DP[i][j]=DP[i-1][j];//没取这个数的结果
            }
        }
    }
    return DP[size-1][target];
}
int main()
{
}