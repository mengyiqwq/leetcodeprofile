#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 贪心法，根据回文串的特点来贪心地取值
int longestPalindrome(string s)
{
    int count = 0;
    int hash[26] = {0};
    int Hash[26] = {0};
    for (char i : s)
    {
        if (i >= 'a')
        {
            hash[i - 'a']++;
            if (hash[i - 'a'] % 2)
            {
                count += hash[i - 'a'] - 1;
                hash[i - 'a'] = 1;
            }
            else
            {
                count += hash[i - 'a'];
                hash[i - 'a'] = 0;
            }
        }
        else
        {
            Hash[i - 'A']++;
            if (Hash[i - 'A'] % 2)
            {
                count += Hash[i - 'A'] - 1;
                Hash[i - 'A'] = 1;
            }
            else
            {
                count += Hash[i - 'A'];
                Hash[i - 'A'] = 0;
            }
        }
    }
    for (int i : hash)
        if (i > 0)
            return count + 1;
    for (int i : Hash)
        if (i > 0)
            return count + 1;
    return count;
}
int main()
{
    string s = "adaffabqvqvbbefaaadfafqgqfaa";
    cout << longestPalindrome(s);
}