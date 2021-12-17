#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 方法一：扫描法，从上往下不断进行扫描添加字符
string convert(string s, int numrows)
{
    if (numrows = 1)
        return s;
    vector<string> rows(numrows, ""); //存放扫描结果的容器
    int currow = 0;                   //记录当前行
    bool ondown = true;               //记录方向是否向下
    for (char c : s)
    {
        rows[currow] += c;
        currow = ondown ? currow + 1 : currow - 1; //维持当前行
        if (currow == 0 || currow == numrows - 1)
            ondown = !ondown; //改变扫描方向
    }
    string res = "";
    for (string substr : rows)
    {
        res += substr;
    }
    return res;
}
// 方法二，按行访问,找规律的方式求解
int main()
{
    string s = "PAYPALISHIRING";
    cout << convert(s, 4);
}