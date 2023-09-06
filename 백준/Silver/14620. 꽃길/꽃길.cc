#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
const vector<pair<int, int>> dir{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };

int vis[11][11];
int board[11][11];
int n;
int ret = INF;
bool check(int x, int y)
{
	if (vis[x][y]) return 0;
	for (const auto di : dir)
	{
		int nx = x + di.first;
		int ny = y + di.second;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny]) return 0;
	}

	return 1;
}

int SetFlower(int x,int y)
{
	vis[x][y] = 1;
	int s = board[x][y];
	for (const auto di : dir)
	{
		int nx = x + di.first;
		int ny = y + di.second;
		vis[nx][ny] = 1;
		s += board[nx][ny];
	}
	return s;
}

void EraseFlower(int x, int y)
{
	vis[x][y] = 0;
	for (const auto di : dir)
	{
		int nx = x + di.first;
		int ny = y + di.second;
		vis[nx][ny] = 0;
	}
	return;
}

void go(int cnt,int sum)
{
	if (cnt == 3)
	{
		ret = min(sum, ret); 
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j))
			{
				go(cnt + 1, sum + SetFlower(i, j));
				EraseFlower(i, j);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	go(0,0);

	cout << ret;
	return 0;
}
