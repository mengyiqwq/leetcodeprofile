#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>&nums)
{
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}
// 摩尔投票法，通过统计出现次数，如果不同时减1，然后减到0重开，直到最后对应的值即为目标值
int majorityElement(vector<int>&nums)
{
    int count=0,res=nums[0];
    for(int i:nums)
    {
        if(count==0) res=i;
        if(i==res) count++;
        else  count--; 
    }
    return res;
}
int main()
{
}