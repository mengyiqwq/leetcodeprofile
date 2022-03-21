#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 动态规划 按照根来进行分解
int numTrees(int n)
{
    vector<int>DP(n+1);
    DP[0]=1;
    DP[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            DP[i]=DP[j-1]*DP[i-j];
        }
    }
    return DP[n];
}
int main()
{
}