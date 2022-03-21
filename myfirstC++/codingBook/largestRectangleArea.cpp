#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 暴力法，n的平方算法
// 接雨水的类型题，当遇到求第一个...的数时常使用单调栈
 int largestRectangleArea(vector<int>& heights) {
 int size=heights.size();
 stack<int>S;
 vector<int>left(size),right(size);
//  设置哨兵，使得左右边界有成立

 for(int i=0;i<size;i++)
 {
   while (!S.empty()&&heights[i]<=heights[S.top()])
   {
       S.pop();
   }
    left[i]=S.empty()?-1:S.top();
    S.push(i);
 }
 S=stack<int>();
 for(int i=size-1;i>=0;i--)
 {
     while (!S.empty()&&heights[i]<=heights[S.top()])
     {
         S.pop();
     }
     right[i]=S.empty()?size:S.top();
     S.push(i);
 }
 int max_area=-1;
 for(int i=0;i<size;i++)
 {
    max_area=max(max_area,(right[i]-left[i]-1)*heights[i]);  
 }
 return max_area;
 }
int main()
{
    vector<int> r = {6,7,5,2,4,5,9,3};
    cout<<largestRectangleArea(r);
}