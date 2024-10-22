#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501];
int graph[501][501];
int n;
const int dx[]{ 1,-1,0,0 };
const int dy[]{ 0,0,1,-1 };

bool isVaild(int y, int x)
{
	return (x >= 0 && y >= 0 && x < n && y < n);
}

int Recur(int y, int x)
{
	if (dp[y][x] != 0) return dp[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isVaild(ny, nx))
		{
			if (graph[ny][nx] > graph[y][x])
			{
				dp[y][x] = max(dp[y][x], Recur(ny, nx) + 1); // 갔다 왔기 때문에 횟수를 더해줌
			}
		}
	}

	return dp[y][x];
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
			cin >> graph[i][j];
		}
	}
	int ans = 0;
	// 모든 점을 방문
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			ans = max(ans,Recur(y, x));
		}
	}

	cout << ans+1;
	return 0;
}