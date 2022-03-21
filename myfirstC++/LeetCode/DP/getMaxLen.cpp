#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 维持两个dp,一个表示前面的正子数组最长，一个表示前面负子数组最短
// 分解成子问题，找到子数组，以及记录前一个子问题的结果
// 不要将问题复杂化，想办法简化问题
// 对于每个数，如果为正，对于正子数组来说是直接在前面的正数组上加1，而对于负子数组来说是
// 直接在前面的负数组上加1，如果为负，对于正子数组来说是直接在负子数组上加1，否则就是在正子数组上加1
// int getMaxLen(vector<int> &nums)
// {
//    vector<int> posiDP(nums);
//    vector<int> negaDP(nums);
//    if (nums[0] > 0)
//       posiDP[0] = 1;
//    else if (nums[0] < 0)
//       negaDP[0] = 1;
//    else
//       negaDP[0] = posiDP[0] = 0;
//     for (int i = 1; i < nums.size(); i++)
//    {
//       if (nums[i] > 0)
//       {
//          posiDP[i] = posiDP[i - 1] + 1;
//          if (negaDP[i - 1] != 0)
//             negaDP[i] = negaDP[i - 1] + 1;
//          else
//             negaDP[i] = 0;
//       }
//       else if (nums[i] < 0)
//       {
//          if (negaDP[i - 1] != 0)
//             posiDP[i] = negaDP[i - 1] + 1;
//          else
//             posiDP[i] = 0;
//          negaDP[i] = negaDP[i - 1] + 1;
//       }
//       else
//       {
//          negaDP[i]=posiDP[i]=0;
//       }
//    }
//     return *max_element(posiDP.begin(),posiDP.end());
// }
// 滑动窗口解决问题
int  getMaxLen(vector<int> &nums)
{
   int posiDP=0,negaDP=0,maxLength=0,temp=0;
   if(nums[0]>0)posiDP=1;else negaDP=1;
   for(int i=1;i<nums.size();i++)
   {
      if(nums[i]>0)
      {
         posiDP++;
         if(negaDP>0)
         negaDP++;
         else negaDP=0;
         maxLength=max(maxLength,posiDP);
      }
      else if(nums[i]<0)
      {
         int newPositive = negaDP > 0 ? negaDP + 1 : 0;
                int newNegative = posiDP + 1;
                tie(posiDP, negaDP) = {newPositive, newNegative};
      }
      else 
      {
         posiDP=0;
         negaDP=0;
      }
   }
   return maxLength;
}
int main()
{

}