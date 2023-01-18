#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

vector<pair<int, int>> del{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };
int n, m;
vector < vector<int> >board(9, vector<int>(9));
int ans	;
vector<vector<int>> virusBoard;
void dfs(int cnt)
{
	if (cnt == 3)
	{

		virusBoard = board;
		int cntSafe = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (virusBoard[i][j] == 2)
				{
					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty())
					{
						auto cur = q.front();
						q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.X + del[dir].X;
							int ny = cur.Y + del[dir].Y;
							if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
							if (virusBoard[nx][ny] == 0)
							{
								virusBoard[nx][ny] = 2;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (virusBoard[i][j] == 0)
				{
					cntSafe++;
				}
			}
		}

		ans = max(ans, cntSafe);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 1;
				dfs(cnt + 1);
				board[i][j] = 0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}


	dfs(0);

	cout << ans;
	// 8 * 8 62 

	return 0;
}