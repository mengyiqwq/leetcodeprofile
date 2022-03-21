#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 烂代码
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [=](vector<int>& x, vector<int>& y)
         { return x[1] < y[1]; });
    int ptr = 0, count = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < intervals[ptr][1])
        {
            count++;
        }
        else
        {
            ptr = i;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> r = {{2, 4}, {5, 7}, {1, 9}, {1, 5}, {2, 8}, {2, 6}};
    eraseOverlapIntervals(r);
}