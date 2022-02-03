#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 递归又又超时
int climbStairs(int n)
{
    if (n <= 3)
        return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
int climbStairs(int n)
{
    if(n<=3) return n;
    int pre1=2,pre2=3,cur;
    for(int i=4;i<=n;i++)
    {
       cur=pre1+pre2;
       pre1=pre2;
       pre2=cur;
    }
    return cur;
}
int main()
{
}