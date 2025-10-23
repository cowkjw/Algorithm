#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };

int board[301][301];
int dist[301][301][31]; // x,y,k남은횟수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	cin >> m >> n;
	pii start{ 0,0 }, end{ n - 1,m - 1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int l = 0; l <= k; l++)
				dist[i][j][l] = INF;
		}
	}
	// pair<pair<int,int>,int>> 좌표, k남은횟수
	queue<pair<pii, int>> q;
	dist[start.first][start.second][k] = 0; 
	q.push({ start, k });
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curK = q.front().second;

		q.pop();
		if (curK > 0)
		{
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = x + hDx[dir];
				int ny = y + hDy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == 1) continue; // 벽
				if (dist[nx][ny][curK - 1] > dist[x][y][curK] + 1)
				{
					dist[nx][ny][curK - 1] = dist[x][y][curK] + 1;
					q.push({ {nx,ny},curK - 1 });
				}
			}
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 1) continue; // 벽
			if (dist[nx][ny][curK] > dist[x][y][curK] + 1)
			{
				dist[nx][ny][curK] = dist[x][y][curK] + 1;
				q.push({ {nx,ny},curK });
			}
		}
	}

	int ans = INF;
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dist[end.first][end.second][i]);
	}
	if (ans == INF) cout << -1;
	else cout << ans;


	return 0;
}