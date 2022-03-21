#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 单调栈
vector<int> finalPrices(vector<int> &prices)
{
   stack<int>S;
   int size=prices.size();
   vector<int>res(size);
   for(int i=size-1;i>=0;i--)
   {
       while (!S.empty()&&S.top()>prices[i])
       {
          S.pop();
       }
       res[i]=S.empty()?prices[i]:(prices[i]-S.top()); 
       S.push(prices[i]);
   }
   return res;
}
int main()
{
}