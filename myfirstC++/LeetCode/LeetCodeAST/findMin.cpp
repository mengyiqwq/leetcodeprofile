#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 二分查找模板
// 
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1, mid = 0;
    if (nums[l] < nums[r])
        return nums[0];
    while (l != r)
    {
        mid = (l + r) / 2;
        if (nums[mid] > nums[l] && nums[l] > nums[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if(l+1<nums.size())l=nums[l+1]<nums[l]?(l+1):l;
    return nums[l];
}
int main()
{
    vector<int> nums = {3, 1, 2};
    cout << findMin(nums);
}