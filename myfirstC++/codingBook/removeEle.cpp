#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 暴力
int removeElement(vector<int> &nums, int val)
{
    for (auto i = nums.begin(); i != nums.end();)
    {
        if (*i == val)
        {
            nums.erase(i);
            continue;
        }
        i++;
    }
    return nums.size();
}
// 快慢指针可以每次留下不是val值的元素
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 2, 3, 3, 3};
    removeElement(nums, 3);
}