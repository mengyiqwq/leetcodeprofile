#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 滑动窗口+数组哈希
// 滑动窗口的关键在于看待哈希表，将哈希表进行不断的单个增加和减少
vector<int> findAnagrams(string s, string p)
{
vector<int> hashMap(26, 0);
vector<int>hashMap_cpy(26,0);
    if (s.size() < p.size())
        return {};
    for(char j:p)
    {
        hashMap[j-'a']++;
    }
    for(int i=0;i<p.size();i++)
    hashMap_cpy[s[i]-'a']++;
   vector<int>res;
   for(int i=0;i<=s.size()-p.size();i++)
   {
     if(hashMap_cpy==hashMap)
     res.push_back(i);
     hashMap_cpy[s[i]-'a']--;
     if(i+p.size()<s.size())
     hashMap_cpy[s[i+p.size()]-'a']++;
   }
    return res;
}
// 优化时可以使用differ来记录不同的字母个数，及使用count数组来记下两个之差
int main()
{
    string s = "abab";
    string p = "ab";
    findAnagrams(s, p);
}