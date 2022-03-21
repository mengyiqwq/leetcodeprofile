#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// dp搞定

int maxProduct(vector<int> &nums)
{
    vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < nums.size(); ++i)
    {
        // 可以记录前面最大值及前面的最小值
        maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
        minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
}
int main()
{
}