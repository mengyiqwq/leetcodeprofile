#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            r = mid;
        else
            l = mid+1;
    }
    if (nums[l] == target)
        return l;
    else
        return -1;
}
int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9};
    cout<<search(nums,9);
}