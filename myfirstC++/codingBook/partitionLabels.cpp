#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 将该问题等效为求解区间交集的问题
vector<int> partitionLabels(string s)
{
    vector<vector<int>> posi(26, vector<int>(2,-1));
    vector<vector<int>> actualposi;
    vector<int> res;
    // 记录一下每个字母的位置
    for (int i = 0; i < s.size(); i++)
    {
        if (posi[s[i] - 'a'][0] == -1)
        {
            posi[s[i] - 'a'][0] = posi[s[i]-'a'][1] = i;
        }
        else
        {
            posi[s[i] - 'a'][1] = i;
        }
    }
    for (auto i : posi)
        if (i[0] != -1)
            actualposi.push_back(i);
    sort(actualposi.begin(), actualposi.end(), [&](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });
    int Begin = 0;
    for (int i = 1; i < actualposi.size(); i++)
    {
        if (actualposi[i][0] > actualposi[i - 1][1])
        {
            res.push_back(actualposi[i-1][1] - Begin + 1);
            Begin = actualposi[i][0];
        }
        else
        {
            actualposi[i][1] = max(actualposi[i - 1][1], actualposi[i][1]);
        }
    }
    res.push_back(s.size() - Begin);
    return res;
}
// 更好的写法
vector<int> partitionLabels(string s)
{
    int hash_map[26]={0};
    vector<int>res;
    for(int i=0;i<s.size();i++)
    {
        hash_map[s[i]-'a']=i;
    }
    int left=0;
    int right=0;
    for(int i=0;i<s.size();i++)
    {
        right=max(right,hash_map[s[i]-'a']);
        if(right==i)
        {
            res.push_back(right-left+1);
            left=i+1;
        }
    }
    return res;
}
int main()
{
    partitionLabels("ababcbacadefegdehijhklij");
}