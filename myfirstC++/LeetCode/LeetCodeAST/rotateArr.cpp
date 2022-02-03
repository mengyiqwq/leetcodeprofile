#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 暴力摆烂,超时了555
// void rotate(vector<int>&nums,int k)
// {
//   int temp,length=nums.size();
//   for(int i=0;i<k;i++)
//   {
//       temp=nums[length-1];
//       for(int j=length-1;j>=1;j--)
//       {
//           nums[j]=nums[j-1];
//       }
//       nums[0]=temp;
//   }
// }
// 优化，截取后面的k长度的段，然后给他放到前面即可,时间空间差不多是O(n)
// void rotate(vector<int> &nums, int k)
// {
//     int length = nums.size();
//     k = k % length;
//     vector<int> temp;
//     int last = length - 1;
//     // length-k下标开始转。
//     for (int i = length - k; i < length; i++)
//     {
//         temp.push_back(nums[i]);
//     }
//     for (int i = length - k - 1; i >= 0; i--)
//     {
//         if (last >= 0)
//             nums[last--] = nums[i];
//     }
//     for (int i = 0; i < length - k; i++)
//     {
//         nums[i] = temp[i];
//     }
// }
// 题解不错，使用temp来存每次被替换的位置，然后依次往下转，直到回到原位置，向下一个重复
// 结束条件就是k
void rotate(vector<int> &nums, int k)
{
    int temp, x=-1, pre, temp2,count=0;
    // 下一个位置是nums[(i+k)%length];
        for (int i = 0; i < k; i++)
        {
            if(count>=nums.size()) break;
            pre = i;
            temp = nums[pre];
            while (i != x)
            {
                x = (pre + k) % nums.size();
                temp2 = temp;
                temp = nums[x];
                nums[x] = temp2;
                count++;
                pre = x;
            }
            
    }
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
}