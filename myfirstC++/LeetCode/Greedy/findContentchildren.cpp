#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int count=0;
    int ptr1=0;
    for(int i:s)
    {
      if(g[ptr1]<=i)
      {
        count++;
        if(ptr1<g.size()-1)
          ptr1++;
        else return count;
      }
    }
    return count;
}
int main()
{
}