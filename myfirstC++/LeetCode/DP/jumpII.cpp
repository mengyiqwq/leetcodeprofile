#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//贪心地去求，先算每个能到的最远位置，再从后往前记下每次到的次数
int jump(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] >= i)
            nums[i] = max(nums[i - 1], nums[i] + i);
    }
    int temp = nums.size() - 1;
    nums[temp] = 0;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < temp)
            temp = i;
        nums[i] = nums[temp] + 1;
    }
    return nums[0];
}
// 更好的想法：从前往后，记录之前的数组中能到的最远下标，如果到了最
// 远下标，则将步数加1，然后继续往下走
int main()
{
}