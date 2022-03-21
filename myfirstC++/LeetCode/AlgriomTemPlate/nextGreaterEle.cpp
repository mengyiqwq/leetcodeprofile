#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 单调栈模板：一般要倒过来遍历数组，且是解决下一个更大值类型题
void getNextGreater(vector<int> &nums)
{
    stack<int> S;
    int size = nums.size();
    vector<int> res(size);
    for (int i = size - 1; i >= 0; i--)
    {
        while (!S.empty() && nums[i] > S.top())
        {
            S.pop();
        }
        res[i] = S.empty() ? -1 : S.top();
        S.push(nums[i]);
    }
}
vector<int>weather(vector<int>&nums){
    stack<int>S;//记录索引的单调栈
    int size=nums.size();
    vector<int>res(size);
    for(int i=size-1;i>=0;i--)
    {
        while (!S.empty()&&nums[S.top()]<nums[i])
        {
            S.pop();
        }
        nums[i]=S.empty()?0:(S.top()-i);
        S.push(i);
    }
    return res;
}
// 对于环形，可以通过循环数组求模的方式来解决
vector<int>getnextGreater(vector<int>&nums){
    int size=nums.size();
    vector<int>res(size);
    stack<int>S;
    for(int i=2*size-1;i>=0;i--)
    {
        while (!S.empty()&&nums[i]<S.top())
        {
            S.pop();
        }
        res[i%size]=S.empty()?-1:S.top();
        S.push(nums[i%size]);
    }
}
int main()
{
    vector<int> nums = {};
}