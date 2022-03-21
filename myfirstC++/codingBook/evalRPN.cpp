#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    // 栈，对于前面两个数进行求解
    stack<int> S;
    for (string i : tokens)
    {
        if (i == "+" || i == "-" || i == "*" || i == "/")
        {
            int num1, num2;
            num1 = S.top();
            S.pop();
            num2 = S.top();
            S.pop();
            if (i == "+")
                S.push(num1 + num2);
            if (i == "-")
                S.push(num2 - num1);
            if (i == "*")
                S.push(num1 * num2);
            if (i == "/")
                S.push(num2 / num1);
        }
        else
            S.push(stoi(i));
    }
    return S.top();
}
int main()
{
    vector<string>S={"4","13","5","/","+"};
    evalRPN(S);
}