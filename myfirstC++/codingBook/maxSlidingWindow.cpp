#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
//   多记录一下该值的索引即可
priority_queue<pair<int,int>>Q;
vector<int>res;
for(int i=0;i<k;i++)
{
    Q.emplace(nums[i],i);
}
res.push_back(Q.top().first);
for(int i=1;i<=nums.size()-k;i++)
{
    // i+k-1
    Q.emplace(nums[i+k-1],i+k-1);
    while(Q.top().second<i)
    {
        Q.pop();
    }
    res.push_back(Q.top().first);
}
return res;
}
// 更好的办法，单调队列，利用每次窗口的滑动时，在窗口里的部分有左边值比当前小时可以舍弃
// 来进行队列维持
int main()
{
}