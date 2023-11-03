#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

const vector<pair<int, int>> dir{ {-1,0} ,{0,1} ,{1,0} ,{0,-1} }; // 북 동 남 서

int n, m;
// 0 북 1 동 2 남 3 서

int vis[301][301];
int board[301][301];
queue<pair<int, int>> q;
vector<pair<int, int>> v;

void BFS()
{
	queue<pair<int, int>> temp = q;
	q = queue<pair<int, int>>();
	int tBoard[301][301];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tBoard[i][j] = board[i][j];
		}
	}
	while (!temp.empty())
	{
		int x, y;
		tie(x, y) = temp.front();
		temp.pop();
		int cnt = 0;
		for (const auto& di : dir)
		{
			int nx = di.first + x;
			int ny = di.second + y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (tBoard[nx][ny] == 0) cnt++;
		}
		board[x][y] = max(board[x][y] - cnt, 0);
		if (board[x][y] > 0) q.push({ x,y }), v.push_back({ x,y });
	}
}

bool Check()
{
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (vis[v[i].first][v[i].second]) continue;
		queue<pair<int, int>> q1;
		cnt++;
		q1.push({ v[i].first,v[i].second });
		vis[v[i].first][v[i].second] = 1;
		while (!q1.empty())
		{
			int x, y;
			tie(x, y) = q1.front();
			q1.pop();

			for (const auto& di : dir)
			{
				int nx = di.first + x;
				int ny = di.second + y;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 0 || vis[nx][ny]) continue;
				q1.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}

	}
	return cnt >= 2;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j]) q.push({ i,j });
		}
	}
	int ret = 0;
	while (1)
	{
		ret++;
		BFS();
        if (v.size() == 0)
		{
			cout << 0;
			return 0;
		}
		if (Check()) break;
		memset(vis, 0, sizeof(vis));
		v.clear();
	}
	cout << ret;
	return 0;
}


