#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    //    贪心,尽可能保留最多的5r
    int Five = 0, Ten = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
            Five++;
        if (bills[i] == 10)
        {
            Five -= 1;
            if (Five < 0)
                return false;
            Ten++;
        }
        if (bills[i] == 20)
        {
            if (Ten > 0 && Five > 0)
            {
                Ten--;
                Five--;
            }
            else if (Five >= 3)
            {
                Five -= 3;
            }
            else
                return false;
        }
    }
    return true;
}
int main()
{
    vector<int> Nums = {5, 5, 5, 10, 20};
    lemonadeChange(Nums);
}