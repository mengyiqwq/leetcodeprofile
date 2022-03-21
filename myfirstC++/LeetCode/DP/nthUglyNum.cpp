#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 最小堆,每次取出最小堆的top元素并将下一个对应的值插入到堆中(注意使用哈希表去重)
int nthUglyNumber(int n)
{
    priority_queue<long, vector<long>, greater<long>> heap;
    vector<int> Ugly = {2, 3, 5};
    long minE;
    unordered_map<long, bool> hashMap;
    heap.push(1L);
    hashMap[1L] = true;
    while (!heap.empty())
    {
        minE = heap.top();
        heap.pop();
        n--;
        if (n <= 0)
            break;
        for (int i : Ugly)
        {
            if (!hashMap[minE * i])
            {
                heap.push(minE * i);
                hashMap[minE * i] = true;
            }
        }
    }
    return (int)minE;
}
// 三指针解法+dp
int nthUglyNumber(int n)
{
    int Ptr1 = 1, Ptr2 = 1, Ptr3 = 1;
    vector<long> DP(n + 1,1L);
    for (int i = 2; i <= n; i++)
    {
        DP[i] = min(min(2 * DP[Ptr1], 3 * DP[Ptr2]), 5 * DP[Ptr3]);
        if (DP[i] == 2 * DP[Ptr1])
            Ptr1++;
        if (DP[i] == 3 * DP[Ptr2])
            Ptr2++;
        if (DP[i] == 5 * DP[Ptr3])
            Ptr3++;
    }
    return DP.back();
}
int main()
{
}