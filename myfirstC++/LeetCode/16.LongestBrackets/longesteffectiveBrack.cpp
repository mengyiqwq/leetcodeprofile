#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// 使用滑动窗口求解
int longestValidParentheses(string s)
{
    int length = s.size();
    if (length == 0)
        return 0;
    int LBrack = 0;
    int tempres = 0;
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(')
        {
            if (s[i - 1] == ')' && i > 0 && LBrack > 0)
            {
                if (tempres > res)
                    res = tempres;
            }
            LBrack++;
        }
        if (s[i] == ')')
        {
            LBrack--;
            if (LBrack < 0)
            {
                tempres = 0;
                LBrack = 0;
                continue;
            }
            if (LBrack >= 0)
                tempres++;
            if (LBrack == 0)
            {
                if (res < tempres)
                    res = tempres;
            }
        }
    }
    if (LBrack > 0)
        return 2 * (tempres - res) > res ? 2 * (tempres - res) : 2 * res;
    else
        return 2 * res;
}
// 动态规划，dalao写法
// 动态规划可以用于求解最值问题等，一般要有一个规划数组和状态转移方程，对于状态转移看每一步最优解
// 和上一步最优解之间的关系来列
// 本题动态转移方程：...()时：dp(i)=dp(i-2)+2;s[i]=='(',...))时，dp(i)=dp(i-1)+2+dp(i-dp(i-1)-2)
// 隔了n个，则在去掉隔着的数前为i-(n+1)
int longestvalidparentheses(string s)
{
    const int length = s.size();
    int res=0;
    int dp[length];
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(')
        {
                dp[i] = 0;
        }
        if (i >= 1)
        {
            if (s[i] == ')' && s[i - 1] == '(')
            {
                if (i >= 2)
                    dp[i] = dp[i - 2] + 2;
                else
                    dp[i] = 2;
            }
            if (s[i] == ')' && s[i - 1] == ')')
            {
                if (i - dp[i - 1] - 1 >= 0)
                {
                    if (s[i - dp[i - 1] - 1] == '(')
                    {
                        if(i - dp[i - 1] - 2>=0)
                        dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                        else dp[i]=dp[i-1]+2;
                    }
                    else
                        dp[i] = 0;
                }
                else
                    dp[i] =0;
            }
        }
        else
            dp[i] = 0;
        if(dp[i]>res)
        res=dp[i];
    }
    return res;
}
// 栈入栈出来处理括号

int main()
{
    string s = ")()())()()(";
    cout << longestvalidparentheses(s);
}