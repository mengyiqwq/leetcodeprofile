#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 递归超时
int tribonacci(int n)
{
    if(n<2) return n;
    if(n==2)return 1;
    return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
}
// 还是滑窗快
int tribonacci(int n)
{
    if(n<2) return n;
    if(n==2)return 1;
    int pre1=0,pre2=1,pre3=1,cur=2;
    for(int i=3;i<=n;i++)
    {
       cur=pre1+pre2+pre3;
       pre1=pre2;
       pre2=pre3;
       pre3=cur;
    }
    return cur;
}
int main()
{
}