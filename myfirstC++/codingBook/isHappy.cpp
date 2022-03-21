#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 遇到循环时可以想想哈希和快慢指针（一个一次走一步，另一个一次走两步)
bool isHappy(int n)
{
    unordered_map<int, bool> hash_map;
    int temp = n;
    while (temp != 1)
    {
        if (!hash_map[temp])
            hash_map[temp] = true;
        else
        {
            return false;
        }
        int posi = temp;
        int sum = 0;
        while (posi > 0)
        {
            sum += pow(posi % 10,2);
            posi /= 10;
        }
        temp = sum;
    }
    return true;
}
int main()
{
}
