#include <string>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int boom[31][31];
bool gameOver = false;
int answer;

void Check(int x, int y, const vector<string>& board)
{
    if (board[y][x] == board[y][x + 1] &&
        board[y][x] == board[y + 1][x] &&
        board[y][x] == board[y + 1][x + 1])
    {
        boom[y][x] = 1;
        boom[y][x + 1] = 1;
        boom[y + 1][x] = 1;
        boom[y + 1][x + 1] = 1;
    }
}

void BoomBoard(vector<string>& board)
{
    bool boomCh = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (boom[i][j])
            {
                board[i][j] = ' ';
                boomCh = true;
                answer++;
            }
        }
    }

    if (boomCh == false) gameOver = true;
}

void RebuildBoard(vector<string>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == ' ')
            {
                for (int k = i; k > 0; k--) 
                {
                    if (board[k - 1][j] == ' ')
                        break;
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = ' ';
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {


    while (!gameOver)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                boom[i][j] = 0;
            }
        }
        for (int y = 0; y < m - 1; y++)
        {
            for (int x = 0; x < n - 1; x++)
            {
                if (board[y][x] != ' ')
                {
                    Check(x, y, board);
                }
            }
        }
        BoomBoard(board);
        RebuildBoard(board);
    }

    return answer;
}