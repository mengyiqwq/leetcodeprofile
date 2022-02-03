#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 2的幂次当且仅当二进制中只有一个1，即return n>0&&(n&(n-1))==0或者n&(-n)==n
bool isPowerofTwo(int n)
{
    if (n == 1)
        return true;
    long i = 1;
    while (i < n)
    {
        i = i * 2;
    }
    if (i == n)
        return true;
    else
        return false;
}
int main()
{
}