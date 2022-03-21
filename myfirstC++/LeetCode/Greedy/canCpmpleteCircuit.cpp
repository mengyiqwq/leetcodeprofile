#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 想法1：使用dfs来搜索，当出现油量不够时回到起点重新开始,n平方算法还是算了
int res = -1;
bool isend = false;
void dfs(int begin, vector<int> &gas, vector<int> &cost, int leftgas, int orginbegin)
{
    int size = gas.size();
    if (begin >= size)
        return;
    if (!leftgas && !gas[begin])
        return;
    if (leftgas < 0 || (leftgas + gas[begin] - cost[begin]) < 0)
        return;
    if ((begin + 1) % size == orginbegin)
    {
        res = (begin + 1) % size;
        isend = true;
        return;
    }
    dfs((begin + 1) % size, gas, cost, leftgas + gas[begin] - cost[begin], orginbegin);
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    for (int i = 0; i < gas.size(); i++)
    {
        dfs(i, gas, cost, 0, i);
        if (isend)
            break;
    }
    return res;
}
// 贪心法,O(n)算法
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int run=0,totaluse=0,start=0;
    for(int i=0;i<gas.size();i++)
    {
       run+=(gas[i]-cost[i]);
       totaluse+=(gas[i]-cost[i]);
       if(run<0)
       {
          start=i+1;
          run=0;
       }
    }
    return totaluse>0?start:-1;
}

int main()
{
    vector<int> gas = {};
    vector<int> cost = {};
    cout << "g:" << endl;
    cout << canCompleteCircuit(gas, cost);
}