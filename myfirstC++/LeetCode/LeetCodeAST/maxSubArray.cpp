#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 动态规划
// 状态转移方程：f(i)=max{f(i-1),nums[i]},若之前的元素大于0，则将其加到当前元素上
// int maxSubArray(vector<int> &nums)
// {
//     int maxValue = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i - 1] > 0)
//         {
//             nums[i] += nums[i - 1];
//         }
//         if (nums[i] > maxValue)
//             maxValue = nums[i];
//     }
//     return maxValue;
// }
// 贪心法，若之前的和小于0则将其丢弃，以当前值重新开始
// 贪心得把每一段可以尽可能变大的段求出来。
int maxSubArray(vector<int> &nums)
{
    int pre=nums[0];
    int maxValue=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(pre<0)
        pre=nums[i];
        else 
        pre+=nums[i];
        if(pre>maxValue)
        maxValue=pre;
    }
    return maxValue;
}
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
}