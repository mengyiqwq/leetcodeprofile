#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//暴力归纳,下标和范围值的关系
int maxChunksToSorted(vector<int> &arr)
{
   int count=0,max_value=arr[0];
   for(int i=0;i<arr.size();i++)
   {
      max_value=max(arr[i],max_value);
      if(max_value==i) count++;
   }
   return count;
}
int main()
{
}