#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, m, h;
int board[101][101][101]; // 높이 행 열
int dx[]{ 1,-1,0,0,0,0 };
int dy[]{ 0,0,1,-1,0,0 };
int dz[]{ 0,0,0,0,-1,1 };
int ret = -1;
queue <pair<int, pair<int, int>>> q;

void go()
{
	while (!q.empty())
	{
		int a, x, y;
		auto cur = q.front();
		a = cur.first;
		x = cur.second.first;
		y = cur.second.second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int na = a + dz[i];

			if (nx < 0 || ny < 0 || na < 0 || nx >= n || ny >= m || na >= h) continue;
			if (board[na][nx][ny] == -1) continue; // 토마토가 없을 때 
			if (board[na][nx][ny] == 0)
			{
				board[na][nx][ny] = board[a][x][y] + 1;
				q.push({ na,{nx,ny} });
			}
		}
	}
}

bool CanAllTomato()
{
	for (int t = 0; t < h; t++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[t][i][j] == 0)
				{
					return false;
				}
				ret = max(board[t][i][j], ret);
			}
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	bool can = false;
	for (int t = 0; t < h; t++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[t][i][j];
				if (board[t][i][j] == 0)
				{
					can = true;
				}
				else if (board[t][i][j] == 1)
				{
					q.push({ t,{i,j} });
				}
			}
		}
	}

	if (!can)
	{
		cout << 0;
		return 0;
	}

	go();

	if (CanAllTomato())
	{

		cout << ret-1;
	}
	else
	{
		cout << -1;
	}
	return 0;
}
