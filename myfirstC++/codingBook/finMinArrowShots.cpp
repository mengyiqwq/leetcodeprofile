#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 并不是一个简单的求交集问题
int findMinArrowShots(vector<vector<int>> &points)
{
    // 找一个最小左边界即可发现规律
    sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b){
     return  a[0]<b[0];
    });
    int sum=0;
    for(int i=1;i<points.size();i++)
    {
    if(points[i][0]>points[i-1][1])
    {
       sum++;
    }
    else//在出现重叠时要记录一下最小右边界 
    {
       points[i][1]=min(points[i-1][1],points[i][1]);
    } 
    }
    return sum+1;
}
int main()
{
}