#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void moveZeros(vector<int>&nums)
{
   int firstZero=0;
  for(int i=0;i<nums.size();i++)
  {
      if(nums[i]!=0)
      {
          nums[firstZero]=nums[i];
          firstZero++;
      }
  }
  for(int i=firstZero;i<nums.size();i++)
  {
      nums[i]=0;
  }
}
int main()
{
    vector<int>nums={0,1,0,3,12};
    moveZeros(nums);
}