#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 双指针算法
vector<int> sortedSquares(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    int last = r;
    vector<int> res(r + 1);
    for (int& i : nums)
        i = pow(i, 2);
    while (l <= r&&last>=0)
    {
        if (nums[l] > nums[r])
            res[last--] = nums[l++];
        else
            res[last--]=nums[r--];
    }
    return res;
}
int main()
{
    vector<int>nums={-7,-3,2,3,11};
    sortedSquares(nums);
}