#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 左半边的最大及右半边的最大，两个最大中的最小即为目标高度
int trap(vector<int> &height)
{
    int size = height.size();
    int water = 0;
    vector<int> LeftH(size, 0);
    vector<int> RightH(size, 0);
    LeftH[0] = height[0];
    RightH[size - 1] = height[size - 1];
    for (int i = 1; i < size; i++) //先求左半边
    {
        LeftH[i] = max(LeftH[i - 1], height[i]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        RightH[i] = max(RightH[i + 1], height[i]);
    }
    for (int i = 0; i < size; i++)
    {
        water += (min(LeftH[i], RightH[i]) - height[i]);
    }
    return water;
}
// 优化上面的动态规划，使用双指针的解法，十分巧妙，利用左
// 使用栈的方式解决，求出每次的区域宽度及高度，相乘得到结果

int main()
{
}