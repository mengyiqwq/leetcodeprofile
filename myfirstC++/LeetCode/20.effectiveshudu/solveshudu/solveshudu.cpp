#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
// 必须要带回溯，
// 回溯法该怎么写？
// 每次遍历一次表，找到下一个能填的可能取值最少的位置，然后再找一下这个这个位置可以填的值，
// 使用回溯法来尝试寻找。
// 使用9位的位串来表示每一个位置可能的行取值，列取值，以及块取值，综合得到可能取得的值（GetNext函数）
vector<bitset<9>> row, col;
vector<vector<bitset<9>>> cell;
bitset<9> GetpossibleBits(int x, int y)
{
    return ~(row[x] | col[y] | cell[x / 3][y / 3]); //得到的是可能取值的位串
}
//每次找到可能取值最少的开始填写
vector<int> GetNext(vector<vector<char>> &board)
{
    vector<int> res;
    int mincnt = 10;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != '.')
                continue;
            auto possiblebit = GetpossibleBits(i, j);
            if (possiblebit.count() >= mincnt)
                continue;
            res = {i, j};
            mincnt = possiblebit.count();
        }
    }
    return res;
}
// 更新位串可能值是否已经被填写,给x行只有9位数，给y行，已经块均是只有9位的数，n即为被使用的位数
void fillNUM(int x, int y, int n, bool flag)
{
    row[x][n] = (flag) ? 1 : 0;
    col[y][n] = (flag) ? 1 : 0;
    cell[x / 3][y / 3][n] = (flag) ? 1 : 0;
}
bool dfs(int cnt, vector<vector<char>> &board)
{
    if (cnt == 0)
        return true;
    auto Next = GetNext(board);
    auto possiblebit = GetpossibleBits(Next[0], Next[1]);
    for (int n = 0; n < possiblebit.size(); n++)
    {
        if (!possiblebit.test(n))
            continue;
        
        board[Next[0]][Next[1]] = n + '1';
        fillNUM(Next[0], Next[1], n, true);
        if (dfs(cnt - 1, board))
            return true; 
        fillNUM(Next[0], Next[1], n, false);
        board[Next[0]][Next[1]] = '.';
      
    }
    return false;
}
void MsolveSudoku(vector<vector<char>> &board)
{
    row = vector<bitset<9>>(9, bitset<9>());
    col = vector<bitset<9>>(9, bitset<9>());
    cell = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
    int cnt = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                cnt++;
                continue;
            }
            int n = board[i][j] - '1';
            row[i] |= (1 << n);
            col[j] |= (1 << n);
            cell[i / 3][j / 3] |= (1 << n);
        }
    }
    dfs(cnt, board);
}
int main()
{
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    MsolveSudoku(board);
    cout << 'a';
}
