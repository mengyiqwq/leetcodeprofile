#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>twoSum(vector<int>&numbers,int target)
{
    int lPtr=0,rPtr=numbers.size()-1;
    while (1)
    {
       if(numbers[lPtr]+numbers[rPtr]==target)
       {
         return {lPtr+1,rPtr+1};
       }
       else if(numbers[lPtr]+numbers[rPtr]<target)
       {
           lPtr++;
       }
       else 
       {
           rPtr--;
       }
    }
    return {lPtr+1,rPtr+1};
}
int main()
{
}