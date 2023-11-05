#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n;
int board[17][17];
int dp[17][17][3];
bool check(int dir,int y,int x) // 0 가로 , 1 세로, 2 대각선
{
    if (dir == 0 || dir == 1) return !board[y][x];

    return (board[y][x] == 0 && board[y-1][x ] == 0 && board[y][x-1] == 0);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    dp[1][2][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 가로
            if (check(0, i, j + 1)) dp[i][j+1][0]+=dp[i][j][0];
            if (check(2, i + 1, j + 1)) dp[i + 1][j + 1][2] += dp[i][j][0];

            // 세로
            if (check(1, i + 1, j)) dp[i + 1][j][1] += dp[i][j][1];
            if (check(2, i + 1, j + 1)) dp[i + 1][j + 1][2] += dp[i][j][1];

            // 대각선
            if (check(0, i, j + 1)) dp[i][j + 1][0] += dp[i][j][2];
            if (check(1, i + 1, j)) dp[i + 1][j][1] += dp[i][j][2];
            if (check(2, i + 1, j+1)) dp[i + 1][j+1][2] += dp[i][j][2];
        }
    }
    cout << dp[n][n][0]+dp[n][n][1]+ dp[n][n][2];
}


