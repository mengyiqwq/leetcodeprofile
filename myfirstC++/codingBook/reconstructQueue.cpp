#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 按照身高从大到小排序，然后将后面的相同编号往前面插入即可，因为后面插入对于前面来说没
// 有影响
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    int size = people.size();
    sort(people.begin(), people.end(), [&](vector<int> &a, vector<int> &b)
         {
      if(a[0]==b[0]) return a[1]<b[1];
      return a[0]>b[0]; });
    vector<vector<int>> res;
    for (int i = 0; i < size; i++)
    {
       int pos=people[i][1];
       res.insert(res.begin()+pos,people[i]);
    }
    return res;
}
int main()
{
}