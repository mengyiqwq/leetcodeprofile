#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 滑动窗口
int lengthOfLongestSubstring(string s)
{
   unordered_map<char, int> Map;
    int lPtr = 0, rPtr = 0, maxLength = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (Map.count(s[i]))
          lPtr = max(Map[s[i]]+1,lPtr);
        Map[s[i]] = i;
        rPtr=i;
        maxLength = maxLength > (rPtr - lPtr+1) ? maxLength : (rPtr - lPtr+1);
    }
    return maxLength;
}
int main()
{
string s=" ";
cout<<lengthOfLongestSubstring(s);
}