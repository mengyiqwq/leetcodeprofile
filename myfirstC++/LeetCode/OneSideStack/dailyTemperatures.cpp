#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int>S;
    int size=temperatures.size();
    vector<int>res(size);
    for(int i=size-1;i>=0;i--)
    {
        while (!S.empty()&&temperatures[S.top()]<temperatures[i])
        {
            S.pop();
        } 
        res[i]=S.empty()?0:(S.top()-i);
        S.push(i);
    }
    return res;
}
int main()
{
}