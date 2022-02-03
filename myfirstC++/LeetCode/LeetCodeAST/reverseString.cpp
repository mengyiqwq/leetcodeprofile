#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s)
{
    // 0和size-1换，和为size-1
    int length = s.size();
    for (int i = 0; i < length / 2; i++)
    {
        swap(s[i], s[length - i - 1]);
    }
}
int main()
{
}