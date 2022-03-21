#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 动态规划
int maxProfit(vector<int> &prices, int fee)
{
    int size=prices.size();
    vector<vector<int>>DP(size,vector<int>(2,0));
    DP[0][0]=0;DP[0][1]=-prices[0];
    for(int i=1;i<size;i++)
    {
        DP[i][0]=max(DP[i-1][1]+prices[i]-fee,DP[i-1][0]);
        DP[i][1]=max(DP[i-1][0]-prices[i],DP[i-1][1]);
    }
    return DP[size-1][0];
}
// 优化
int maxProfit(vector<int> &prices, int fee)
{
   int size=prices.size();
   int DP0=0,DP1=-prices[0],tempDP0=0,tempDP1=-prices[0];
   for(int i=1;i<size;i++)
   {
       tempDP0=DP0;
       tempDP1=DP1;
      DP0=max(tempDP0,tempDP1+prices[i]-fee);
      DP1=max(tempDP1,tempDP0-prices[i]);
   }
   return DP0;
}
// 贪心法，反悔操作，在出现一只股票卖的钱不够多时，可以继续向后面卖（免手续费），直到可以用低
// 价来买下一只股票
int maxProfit(vector<int>&prices,int fee)
{
    int buy=prices[0]+fee,maxprofit=0;
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]+fee<buy)
        {
            buy=prices[i]+fee;
        }
        if(prices[i]>buy)
        {
           maxprofit+=(prices[i]-buy);
           buy=prices[i];
        }
    }
    return maxprofit;
}

int main()
{
}