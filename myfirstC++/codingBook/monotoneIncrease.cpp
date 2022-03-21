#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int monotoneIncreasingDigits(int n)
{
    string temp=to_string(n);
    for(int i=temp.size()-1;i>=1;i--)
    {
       if(temp[i]<temp[i-1])
       {
           for(int j=i;j<temp.size();j++)
           {
               temp[j]='9';
           }
           temp[i-1]--;
       }
    }
    return stoi(temp);
}
int main()
{
}