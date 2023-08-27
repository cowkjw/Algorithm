#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> dir{ {1, 0}, { 0,1 }, { -1,0 }, { 0,-1 } };

char board[1001][1001];
int vis[1001][1001];
int fireVis[1001][1001];
int n, m, ans;
pair<int, int> hon;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	fill(&fireVis[0][0], &fireVis[0][0] + 1001 * 1001, INF);
	queue<pair<int, int>>q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'J') hon = { i,j };
			else if (board[i][j] == 'F')
			{
				fireVis[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) // 불 체크
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (const auto& di : dir)
		{
			int nx = di.first + x;
			int ny = di.second + y;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (fireVis[nx][ny]!=INF||board[nx][ny] == '#') continue;

			fireVis[nx][ny] = fireVis[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	vis[hon.first][hon.second] = 1;
	q.push(hon);

	while (!q.empty()) // 지훈 체크
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		if (x == n - 1 || y == m - 1 || x == 0 || y == 0) // 가장 자리
		{
			ans = vis[x][y];
			break;
		}

		for (const auto& di : dir)
		{
			int nx = di.first + x;
			int ny = di.second + y;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny]||board[nx][ny] == '#') continue;
			if (fireVis[nx][ny] <= vis[x][y] + 1) continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	if (ans == 0) cout << "IMPOSSIBLE";
	else cout << ans;
}
