#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    
    sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });
    int left = intervals[0][0];
    int right = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > right)
        {
            res.push_back({left, right});
            left = intervals[i][0];
            right=intervals[i][1];
        }
        else
        {
            right = max(right, intervals[i][1]);
        }
    }
    res.push_back({left, right});
    return res;
}