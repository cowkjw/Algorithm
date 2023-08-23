#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


vector<pair<int, int>> dir{ {1, 0}, { 0,1 }, { -1,0 }, { 0,-1 } };
vector<pair<int, int>> ground;


char board[101][101];
int dist[101][101];
int n, m, res;

void go(int x, int y)
{
	memset(dist, 0, sizeof(dist));
	queue<pair<int, int>>q;
	q.push({ x,y });
	dist[x][y] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (const auto& di : dir)
		{
			int nx = di.first + cur.first;
			int ny = di.second + cur.second;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 'W') continue;
			if (dist[nx][ny]) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
			res = max(res, dist[nx][ny]);
		}
	}

	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'L') ground.push_back({ i,j });
		}
	}
	for (const auto& i : ground)
	{
		go(i.first, i.second);
	}
	cout << res - 1;
}

