#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 模拟法，蠕虫问题
int ClimbingWorm(int n, int u, int d)
{
    int nowClimbed = 0, time = 0;
    while (nowClimbed < n)
    {
        if (!(time % 2))
            nowClimbed += u;
        else
            nowClimbed -= d;
            time++;
    }
    return time;
}
int main()
{
}