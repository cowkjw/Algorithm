#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> dir{ {1, 0}, { 0,1 }, { -1,0 }, { 0,-1 } };
int r, c, k;
char board[6][6];
int vis[6][6];
int ret;

void go(int x, int y, int cnt)
{
	if (x == 0 && y == c - 1)
	{
		if (cnt == k)
			ret++;
		return;
	}

	for (const auto di : dir)
	{
		int nx = x + di.first;
		int ny = y + di.second;
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (vis[nx][ny] || board[nx][ny] == 'T') continue;
		vis[nx][ny] = 1;
		go(nx, ny, cnt + 1);
		vis[nx][ny] = 0;
	}
}

pair<int, int> start, home;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}
	int x = r - 1;
	int y = 0;
	vis[x][y] = 1;
	go(x, y, 1);

	cout << ret;

	return 0;
}