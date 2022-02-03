#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 迭代
int fib(int n)
{
    if(n<=1)return n;
    vector<int> F(n+1);
    F[0]=0;
    F[1]=1;
    for (int i = 2; i <= n; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    return F[n];
}
// 更好的写法，直接用两个变量进行滑动
int fib(int n)
{
   if(n<2)return n;
   int pre1=0,pre2=1,cur;
   for(int i=2;i<=n;i++)
   {
      cur=pre1+pre2;
      pre1=pre2;
      pre2=cur;
   }
   return cur;
}
// 法二，杀龙招，使用矩阵乘法可以直接由前两个求出最后要找的结果，不过需要求某个M矩阵的n次幂，
// 通过快速幂算法可以将该计算简化到log(n)时间复杂度
// 法三，通项公式直接求。。。
int main()
{
}