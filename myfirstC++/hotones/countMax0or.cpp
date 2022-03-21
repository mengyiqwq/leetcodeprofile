#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 暴力回溯法

int cnt=0;
int max_Value=0;
void dfs(vector<int>&nums,int cur,int or_val)
{
    if(cur==nums.size())
   {
       if(or_val>max_Value){
           cnt=1;
           max_Value=or_val;
       }
       else if(or_val==max_Value)
       {
           cnt++;
       }
      return;
   }
   dfs(nums,cur+1,nums[cur]|or_val);
   dfs(nums,cur+1,or_val);
   return;
}
int countMaxOrSubsets(vector<int>&nums)
{
    dfs(nums,0,0);
    return cnt;    
}
// 位运算法
int countMaxOrSubsets(vector<int> &nums)
{
    int size = nums.size();
    int state = 1 << size;
    int max_value = 0, cnt = 0;
    for (int i = 0; i < state; i++)
    {
        int temp = 0;
        for (int j = 0; j < size; j++)
        {
            if ((i >> j) & 1)
            {
                temp |= nums[j];
            }
        }
        if (temp == max_value)
        {
            cnt++;
        }
        else  if(max_value<temp)
        {
            max_value = temp;
            cnt = 1;
        }
    }
    return cnt;
}
int main()
{
}