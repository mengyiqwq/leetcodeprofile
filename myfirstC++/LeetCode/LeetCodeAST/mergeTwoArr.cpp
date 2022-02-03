#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 先用空间换换时间吧
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     vector<int> res;
//     int ptr1 = 0, ptr2 = 0;
//     while (ptr1 < m && ptr2 < n)
//     {
//         if (nums1[ptr1] < nums2[ptr2])
//         {
//             res.push_back(nums1[ptr1]);
//             ptr1++;
//         }
//         else
//         {
//             res.push_back(nums2[ptr2]);
//             ptr2++;
//         }
//     }
//     while (ptr1 < m)
//     {
//         res.push_back(nums1[ptr1]);
//         ptr1++;
//     }
//     while (ptr2 < n)
//     {
//         res.push_back(nums2[ptr2]);
//         ptr2++;
//     }
//     nums1 = res;
// }
// 可以从后面往前放
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int last = m + n - 1;
    while (n)//数组的越界问题解决
    {
        if (m==0||nums1[m - 1] > nums2[n - 1])//当m退到0时，此时是将nums2不断拷贝过来
        {
            nums1[last--] = nums2[--n];
        }
        else
            nums1[last--] = nums1[--m];
    }
 
}
int main()
{
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    merge(nums1, 0, nums2, 1);
}