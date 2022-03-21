#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 滑窗法
int minSubArrayLen(int target, vector<int> &nums)
{
    int temp=0;
    int minlen=INT16_MAX,lPtr=0;
    for(int i=0;i<nums.size();i++)
    {
        temp+=nums[i];
        while (temp>=target&&lPtr<nums.size())
        {
            temp-=nums[lPtr];
            minlen=min(minlen,i-lPtr+1);
            lPtr++;
        }
    }
    return minlen==INT16_MAX?0:minlen;
}
int main()
{
}