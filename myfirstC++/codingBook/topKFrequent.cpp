#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{ 
   map<int,int>hash_map;
   priority_queue<pair<int,int>>Q;
   vector<int>res;
   for(int i:nums)
   hash_map[i]++;
   for(auto i:hash_map)
   {
       Q.emplace(i.second,i.first);
   }
   while (k>0&&!Q.empty())
   {
       res.push_back(Q.top().second);
       Q.pop();
       k--;
   }
   return res;
}
int main()
{
}