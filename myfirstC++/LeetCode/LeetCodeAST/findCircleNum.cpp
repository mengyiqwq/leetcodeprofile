#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 并查集
// int findCircleNum(vector<vector<int>> &isConnected)
// {
//     int size = isConnected.size();
//     int count = 0;
//     vector<int> city(size);
//     for (int i = 0; i < size; i++)
//         city[i] = i;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             if (isConnected[i][j])
//             {
//                 if (city[i] == i)
//                 {
//                     city[j] = city[i];
//                     continue;
//                 }
//                 while (city[city[j]] != city[j])
//                     city[j] = city[city[j]];
//                 while (city[city[i]] != city[i])
//                     city[i] = city[city[i]];
//                 if (city[i] != city[j])
//                     city[city[j]] = city[i];
//             }
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (city[i] == i)
//             count++;
//     }
//     return count;
// }
// 深度优先搜索，搜到尽头后返回结果，然后在没遍历过的继续搜
// 做法:维持一个栈及数组哈希，然后不断入栈，或者递归写法

void dfs(int curCity, vector<vector<int>> &isConnect, vector<bool> &city)
{
    if (city[curCity])
        return;
    else
        city[curCity] = true;
    for (int j = 0; j < isConnect.size(); j++)
    {
        if (isConnect[curCity][j] && !city[j])
            dfs(j, isConnect, city);
    }
    return;
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int count=0;
    vector<bool> city(isConnected.size(), false);
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (city[i])
            continue;
        dfs(i, isConnected, city);
        count++;
    }
    return count;
}
// 或者使用广度优先队列处理
int main()
{
    vector<vector<int>> isconnect = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    findCircleNum(isconnect);
}