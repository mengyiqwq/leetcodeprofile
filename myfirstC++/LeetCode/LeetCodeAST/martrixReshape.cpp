#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    if (mat.size() * mat[0].size() != r * c)
        return mat;
    vector<vector<int>>res(r,vector<int>(c));
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            res[(i*mat[0].size()+j)/c][(i*mat[0].size()+j)%c]=mat[i][j];
        }
    }
    return res;
}
int main()
{
}