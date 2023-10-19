#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, t;
vector<vector<int>> v;
int vis[301][301];
int dx[]{ 1,2,2,1,-1,-2,-2,-1 };
int dy[]{ -2,-1,1,2,2,1,-1,-2 };
int sx, sy, ex, ey;
int ret;
void Init()
{
	memset(vis, 0, sizeof(vis));
	ret = 0;
}

void go(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	vis[x][y] = 1;

	while (!q.empty())
	{
		int a, b;
		tie(a, b) = q.front();
		q.pop();
		if (a == ex && b == ey)
		{
			ret = vis[a][b];
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;

			vis[nx][ny] = vis[a][b] + 1;
			q.push({ nx,ny });
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		Init();
		cin >> n;
		cin >> sx >> sy;
		cin >> ex >> ey;
		go(sx, sy);
		cout << ret-1 << '\n';
	}
	return 0;
}
