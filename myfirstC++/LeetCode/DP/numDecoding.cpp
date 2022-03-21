#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// dp[i]=dp[i-1]+dp[i-2](在nums[i-1]满足要求时)可以直接使用指针来记录前一个和前二个来降低空间复杂度
int numDecodings(string s)
{
    int size = s.size();
    if (size == 1)
        return 1;
    if(s[0]=='0') return 0;
    vector<int> DP(size + 1, 1);
    DP[1] = 1;
    int temp;
    for (int i = 1; i < s.size(); i++)
    {
        temp = (((s[i - 1] - '0') * 10 + s[i] - '0'));
        if (s[i] == '0')
        {
            if (temp > 0 && temp <= 26)
                DP[i + 1] = DP[i - 1];
            else
                return 0;
        }
        else
        {
            if (temp <= 26 && temp > 0 && s[i - 1] != '0')
            {
                DP[i + 1] = DP[i - 1] + DP[i];
            }
            else
                DP[i + 1] = DP[i];
        }
    }
    return DP.back();
}

int main()
{
}