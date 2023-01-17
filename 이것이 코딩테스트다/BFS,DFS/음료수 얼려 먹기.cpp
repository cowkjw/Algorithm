#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321

using namespace std;



vector<pair<int, int>> del{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int ans = 0;

	vector<string> iceBoard(n);
	vector < vector<bool>> vis(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
	{
		cin >> iceBoard[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (vis[i][j] || iceBoard[i][j] == '1') continue;

			queue<pair<int, int>>  q;
			vis[i][j] = true;
			q.push({ i,j });

			ans++;
			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					int nx = cur.first + del[i].first;
					int ny = cur.second + del[i].second;

					if (nx < 0 || nx >= n || ny < 0 || ny >= m || (iceBoard[nx][ny] == '1') || vis[nx][ny]) continue;

					if (iceBoard[nx][ny] == '0')
					{
						vis[nx][ny] = true;
						q.push({ nx,ny });
					}

				}
			}
		}
	}

	cout << ans;


	return 0;
}



