#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b)  (((a)>(b))?(a):(b))
#define min(a,b)  (((a)<(b))?(a):(b))
// 暴力法
double findthemid(vector<int>& nums1, vector<int>& nums2)
{
  vector<int>::iterator iter1 = nums1.begin();
  vector<int>::iterator iter2 = nums2.begin();
  vector<int> res;
  while (iter1 != nums1.end() && iter2 != nums2.end())
  {
    if (*iter1 >= *iter2)
    {
      res.push_back(*iter2);
      iter2++;
    }
    if (*iter2 > *iter1)
    {
      res.push_back(*iter1);
      iter1++;
    }
  }
  while (iter1 != nums1.end())
  {
    res.push_back(*iter1);
    iter1++;
  }
  while (iter2 != nums2.end())
  {
    res.push_back(*iter2);
    iter2++;
  }

  if (!(res.size() % 2))//如果是偶数
  {
    return ((double)res[res.size() / 2 - 1] + (double)res[res.size() / 2]) / 2;
  }
  else
    return res[res.size() / 2];
}
//合并加排序
double sortfindthemid(vector<int>& nums1, vector<int>& nums2)
{ 
  for(int i=0;i<nums2.size();i++)
  {
    nums1.push_back(nums2[i]);
  }
  sort(nums1.begin(),nums1.end());
    if (!(nums1.size() % 2))//如果是偶数
  {
    return ((double)nums1[nums1.size() / 2 - 1] + (double)nums1[nums1.size() / 2]) / 2;
  }
  else
    return nums1[nums1.size() / 2];
}
// 二分切割法,目前有问题
double binaryfindmid(vector<int>nums1,vector<int>nums2)
{
    int length1=nums1.size();
    int length2=nums2.size();
    if(length1>length2)
    return binaryfindmid(nums2,nums1);//重新调用，使得nums1始终是短的那一个
    //其中Lcut1和Rcut2分别为二分查找对应的在较短的数组上的左右边界
    int LMax1,LMax2,RMin1,RMin2,cut1,cut2,Lcut1=0,Rcut1=length1*2;
    while (Lcut1<=Rcut1)
    {
      cut1=(Lcut1+Rcut1)/2;
      cut2=length2+length1-cut1;//保持两个对应的左边与右边始终相等，同时便于cut1和cut2的此消彼长
      LMax1=(cut1==0)?INT_MIN:nums1[(cut1-1)/2];
      RMin1=(cut1==length1*2)?INT_MAX:nums1[cut1/2];
      LMax2=(cut2==0)?INT_MIN:nums2[(cut2-1)/2];
      RMin2=(cut2==length2*2)?INT_MAX:nums2[cut2/2];
      if(LMax1>RMin2)
      {
        Rcut1=cut1-1;
      }
      else if(LMax2>RMin1)
      {
        Lcut1=cut1+1;
      }
      else
      break;
    }
    return (max(LMax2,LMax1)+min(RMin1,RMin2))/2.0;
}
int main()
{
  vector<int> a1 = {3,4,5};
  vector<int> a2 = {1,2};
  cout << findthemid(a1, a2);
  cout<<sortfindthemid(a1,a2)<<endl;
  cout<<binaryfindmid(a1,a2);
}