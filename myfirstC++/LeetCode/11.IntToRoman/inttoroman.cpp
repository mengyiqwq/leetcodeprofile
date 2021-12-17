#include <iostream>
using namespace std;
string intToRoman(int num)//枚举法
{
    string res = "";
    if (num / 1000 > 0)
    {
        while (num >= 1000)
            {
                res += 'M';
                num -= 1000;
            }
    }
    if (num / 500 > 0)
    {
        if (num / 100 == 9)
        {
            res += "CM";
            num -= 900;
        }
        else
        {
            while (num >= 500)
            {
                res += 'D';
                num -= 500;
            }
        }
    }
    if (num / 100 > 0)
    {
        if (num / 100 == 4)
        {
            res += "CD";
            num -= 400;
        }
        else
        {
           while (num >= 100)
            {
                res += 'C';
                num -= 100;
            }
        }
    }
    if (num / 50 > 0)
    {
        if (num / 10 == 9)
        {
            res += "XC";
            num -= 90;
        }
        else
        {
            while (num >= 50)
            {
                res += 'L';
                num -= 50;
            }
        }
    }
    if (num / 10 > 0)
    {
        if (num / 10 == 4)
        {
            res += "XL";
            num -= 40;
        }
        else
        {
           while (num >= 10)
            {
                res += 'X';
                num -= 10;
            }
        }
    }
    if (num / 5 > 0)
    {
        if (num == 9)
        {
            res += "IX";
            num -= 9;
        }
        else
        {
            while (num >= 5)
            {
                res += 'V';
                num -= 5;
            }
        }
    }
    if (num > 0)
    {
        if (num == 4)
        {
            res += "IV";
            num -= 4;
        }
        else
        {
            while (num > 0)
            {
                res += 'I';
                num -= 1;
            }
        }
    }
    return res;
}
// 简洁写法思路:建一个对应的表
int main()
{
    int a = 2000;
    cout << intToRoman(a);

}