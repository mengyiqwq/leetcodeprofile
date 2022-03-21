#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mostFrequent(vector<int> &nums, int key)
{
    unordered_map<int,int>hash_map;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]==key)
        {
            hash_map[nums[i+1]]++;
        }
    }
    int max_val=-1;
    int max_index;
    int count=0;
    for(auto i:hash_map)
    {
       if(!count)max_index=i.first;
       if(i.second>max_val)
       {
          max_index=i.first;
          max_val=i.second;
       }
       count++;
    }
    return max_index;
}
int main()
{
    vector<int>nums={11,22,11,33,11,33,11};
    mostFrequent(nums,11);
}