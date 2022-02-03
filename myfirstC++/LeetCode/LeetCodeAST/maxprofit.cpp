#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 暴力法，超时
int maxProfit(vector<int>&prices)
{
    int maxPro=0;
    for(int i=0;i<prices.size()-2;i++)
    {
        for(int j=i+1;j<prices.size()-1;j++)
        {
           if(prices[j]-prices[i]>maxPro)
           maxPro=prices[j]-prices[i];
        }
    }
    return maxPro;
}
// 动态规划，状态转移方程为f(x)=f(x-1)
int maxProfit(vector<int>&prices){
    int minValue=prices[0],maxPro=0;
    for(int i=0;i<prices.size();i++)
    {
        if(prices[i]-minValue)
        maxPro=maxPro>(prices[i]-minValue)?maxPro:(prices[i]-minValue);
        if(prices[i]<minValue)
        minValue=prices[i];
    }
    return maxPro;
}
int main()
{
}