#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int fx, fy;
char ch;

struct matrix
{
    int a[5][5];

    bool operator<(matrix x) const
    { //重载<,如果前面和后面不相等返回较比较大小
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (a[i][j] != x.a[i][j])
                    return a[i][j] < x.a[i][j];
        return false;
    }
} f, st;

int h(matrix a)
{
    int ret = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (a.a[i][j] != st.a[i][j])
                ret++;
    return ret;
}

struct node
{
    matrix a;
    int t;//移动的步数

    bool operator<(node x) const { return t + h(a) > x.t + h(x.a); }
} x;

priority_queue<node> q; // 搜索队列
set<matrix> s;          // 防止搜索队列重复

int main()
{
    st.a[1][1] = 1; // 定义标准表
    st.a[1][2] = 2;
    st.a[1][3] = 3;
    st.a[2][1] = 8;
    st.a[2][2] = 0;
    st.a[2][3] = 4;
    st.a[3][1] = 7;
    st.a[3][2] = 6;
    st.a[3][3] = 5;
    for (int i = 1; i <= 3; i++) // 输入
        for (int j = 1; j <= 3; j++)
        {
            scanf(" %c", &ch);
            f.a[i][j] = ch - '0'; // f是矩阵,使用对应数字矩阵
        }
    q.push({f, 0}); //放进第一个节点
    while (!q.empty())
    {
        x = q.top(); // x是队伍的第一个元素
        q.pop();
        if (!h(x.a))
        { // 判断是否与标准矩阵一致
            printf("%d\n", x.t);
            return 0;
        }
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (!x.a.a[i][j])
                    fx = i, fy = j; // 如果该点上的数为0
        for (int i = 0; i < 4; i++)
        {                                         // 对四种移动方式分别进行搜索
            int xx = fx + dx[i], yy = fy + dy[i]; //可以由0点到达的几个位置
            if (1 <= xx && xx <= 3 && 1 <= yy && yy <= 3)
            {
                swap(x.a.a[fx][fy], x.a.a[xx][yy]); //对于当前的路径进行一波移动
                if (!s.count(x.a))                  //如果没有这样走过就放进set防止由于重复路径导致无限循环
                    s.insert(x.a),
                        q.push({x.a, x.t + 1});     // 这样移动后，将新的情况放入搜索队列中
                swap(x.a.a[fx][fy], x.a.a[xx][yy]); // 如果不这样移动的情况
            }
        }
    }
    return 0;
}