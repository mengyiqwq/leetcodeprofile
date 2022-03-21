#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 两遍遍历
int candy(vector<int> &ratings)
{
    // 从谷底开始即
    int size = ratings.size();
    if(size==1) return 1;
    vector<int> Candys(size, INT16_MIN);
    if (ratings[0] <= ratings[1])
        Candys[0] = 1;
    if (ratings[size - 1] <= ratings[size - 2])
        Candys[size - 1] = 1;
    for (int i = 1; i < size - 1; i++)
    {
        if (ratings[i - 1] >= ratings[i] && ratings[i] <= ratings[i + 1])
        {
            Candys[i] = 1;
        }
    }
    for (int i = 1; i < size; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            Candys[i] = max(Candys[i], Candys[i - 1] + 1);
        }
    }
    for (int i = size - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
           Candys[i] = max(Candys[i], Candys[i + 1] + 1);
        }
    }
    int sum = 0;
    for (int i : Candys)
    {
        if (i == INT16_MIN)
            sum += 1;
        else
            sum += i;
    }
    return sum;
}
// 直接记录一下长度，并且每次位于递减时，将递减序列中的值记为1，加上递减长度
int main()
{
}