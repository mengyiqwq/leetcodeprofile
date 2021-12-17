#include <iostream>
using namespace std;
#include <string>
#include <vector>
// 正常解法，难点在判断溢出应该利用符号改变,此处没有防止溢出，可以通过在最后要溢出那一位进行溢出判断，
// 将最大/最小值除以10来进行判断到达最大位前，以及将长度相等时数字进行判断，
int myAtoi(string s)
{
    int len = s.size();
    // int count=0;
    int res = 0;
    int flag = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122)
            break;
        if (s[i] == ' ')
            continue;
        if (s[i] >= 48 && s[i] <= 57)
        {
            
            if ((res * 10 + s[i] - 48) < 0 && !flag) //正数溢出
            {
                res = INT32_MAX;
                break;
            }
            if ((res * 10 + s[i] - 48) > 0 && flag)
            {
                res = INT32_MIN;
                break;
            }
            res = res * 10 + s[i] - 48;
            // count++;
        }
        if (s[i] == '-')
        {
            flag = true;
        }
    }
    return res * (flag ? -1 : 1);
}
int main()
{
    string a = "  -210000698695785";
    cout << myAtoi(a);
}