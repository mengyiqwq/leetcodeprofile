#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long minimalKSum(vector<int> &nums, int k)
{
  sort(nums.begin(), nums.end());
        int n = unique(nums.begin(), nums.end()) - nums.begin(); // 所谓的去重只是把多余的数移到了最后面并没有删除
        long long d = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= k)
            {
                d += nums[i];
                ++k;
            }
        }
        return (1LL + k) * k / 2 - d;
}
// 作差
long long minimalKSum(vector<int> &nums, int k)
{
    // 将前面k个数进行扣掉
    long long res = (1 + k) * k / 2;
    sort(nums.begin(), nums.end());
    unordered_map<int, bool> hash_map;
    for (int i : nums)
        hash_map[i] = true;
    long long temp = k + 1;
    int tempk = k;
    for (int i = 0; i <= k; i++)
    {
        if (tempk > 0)
        {
            res -= nums[i];
            tempk--;
        }
    }
    while (tempk)
    {
        if (!hash_map[temp])
        {
            res += temp;
            tempk--;
        }
        temp++;
    }
    return res;
}
long long minimalKSum(vector<int> &nums, int k)
{
    vector<long long> tempa;
    for (int i : nums)
    {
        tempa.push_back(i);
    }
    sort(tempa.begin(), tempa.end());
   tempa.erase(unique(tempa.begin(),tempa.end()),tempa.end());
    long long res = 0;
    res += ((1 + (tempa[0] - 1)) * (tempa[0] - 1)) / 2;
    k -= tempa[0] - 1;
    for (int i = 1; i < tempa.size(); i++)
    {
        if (k <= 0)
            return res;
        else
        {
            k -= (tempa[i] - tempa[i - 1] - 1);
            if (k >= 0)
                res += ((tempa[i - 1] + 1 + (tempa[i] - 1)) * (tempa[i] - tempa[i - 1] - 1)) / 2;
            else
            {
                res += ((tempa[i - 1] + 1 + (tempa[i] - 1 + k)) * (tempa[i] - tempa[i - 1] - 1 + k)) / 2;
            }
        }
    }
    long long temp = nums.back();
    while (k > 0)
    {
        temp++;
        res += temp;
        k--;
    }
    return res;
}
int main()
{
    vector<int> res = {53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83,
                       76};
    minimalKSum(res, 76);
}