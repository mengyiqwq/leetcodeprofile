#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> getRow(int rowIndex)
{
    if(rowIndex==0) return {1};
    if(rowIndex==1) return {1,1};
    vector<vector<int>>DP(rowIndex+1,vector<int>(1,1));
   DP[1].push_back(1);
    for(int i=2;i<=rowIndex;i++)
    {
       for(int j=0;j<DP[i-1].size()-1;j++) 
       {
           DP[i].push_back(DP[i-1][j]+DP[i-1][j+1]);
       }
       DP[i].push_back(1);
    }
    return DP[rowIndex];
}
int main()
{
    getRow(3);
}
