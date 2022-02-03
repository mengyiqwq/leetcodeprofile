#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isBadVersion(int version);
int firstBadVersion(int n)
{
    int l=1,r=n;
    long long int mid;
    while (l<r)
    {
        mid=(l+r)/2;
        if(isBadVersion(mid))
        r=mid;
        else 
        l=mid+1;
    }
    if(isBadVersion(r))
    return r;
    else 
    return l;
}
int main()
{
}