#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// 暴力法，直接来
bool isValidSudoku(vector<vector<char>> &board)
{
    map<char, int> Map;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            else if (Map[board[i][j]] <= 0)
            {
                 Map[board[i][j]]++;
            }
            else
               return false;
        }
        Map.clear();
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] == '.')
                continue;
            else if (Map[board[j][i]] <= 0)
            {
              Map[board[j][i]]++;  
            }
            else
                return false;
        }
        Map.clear();
    }

    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            for (int a = i; a < i + 3; a++)
            {
                for (int b = j; b < j + 3; b++)
                {
                    if (board[a][b] == '.')
                        continue;
                    else if (Map[board[a][b]] <= 0)
                    {
                        Map[board[a][b]]++;
                    }
                    else
                        return false;
                }
            }
            Map.clear();
        }
    }
    return true;
}
int main()
{
    vector<vector<char>>board = 
{{'.','.','.','.','5','.','.','1','.'}
,{'.','4','.','3','.','.','.','.','.'}
,{'.','.','.','.','.','3','.','.','1'}
,{'8','.','.','.','.','.','.','2','.'}
,{'.','.','2','.','7','.','.','.','.'}
,{'.','1','5','.','.','.','.','.','.'}
,{'.','.','.','.','.','2','.','.','.'}
,{'.','2','.','9','.','.','.','.','.'}
,{'.','.','4','.','.','.','.','.','.'}};
cout<<isValidSudoku(board);
}