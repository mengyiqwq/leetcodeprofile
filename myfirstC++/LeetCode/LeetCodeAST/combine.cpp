#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 奇怪的暴力法
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            res.push_back({{i + 1}});
        return res;
    }
    vector<int> temp(k); // temp用来记录下标

    for (int i = 0; i < k; i++)
        temp[i] = i + 1;
    int cur = k - 1;
    while (temp[0] <= n - k + 1)
    {
        if (temp[cur] > n - k + cur + 1 && cur > 0)
        {
            int i = k - 1;
            for (; i >= 0; i--)
            {
                if (temp[i] < n - k + i + 1)
                {
                    temp[i]++;
                    for (int j = i + 1; j < k; j++)
                        temp[j] = min(temp[j - 1] + 1, n - k + j + 1);
                    break;
                }
            }
            if (i < 0)
                break;
        }

        res.push_back(temp);
        temp[cur]++;
    }

    return res;
}
// 回溯法加剪枝,回溯法关键在于构造一个dfs函数,根据每次需要处理的元素进行dfs的处理
// 还有一个已经选中的元素集,递归地解决问题
vector<int>temp;
vector<vector<int>>res;
void dfs(int cur,int n,int k)//
{
    if(temp.size()+(n-k+1)<k)//剪枝
      return;
    if(temp.size()==k)//选完了
    {
      res.push_back(temp);
      return;
    }
    temp.push_back(cur);
    dfs(cur+1,n,k);//选择当前这个元素的情况
    temp.pop_back();
    dfs(cur+1,n,k);//不选择的情况
}
vector<vector<int>> combine(int n, int k)
{
    dfs(1,n,k);
    return res;
}

int main()
{
    combine(7, 3);
}