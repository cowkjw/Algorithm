#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int t, n, m;
int board[1001][1001];
int dist[1001][1001];
int fire[1001][1001];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
queue<pair<int, int>> f;
queue<pair<int, int>> q;
void Fire()
{
	while (!f.empty())
	{
		int x, y;
		tie(x, y) = f.front();
		f.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == -1) continue; //벽
			if (fire[nx][ny]) continue; // 이미 번진 곳
			fire[nx][ny] = fire[x][y] + 1;
			f.push({ nx,ny });
		}
	}
	return;

}

void go()
{
	bool escape = false;
	while (!q.empty() && (!escape))
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				cout << dist[x][y] << '\n';
				escape = true;
				break;
			}
			if (board[nx][ny] == -1) continue; // 벽
			if (dist[nx][ny]) continue; // 이미 처리한 곳
			if (fire[nx][ny] != 0 && fire[nx][ny]<=dist[x][y]+1) continue; // 불이 있고 넘는 경우
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	if (!escape) cout << "IMPOSSIBLE" << '\n';
	return;
}

void Init()
{
	memset(board, ' ', sizeof(board));
	memset(dist, 0, sizeof(dist));
	memset(fire, 0, sizeof(fire));
	f = queue<pair<int, int>>();
	q = queue<pair<int, int>>();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		Init();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '#') board[i][j] = -1; //벽
				else
				{
					if (ch == '*') // 불
					{
						fire[i][j] = 1;
						f.push({ i,j });
					}
					else if (ch == '@')
					{
						dist[i][j] = 1;
						q.push({ i,j });
					}
					board[i][j] = 0;
				}
			}
		}

		Fire();
		go();
	}

	return 0;
}
