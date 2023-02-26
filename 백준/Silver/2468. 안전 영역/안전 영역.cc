#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int board[102][102];
int vis[102][102];
int dx[4] = { -1,1,0,0 }; // 상 하 좌 우
int dy[4] = { 0,0,-1,1 };
int n, maxlimit, ans;



void BFS(int x, int y, int limit)
{
	queue<pair<int, int>> q;

	q.push({ x,y });
	vis[x][y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (vis[nx][ny] == 0 && board[nx][ny] > limit)
			{
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
		{
			cin >> board[x][y];
			maxlimit = max(board[x][y], maxlimit);
		}

	for (int limit = 0; limit <= maxlimit; limit++)
	{
		for (int i = 0; i < n; i++)
			fill(vis[i], vis[i] + n, 0);

		int cnt = 0;

		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
			{
				if (board[x][y] > limit && vis[x][y] == 0)
				{
					BFS(x, y, limit);
					cnt++;
				}
			}
		ans = max(cnt, ans);
	}

	cout << ans;


	return 0;


}
