#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 哈希+dp,记录的是以i结尾是否可以查找到,直接写对应的转移方程，dp[i]=dp[j]&&hashmap[j..i]
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> hashmap;
    vector<bool> dp(s.size()+1);
    for (auto i : wordDict)
        hashmap[i] = true;
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && hashmap[s.substr(j, i-j)])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}
int main()
{
    vector<string> Dirt = {"aaaa", "aaa"};
    wordBreak("aaaaaaa", Dirt);
}