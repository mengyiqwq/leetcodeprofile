#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 哈希表来进行判断,n的三次方，仍然超时
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int size = nums1.size();
    int count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            hash_map[nums1[i] + nums2[j]]++;
        }
    }
   for(int i=0;i<size;i++)
   {
       for(int j=0;j<size;j++)
       {
           if(hash_map[-(nums3[i]+nums4[j])])
           {
               count+=hash_map[-(nums3[i]+nums4[j])];
           }
       }
   }
    return count;
}

int main()
{
}