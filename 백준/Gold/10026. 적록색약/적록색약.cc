#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n;
vector<vector<int>> v;
int dp[1001];
char board[101][101];
int vis[101][101];
int ret1, ret2;
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
void go(int x, int y, char color ,bool flag = false)// true 적록
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = 1;

	if (flag) // 적록
	{
		if (color == 'B')
		{
			while (!q.empty())
			{
				int a, b;
				tie(a, b) = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = a + dx[i];
					int ny = b + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;
					if (board[nx][ny] != 'B') continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
		else
		{
			while (!q.empty())
			{
				int a, b;
				tie(a, b) = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = a + dx[i];
					int ny = b + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;
					if (board[nx][ny] == 'B') continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	else
	{
		while (!q.empty())
		{
			int a, b;
			tie(a, b) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = a + dx[i];
				int ny = b + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;
				if (board[nx][ny] != color) continue;
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
}

void Init()
{
	memset(vis, 0, sizeof(vis));
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j])continue;
			go(i, j, board[i][j], false);
			ret1++;
		}
	}

	Init();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j])continue;
			go(i, j, board[i][j], true);
			ret2++;
		}
	}

	cout << ret1 << " " << ret2;

	return 0;
}
