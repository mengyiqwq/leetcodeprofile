#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
   int hash_Map1[26]={0};
   for(char i:s)
   hash_Map1[i-'a']++;
   for(char i:t)
   {
    hash_Map1[i-'a']--;
   }
   for(int i:hash_Map1)
   {
       if(i!=0)
       return false;
   }
   return true;
}
int main()
{
}