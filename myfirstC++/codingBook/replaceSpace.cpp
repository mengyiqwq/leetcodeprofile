#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string replaceSpace(string s)
{
  string res="";
  for(char i:s)
  {
      if(i==' ')
      res+="%20";
      else 
      res+=i;  
  }
  return res;
}
int main()
{
}