#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int n, m;
int board[9][9];
int dx[]{ -1,0,1,0 };
int dy[]{ 0,1,0,-1 };
vector<pair<int, int>> v;
int ret = INF;


vector<pair<int, int>>  CCTV(int here, int dir)
{
	vector<pair<int, int>> change;

	int x = v[here].first;
	int y = v[here].second;

	if (board[x][y] == 1)
	{
		while (1)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != 6)
			{
				if (board[nx][ny] == 0)
				{
					board[nx][ny] = 8;
					change.push_back({ nx,ny });
				}
				x = nx;
				y = ny;
			}
			else break;
		}
	}
	else if (board[x][y] == 2)
	{
		for (int i = 0; i <= 2; i += 2)
		{
			int _x = x;
			int _y = y;
			while (1)
			{
				int nx = _x + dx[(dir + i) % 4];
				int ny = _y + dy[(dir + i) % 4];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != 6)
				{
					if (board[nx][ny] == 0)
					{
						board[nx][ny] = 8;
						change.push_back({ nx,ny });
					}
						_x = nx;
						_y = ny;
				}
				else break;
			}
		}
	}
	else if (board[x][y] == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			int _x = x;
			int _y = y;
			while (1)
			{
				int nx = _x + dx[(dir + i) % 4];
				int ny = _y + dy[(dir + i) % 4];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != 6)
				{
					if (board[nx][ny] == 0)
					{
						board[nx][ny] = 8;
						change.push_back({ nx,ny });
					}
						_x = nx;
						_y = ny;
				}
				else break;
			}
		}
	}
	else if (board[x][y] == 4)
	{
		for (int i = 0; i < 3; i++)
		{
			int _x = x;
			int _y = y;
			while (1)
			{
				int nx = _x + dx[(dir + i) % 4];
				int ny = _y + dy[(dir + i) % 4];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != 6)
				{
					if (board[nx][ny] == 0)
					{
						board[nx][ny] = 8;
						change.push_back({ nx,ny });
					}
						_x = nx;
						_y = ny;
				}
				else break;
			}
		}
	}
	else if (board[x][y] == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			int _x = x;
			int _y = y;

			while (1)
			{
				int nx = dx[(dir + i) % 4] + _x;
				int ny = dy[(dir + i) % 4] + _y;

				if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != 6)
				{
					if (board[nx][ny] == 0)
					{
					board[nx][ny] = 8;
					change.push_back({ nx,ny });
					}
					_x = nx;
					_y = ny;
				}
				else break;
			}
		}
	}
	return change;
}
int Check()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0) cnt++;
		}
	}

	return cnt;
}
void go(int here)
{
	if (here == v.size())
	{
		ret = min(Check(), ret);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		vector<pair<int, int>> change = CCTV(here, i);
		go(here + 1);
		for (auto i : change) board[i.first][i.second] = 0;// 원래 0이었던 곳으로 변환
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) v.push_back({ i,j });
		}
	}

	go(0);

	cout << ret;

	return 0;
}


