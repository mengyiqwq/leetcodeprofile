#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t)
{
  int hash[26]={0};
  for(char i:s)
  {
      hash[i-'a']++;
  }
  for(char i:t)
  {
      hash[i-'a']--;
  }
  for(int i:hash)
  if(i!=0)
  return false;
  return true;
}
int main()
{
}