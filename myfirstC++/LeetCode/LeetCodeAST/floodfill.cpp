#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 111
// 110
// 101
// 广度优先算法
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int temp = image[sr][sc];
    if(temp==newColor) return image;
    queue<pair<int, int>> Q;
    Q.push({sr, sc});
    while (!Q.empty())
    {
        auto i = Q.front();
        Q.pop();
        image[i.first][i.second] = newColor;
        if (i.first - 1 >= 0)
            if (image[i.first - 1][i.second] == temp)
            {
                image[i.first - 1][i.second] = newColor;
                Q.push({i.first - 1, i.second});
            }
        if (i.first + 1 < image.size())
            if (image[i.first + 1][i.second] == temp)
            {
                image[i.first + 1][i.second] = newColor;
                Q.push({i.first + 1, i.second});
            }
        if (i.second - 1 >= 0)
            if (image[i.first][i.second - 1] == temp)
            {
                image[i.first][i.second - 1] = newColor;
                Q.push({i.first, i.second - 1});
            }
        if (i.second + 1 < image[0].size())
            if (image[i.first][i.second + 1] == temp)
            {
                image[i.first][i.second + 1] = newColor;
                Q.push({i.first, i.second + 1});
            }
    }
    return image;
}
// 另一种深度优先算法
int main()
{
    vector<vector<int>> image = {{0,0,0}, {0,1,1}};
    floodFill(image, 1, 1, 1);
}