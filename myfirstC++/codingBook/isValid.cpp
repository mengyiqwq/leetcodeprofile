#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> S;
    for (char i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            S.push(i);
        }
        else
        {
            if (!S.empty())
            {
                auto cur = S.top();
                if (i == ')')
                {
                    if (cur != '(')
                        return false;
                }
                else if (i == '}')
                {
                    if (cur != '{')
                        return false;
                }
                else
                {
                    if (cur != '[')
                        return false;
                }
                S.pop();
            }
            else return false;
        }
    }
    if(!S.empty())
    return false;
    return true;
}
int main()
{
}