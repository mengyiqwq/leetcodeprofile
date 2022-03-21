#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> S1;
    stack<int> S2;
    int size = 0;
    MyQueue()
    {
    }

    void push(int x)
    {
        size++;
        while (!S2.empty())
        {
            auto i = S2.top();
            S1.push(i);
            S2.pop();
        }
        S1.push(x);
    }

    int pop()
    {
        size--;
        while (!S1.empty())
        {
            auto i = S1.top();
            S2.push(i);
            S1.pop();
        }
        int temp = S2.top();
        S2.pop();
        return temp;
    }

    int peek()
    {
        while (!S1.empty())
        {
            auto i = S1.top();
            S2.push(i);
            S1.pop();
        }
        int temp = S2.top();
        return temp;
    }

    bool empty()
    {
        return size == 0;
    }
};
int main()
{
}