#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501];
int graph[501][501];
int n,m;
const int dx[]{ 1,-1,0,0 };
const int dy[]{ 0,0,1,-1 };

bool isVaild(int y, int x)
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

int Recur(int y, int x)
{
	if (y == n - 1 && x == m - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];
	int route = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isVaild(ny, nx))
		{
			if (graph[ny][nx] < graph[y][x])
			{
				route += Recur(ny, nx);
			}
		}
	}
	dp[y][x] = route;

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = -1;
		}
	}

	Recur(0, 0);
	cout << dp[0][0];
	return 0;
}