#include <bits/stdc++.h>
#define INF 987654321
#define X first 
#define Y second

using namespace std;

vector<pair<int, int>> del{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };
int n, k, s, x, y;
int board[201][201];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<queue<pair<int, int>>> virus(k+1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
			{
				virus[board[i][j]].push({ i,j });
			}
		}
	}

	cin >> s >> x >> y;// s 시간

	while (s--)
	{
		for (int i = 1; i <= k; i++)
		{
			int size = virus[i].size();
			while (size--)
			{
				auto cur = virus[i].front();
				virus[i].pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = del[dir].X + cur.X;
					int ny = del[dir].Y + cur.Y;

					if (nx > 0 && nx <= n && ny > 0 && ny <= n && board[nx][ny] == 0)
					{
						board[nx][ny] = i;
						virus[i].push({ nx,ny });
					}
				}
			}
		}
	}
	cout << board[x][y];
	return 0;
}