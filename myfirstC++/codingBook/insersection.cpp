#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    // 0表示没有，1表示有，2表示被放进过了
    unordered_map<int,int>hash_map;
    for(int i:nums1)
    {
        hash_map[i]=1;
    }
    vector<int>res;
    for(int i:nums2)
    if(hash_map[i]==1) {
        res.push_back(i);
        hash_map[i]=2;
    }
    return res;
}
int main()
{
}