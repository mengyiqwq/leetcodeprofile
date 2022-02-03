#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 额，第一步排序就把序号丢了
// int search(vector<int> &nums, int target)
// {
//     if (target < nums[0])
//         return 0;
//     int l = 0, r = nums.size() - 1;
//     if (target > nums[r])
//         return r;
//     int mid;
//     while (l < r)
//     {
//         mid = (l + r) / 2;
//         if (target < nums[mid])
//             r = mid;
//         else
//             l = mid + 1;
//     }
//     return mid;
// }
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     sort(nums.begin(), nums.end());
//     int mid = search(nums, target);
//     int l=mid==0?0:mid-1,r=mid,temp=nums[l]+nums[r];
//     while (temp!=target)
//     {
//        if(temp<target&&r<nums.size()-1)
//        r++;
//       else if(temp>target&&l>0)
//        l--;
//        temp=nums[l]+nums[r];
//     }
//     return {l,r};
// }
// 数组加哈希表
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> HashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = HashMap.find(target-nums[i]);
        if (it != HashMap.end())//find()没找到时会返回HashMap.end()
            return {it->second, i};
        HashMap[nums[i]] = i;
    }
    return {};
}
int main()
{
    vector<int> nums = {3, 2, 4};
    vector<int> res = twoSum(nums, 6);
    cout<<res[0]<<res[1];
}