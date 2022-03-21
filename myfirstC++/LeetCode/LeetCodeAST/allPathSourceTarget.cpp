#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 所有可能结果使用bfs更好,但是出现了结果重复问题...
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<vector<int>>> res(n);
    queue<int> Q;
    Q.emplace(0);
    res[0] = {{0}};
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i : graph[cur]) //对于出去的点
        {
            Q.emplace(i);
            for (auto j : res[cur]) //对于进来的路径
            {
                j.push_back(i);
                res[i].push_back(j);
            }
        }
    }
    for(auto i=res[n-1].begin();i<=res[n-1].end();i++)
    {
        for(auto j=i+1;j<=res[n-1].end();j++)
        {
            if(*i==*j)
            res[n-1].erase(j);
        }
    }
    unique(res[n-1].begin(),res[n-1].end());
    return res[n - 1];
}

int main()
{
}