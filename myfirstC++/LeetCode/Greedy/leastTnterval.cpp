#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 贪心，用一个map来记录任务冷却时间,每次找到时间为0以及剩余最多的任务，冷却时间更新为n
// ，找不到就插入待命，全体冷却时间减1.
int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> freq;
    // 记录一下每个任务的次数
    for (char ch : tasks)
        freq[ch]++;
    vector<int> nextValidTime, rest;
    int size = freq.size();
    // 记录每个任务剩下次数
    for (auto i : freq)
    {
        nextValidTime.push_back(1);
        rest.push_back(i.second);
    }
    // 初始化完成
    int time = 0;
    for (int i = 0; i < tasks.size(); i++)
    {
        time++;
        //    找到最小的下一次有效时间
        int minNext = INT16_MAX;
        for (int j = 0; j < size; j++)
        {
            if (rest[j])
            {
                minNext = min(minNext, nextValidTime[j]);
            }
        }
        //    跳过待命时间
        time = max(time, minNext);
        // 找到剩下次数最多的
        int best = -1;
        for (int j = 0; j < size; ++j)
        {
            if (rest[j] && nextValidTime[j] <= time)
            {
                if (best == -1 || rest[j] > rest[best])
                {
                    best = j;
                }
            }
        }
        nextValidTime[best]=time+n+1;
        rest[best]--;
    } 
    return time;
}

int main()
{
}