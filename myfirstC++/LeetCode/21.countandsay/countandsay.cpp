#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string countAndSay(int n)
{
    string temp[n] = {""};
    temp[0] = "1";
    int count = 0;
    char curchar;
    if (n == 1)
        return "1";
    for (int i = 1; i < n; i++)
    {
        curchar = temp[i - 1][0];
        for (char j : temp[i - 1])
        {
            if (curchar == j)
                count++;
            else
            {
                temp[i] += to_string(count);
                temp[i] += curchar;
                curchar = j;
                count = 1;
            }
        }
        if (count >= 1)
        {
            temp[i] += to_string(count);
            temp[i] += curchar;
        }
        count = 0;
    }
    return temp[n - 1];
}
int main()
{
    cout << countAndSay(6);
}