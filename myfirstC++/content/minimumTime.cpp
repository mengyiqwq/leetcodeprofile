#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 暴力,暴力超时
long long minimumTime(vector<int> &time, int totalTrips)
{
    int t = 0;
    int temp = 0;
    int size = time.size();
    while (temp < totalTrips)
    {
        temp = 0;
        t++;
        for (int i = 0; i < size; i++)
        {
            temp += t / time[i];
        }
    }
    return t;
}
// 优化，二分法
long long minimumTime(vector<int> &time, int totalTrips)
{
    long long l = 1, r = LONG_LONG_MAX;

    long long mid;
    int size = time.size();
    while (l < r)
    {
        mid = (l + r) / 2;
        long long temp = 0;
        for (int i = 0; i < size; i++)
        {
            temp += mid / time[i];
        }
        if (temp >= totalTrips)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
}