#include <iostream>
using namespace std;
int romanToInt(string s)
{
    int length = s.length();
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        if (i <length-1)
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                {
                    res += -1;
                    continue;
                }
            }
            if (s[i] == 'X')
            {
                if (s[i + 1] == 'L' || s[i + 1] == 'C')
                {
                    res += -10;
                    continue;
                }
            }
            if (s[i] == 'C')
            {
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                {
                    res += -100;
                    continue;
                }
            }
        }
        switch (s[i])
        {
        case 'I':
            res += 1;
            break;
        case 'V':
            res += 5;
            break;
        case 'X':
            res += 10;
            break;
        case 'L':
            res += 50;
            break;
        case 'C':
            res += 100;
            break;
        case 'D':
            res += 500;
            break;
        case 'M':
            res += 1000;
            break;
        default:
            break;
        }
    }
    return res;
}
int main()
{
    string a="MCMXCIV";
    cout<<romanToInt(a);
}