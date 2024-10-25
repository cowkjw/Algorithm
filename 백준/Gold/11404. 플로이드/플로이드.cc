#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n, m;
int board[101][101];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) board[i][j] = 0;
			else board[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int y, x, w;
		cin >> y >> x >> w;
		board[y][x] = min(board[y][x], w);
	}


	for (int k = 1; k <= n; k++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				board[j][i] = min(board[j][i], board[j][k] + board[k][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == INF) cout << 0 << " ";
			else cout << board[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}