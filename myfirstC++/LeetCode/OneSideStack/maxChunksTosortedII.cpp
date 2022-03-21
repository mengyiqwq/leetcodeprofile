#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int> &arr)
{
    stack<int>S;
    int premax=-1;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
       if(arr[i]>=premax)
       {
           S.push(premax);
           premax=arr[i];
           count++;
       }
       while (!S.empty()&&S.top()>arr[i])
       {
           S.pop();
           count--;
       }
    }
    return max(count,1);
}
int main()
{
}