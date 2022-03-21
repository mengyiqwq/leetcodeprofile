#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 价值{2,3,4,6,7}  体积{3,4,2,1,5} 背包为6
// 1.暴力法，找到背包可以放的所有体积的组合及价值，求最大，时间复杂度为O(2^n)
int max_Value = 0;
int temp_Value=0;
int curSize = 0;
void dfs(int cur, vector<int> &Value, vector<int> &Size, int contain)
{
    for (int i = cur; i < Value.size(); i++)
    {
        if (curSize + Size[i] > contain)
            return;
        curSize += Size[i];
        temp_Value += Value[i];
        max_Value=max(temp_Value,max_Value);
        dfs(i + 1, Value, Size, contain);
        curSize -= Size[i];
        temp_Value-=Value[i];
        dfs(i+1,Value,Size,contain);
    }
}
int bag(vector<int> &Value, vector<int> &Size, int contain)
{
    dfs(0,Value,Size,contain);
    return max_Value;
}

int main()
{
}