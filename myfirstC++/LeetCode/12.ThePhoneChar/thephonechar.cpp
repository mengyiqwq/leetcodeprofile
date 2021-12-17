#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

// 暴力法,不写了，只是一个思路，似乎代码质量特别差劲
vector<string> LetterCombinations(string digits)
{
    vector<string> Phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    int length = digits.length();
    string temp = "";
    if (length == 0)
        return {};
    for (char i : Phone[digits[0] - 2 - '0'])
    {
        temp += i;
        if (length < 2)
        {
            res.push_back(temp);
            temp.pop_back();
            continue;
        }
        else
            for (char z : Phone[digits[1] - 2 - '0'])
            {
                temp += z;
                if (length < 3)
                {
                    res.push_back(temp);
                    temp.pop_back();
                    continue;
                }
                else
                    for (char j : Phone[digits[2] - 2 - '0'])
                    {
                        temp += j;
                        res.push_back(temp);
                        temp.pop_back();
                    }
                temp.pop_back();
            }
        temp.pop_back();
    }
    return res;
}
// 回溯法解决，又称为试探法，当探索到某一步，发现选择不优或者无法到达目的时退回重选
void backtrack(vector<string>&Res,const unordered_map<char,string>&phoneMap,const string& digits,int index,string& subRes)
{
    if(index==digits.length())//有多少个数字对应串应该有多大，因此此时可以将得到的最终结果放进数组
    Res.push_back(subRes);
    else
    {
        char digit=digits[index];//当前索引的数字字符
        const string &letters=phoneMap.at(digit);//对应数字字符在map中的字符串
        for(const char &letter:letters)
        {
            subRes+=letter;//子串添加字符
            backtrack(Res,phoneMap,digits,index+1,subRes);//回溯调用，添加下一个字符
            subRes.pop_back();//将最后一个字符去掉，换字符的操作
        }
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string>Res;
    if(digits.empty()){
        return Res;
    }
    unordered_map<char,string>phoneMap{
         {'2',"abc"},
         {'3',"def"},
         {'4',"ghi"},
         {'5',"jkl"},
         {'6',"mno"},
         {'7',"pqrs"},
         {'8',"tuv"},
         {'9',"wxyz"}
    };
    string subRes;
    backtrack(Res,phoneMap,digits,0,subRes);
    return Res;
}
int main()
{
    vector<string> res;
    res = letterCombinations("23");
    cout << res[0] << endl
         << res[1] << endl
         << res[2] << endl
         << res[3];
}