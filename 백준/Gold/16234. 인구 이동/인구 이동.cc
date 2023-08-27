#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> dir{ {1, 0}, { 0,1 }, { -1,0 }, { 0,-1 } };

int board[51][51];
int vis[101][101];
int n, m, l, r;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int ans = 0;

	while (true)
	{
		memset(vis, 0, sizeof(vis));
		bool flag = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
                if (vis[i][j]) continue;
				vector<pair<int, int>> v{ {i,j} };
				queue<pair<int, int>> q;

				q.push({ i,j });
				vis[i][j] = 1;
				int p = board[i][j];

				while (!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (const auto& di : dir)
					{
						int nx = x + di.first;
						int ny = y + di.second;

						if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) continue;

						int diff = abs(board[nx][ny] - board[x][y]);// 인구 차이
						if (diff >= l && diff <= r)
						{
							vis[nx][ny] = 1;
							v.push_back({ nx,ny });
							q.push({ nx,ny });
							p += board[nx][ny];
						}
					}
				}
				if (v.size() != 1)
				{
					p = p / v.size();
					for (const auto& i : v)
					{
						board[i.first][i.second] = p;
					}
					flag = true;
				}
			}
		}
		if (!flag) break;
		ans++;
	}

	cout << ans;
}
