#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 分治算法
vector<int> diffWaysToCompute(string expression)
{
    vector<int> res;
    vector<int> leftRes;
    vector<int> RightRes;
    int size = expression.size();
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-')
        {
            flag = true;
            leftRes = diffWaysToCompute(string(expression, 0, i));
            RightRes = diffWaysToCompute(string(expression, i+1, size - i-1));
            for(int m:leftRes)
            {
                for(int n:RightRes)
                {
                    if(expression[i]=='+')
                    res.push_back(m+n);
                    if(expression[i]=='-')
                    res.push_back(m-n);
                    if(expression[i]=='*')
                    res.push_back(m*n);
                }
            }
        }
       
    } 
    if(!flag) return {stoi(expression)};
    return res;
}
int main()
{
}
