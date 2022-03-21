#include <iostream>
// #include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
// 二分查找，变式一下
int binarySearch(int l, int r, vector<int> nums, int target)
{
    int mid = l;
    while (l < r)
    {
        if (l <= nums.size() - 1)
            if (nums[l] == target)
                return l;
        if (r <= nums.size() - 1)
            if (nums[r] == target)
                return r;
        mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            r = mid;
        else
            l = mid + 1;
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    if (nums.size() <= 3)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                return i;
        return -1;
    }
    int l = 0, r = nums.size() - 1, mid = 0, res = -1;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (nums[l] < nums[mid])
        {
            res = binarySearch(l, mid + 1, nums, target);
            if (res != -1)
                return res;
            else
                l = mid + 1;
        }
        else
        {
            res = binarySearch(mid, r + 1, nums, target);
            if (res != -1)
                return res;
            else
                r = mid;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {9, 1, 2, 3, 4, 5, 6, 7, 8};
   cout<< search(nums, 9);
}