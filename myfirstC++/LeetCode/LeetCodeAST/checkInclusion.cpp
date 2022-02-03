#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 双指针加递归，在超时边缘疯狂试探
bool checkInclusion(string s1, string s2)
{
    int hashMap[26] = {0};

    for (char i : s1)
        hashMap[i - 'a']++;
    if (s1.size() == s2.size())
    {
        for (char i : s2)
        {
            if (hashMap[i - 'a'])
                hashMap[i - 'a']--;
            else
                return false;
        }
        return true;
    };
    int lPtr = 0, rPtr = 0;
    for (int i = 1; i < s2.size(); i++)
    {
        if (hashMap[s2[i] - 'a'])
        {
            rPtr = i;
            if (!hashMap[s2[i - 1] - 'a'])
                lPtr = i;
        }
        if (rPtr - lPtr + 1 >= s1.size())
        // 此处应该比较两者
        {
            if (checkInclusion(s2.substr(lPtr, s1.size()), s1))
                return true;
            else
                lPtr++;
        }
    }
    return false;
}
// 更好的办法：滑动窗口
bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    int windowssize = s1.size();
    vector<int> hashMap1(26,0);
     vector<int> hashMap2(26,0);
    for (int i = 0; i < s1.size(); i++)
    {
        hashMap1[s1[i]-'a']++;
        hashMap2[s2[i] - 'a']++;
    }
    for (int i = windowssize; i < s2.size(); i++)
    {
        if (hashMap1 == hashMap2)
            return true;
        hashMap2[s2[i- windowssize] - 'a']--;
        hashMap2[s2[i] - 'a']++;
    }
    if (hashMap1 == hashMap2)
        return true;
    return false;
}
int main()
{
}