#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 每次往后时，去重，及贪心地使用栈来将元素pop出来，同时注意元素数量
string removeDuplicateLetters(string s)
{
    int Ele_Num[26] = {0};
    bool isinStack[26] = {false};
    string S;
    for (char i : s)
        Ele_Num[i - 'a']++;
    for (char i : s)
    {
        if (!isinStack[i - 'a'])
        {
            while (!S.empty() && S.back() > i)
            {
                if (Ele_Num[S.back() - 'a'] > 0)
                {
                    isinStack[S.back() - 'a'] = false;
                    S.pop_back();
                }
                else
                    break;
            }
            isinStack[i - 'a'] = true;
            S.push_back(i);
            
        }
        Ele_Num[i-'a']--;
    }
    return S;
}
int main()
{
}