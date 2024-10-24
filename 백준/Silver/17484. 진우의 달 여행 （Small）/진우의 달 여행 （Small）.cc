#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n, m;
int board[7][7];
int dp[7][7][3]; // 왼쪽 대각선 , 밑 , 오른쪽 대각선
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> board[y][x];
		}
	}


	// dp 초기화
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			dp[y][x][0] = dp[y][x][1] = dp[y][x][2] = INF; // 무한대로 초기화
		}
	}

	for (int x = 1; x <= m; x++)
	{
		dp[1][x][0] = dp[1][x][1] = dp[1][x][2] = board[1][x]; // 첫 번째 행의 값으로 초기화
	}

	for (int y = 2; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (x > 1) 
			{
				dp[y][x][0] = min(dp[y - 1][x - 1][1], dp[y - 1][x - 1][2]) + board[y][x];
			}

			// 중간
			dp[y][x][1] = min(dp[y - 1][x][0], dp[y - 1][x][2]) + board[y][x];

			// 오른쪽 대각선 (x+1이 m 이하인 경우만 처리)
			if (x < m) 
			{
				dp[y][x][2] = min(dp[y - 1][x + 1][0], dp[y - 1][x + 1][1]) + board[y][x];
			}
		}
	}

	int result = INF;
	for (int x = 1; x <= m; x++)
	{
		result = min({ result, dp[n][x][0], dp[n][x][1], dp[n][x][2] });
	}

	cout << result;

	return 0;
}