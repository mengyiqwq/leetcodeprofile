#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
map<int,int>hashMap1;
map<int,int>hashMap2;
int temp;
for(int i:nums1)
{
    hashMap1[i]++;
}
nums1.clear();
for(int i:nums2)
{
    hashMap2[i]++;
}
for(auto iter:hashMap1)
{
    temp=hashMap2[iter.first];
    if(temp>0)
    {
       temp=min(iter.second,temp);
       for(int i=0;i<temp;i++)
       {
         nums1.push_back(iter.first);
       }
    }
}
return nums1;
    }
    // 使用unorder_map写法更好
      vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int>hashMap;
      if(nums1.size()>nums2.size())
     return intersect(nums2,nums1);
      for(int i:nums1)
      hashMap[i]++;
      vector<int>res;
      for(int i:nums2)
      {
          if(hashMap.count(i))
          {
            res.push_back(i);
            hashMap[i]--;//技巧：将两者间的最小者看成是减得的过程
            if(hashMap[i]==0)
            hashMap.erase(i);
          }
      }
      return res;
      }
int main()
{
}