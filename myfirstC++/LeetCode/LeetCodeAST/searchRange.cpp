#include <iostream>
// #include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return {-1, -1};
    int l = 0, r = nums.size(), mid=0;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (target == nums[mid])
            break;
        if (target > nums[mid])
            l = mid + 1;
        else
            r = mid;
    }
    if (nums[mid] != target)
        return {-1, -1};
    else
    {
        l = r = mid;
        while (l >= 0)
        {
            if (nums[l] == target)
                l--;
            else
            {
                l++;
                break;
            }
        }
        while (r <= nums.size() - 1)
        {
            if (nums[r] == target)
                r++;
            else
            {
                r--;
                break;
            }
        }
        l=l<0?0:l;
        r=r>(nums.size()-1)?(nums.size()-1):r;
    }
    return {l, r};
}
int main()
{
  vector<int>nums={3};
    searchRange(nums,3);
}