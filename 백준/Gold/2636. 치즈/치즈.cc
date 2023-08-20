#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int vis[101][101];
vector<pair<int, int>> dir {{1, 0}, { 0,1 }, { -1,0 }, { 0,-1 }};
int board[101][101];
int n, m;

vector<pair<int, int>> cheese;

void go(int x, int y)
{
	vis[x][y] = 1;
	if (board[x][y] == 1)
	{
		cheese.push_back({ x,y });
		return;
	}

	for (const auto& di : dir)
	{
		int nx = x + di.first;
		int ny = y + di.second;

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (vis[nx][ny]) continue;
		go(nx, ny);
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int totalT = 0;
	int cnt = 0;

	while (true)
	{
		fill(&vis[0][0], &vis[0][0] + 101 * 101, 0);
		cheese.clear();
		go(0, 0);
		cnt = cheese.size();

		for (auto c : cheese) board[c.first][c.second] = 0;

		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] != 0) flag = true;
			}
		}
		totalT++;
		if (!flag) break;
	}
	cout << totalT << "\n" << cnt;
	return 0;
}