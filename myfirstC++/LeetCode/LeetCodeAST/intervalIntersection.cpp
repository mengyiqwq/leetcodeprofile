#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 双指针,使用插入的观点来解决，然后决定是和前一个还是后一个值构成结果
// 写得快死了的烂代码
// vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
// {
//     if (!firstList.size() || !secondList.size())
//         return {};
//     vector<vector<int>> res = {};
//     int firstSize = firstList.size() * firstList[0].size();
//     int secondSize = secondList.size() * secondList[0].size();
//     for (int i = 0; i < firstSize; i++)
//     {
//         for (int j = 0; j < secondSize; j++)
//         {

//             if (secondList[j / 2][j % 2] >= firstList[i / 2][i % 2])
//             {
//                 //    前面是偶数，后面是奇数时有效插入，插入位置为j
//                 if (!((j - 1) % 2))
//                 {
//                     if (!(i % 2))
//                     {
//                         if (firstList[(i + 1) / 2][(i + 1) % 2] <= secondList[j / 2][j % 2])
//                         {
//                             res.push_back({firstList[i / 2][i % 2], firstList[(i + 1) / 2][(i + 1) % 2]});
//                             i++;
//                         }
//                         else
//                             res.push_back({firstList[i / 2][i % 2], secondList[j / 2][j % 2]});
//                     }
//                     else
//                     {
//                         res.push_back({secondList[(j - 1) / 2][(j - 1) % 2], firstList[i / 2][i % 2]});
//                     }
//                 }
//                 else if (secondList[j / 2][j % 2] == firstList[i / 2][i % 2])
//                 {
//                     if (i % 2)
//                         res.push_back({secondList[j / 2][j % 2], secondList[j / 2][j % 2]});
//                     else
//                     {
//                         if (firstList[i / 2][i % 2] <= secondList[j / 2][j % 2] && firstList[(i + 1) / 2][(i + 1) % 2] >= secondList[(j + 1) / 2][(j + 1) % 2])
//                         {
//                             cout<<j;
//                             res.push_back({secondList[j / 2][j % 2], secondList[(j + 1)/2][(j + 1) % 2]});
//                             i++;
//                         }
//                     }
//                 }
//                 else
//                 {
//                     if (!(i % 2))
//                         if (firstList[i / 2][i % 2] <= secondList[j / 2][j % 2] && firstList[(i + 1) / 2][(i + 1) % 2] >= secondList[(j + 1) / 2][(j + 1) % 2])
//                         {
//                             res.push_back({secondList[j / 2][j % 2], secondList[j + 1][(j + 1) % 2]});
//                             i++;
//                         }
//                 }
//                 break;
//             }
//         }
//     }
//     return res;
// }

// 题解方法：双指针，在两个区间的第一个中，看末端点最小的那个区间数组，来进行判断
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    int Fptr = 0, Sptr = 0;
    vector<vector<int>> res;
    int Fsize = firstList.size(), Ssize = secondList.size();
    if (!Fsize || !Ssize)
        return {};
    while (Fptr < Fsize && Sptr < Ssize)
    {
        if (firstList[Fptr][1] < secondList[Sptr][1])
        {
            if (firstList[Fptr][1] >= secondList[Sptr][0])
            {
                res.push_back({max(firstList[Fptr][0], secondList[Sptr][0]), firstList[Fptr][1]});
            }
            Fptr++;
        }
        else
        {
            if (firstList[Fptr][0] <= secondList[Sptr][1])
            {
                res.push_back({max(firstList[Fptr][0], secondList[Sptr][0]), secondList[Sptr][1]});
            }
            Sptr++;
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> firstw = {{5, 10}};
    vector<vector<int>> secondw = {{5, 6}};
    intervalIntersection(firstw, secondw);
}