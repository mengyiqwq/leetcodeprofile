#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 充分地理解单调栈
int mctFromLeafValues(vector<int> &arr)
{
    int size = arr.size();
    if (size == 2)
        return arr[0] * arr[1];
    stack<int> S; //递减栈

    int sum = 0;
    S.push(arr[0]);
    for (int i = 1; i < size; i++)
    {
        while (!S.empty() && (arr[i] > S.top() || i == size - 1))
        {
            sum += (S.top() * arr[i]);
            S.pop();
        }
        if(arr[i]<arr[i-1]) S.push(arr[i]);
    }
    return sum;
}
int main()
{
}