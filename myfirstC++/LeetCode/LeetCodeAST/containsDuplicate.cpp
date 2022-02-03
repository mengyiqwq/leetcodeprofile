#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 使用map直接找,好像很慢
// bool containsDuplicate(vector<int> &nums)
// {
//     map<int, int> Map;
//     for (int i : nums)
//     {
//         Map[i]++;
//         if (Map[i] > 1)
//             return true;
//     }
//     return false;
// }
// 更慢，直接超时
// bool containsDuplicate(vector<int> &nums)
// {
//     for(int i=0;i<nums.size()-1;i++)
//     {
//         for(int j=i+1;j<nums.size();j++)
//         {
//             if(nums[i]==nums[j])
//             return true;
//         }
//     }
//     return false;
// }
// 直接使用集合来求
bool containsDuplicate(vector<int> &nums)
{
    return set<int>(nums.begin(),nums.end()).size()!=nums.size();
}
// 使用哈希表
bool containsDuplicate(vector<int> &nums)
{
  unordered_set<int>hash;
  for(int i:nums)
  {
      if(hash.find(i)!=hash.end()) return true;
      hash.insert(i);
  }
  return false;
}

int main()
{
    vector<int>nums={1,2,3,4,1};
    cout<<containsDuplicate(nums);
}