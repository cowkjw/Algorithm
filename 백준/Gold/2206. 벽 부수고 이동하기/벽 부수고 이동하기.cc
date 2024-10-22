#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
using namespace std;

const vector<pair<int, int>> delta{ {1,0},{-1,0},{0,1},{0,-1} };
int n, m;
int vis[1001][1001][2];
int dist[1001][1001][2];
vector<string> board(1001);

bool isValid(int y, int x)
{
	return(x >= 0 && y >= 0 && y < n && x < m);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			fill(dist[i][j], dist[i][j] + 2, -1); // 2차원에서 각 배열 초기화
		}
	}

	queue <tuple<int, int,int>>q;
	q.push({ 0,0,0 });
	vis[0][0][0] = 1;
	dist[0][0][0] = 1;

	while (!q.empty())
	{
		int y, x,isBroke;
		tie(y, x,isBroke) = q.front();
		q.pop();
		if (x== m-1  && y == n-1 ) 
		{
			cout << dist[y][x][isBroke];
			return 0;
		}
		for (const auto& d : delta)
		{
			int ny = d.first + y;
			int nx = d.second + x;

			if (!isValid(ny, nx)) continue;

			if (board[ny][nx] == '0' && !vis[ny][nx][isBroke])
			{
				vis[ny][nx][isBroke] = 1;
				dist[ny][nx][isBroke] = dist[y][x][isBroke] + 1;
				q.push({ ny, nx, isBroke }); // 현재 벽 부수기 여부 유지
			}
			else if (board[ny][nx] == '1' && !vis[ny][nx][1] && isBroke == 0)
			{
				vis[ny][nx][1] = 1; 
				dist[ny][nx][1] = dist[y][x][isBroke] + 1; // 거리 업데이트
				q.push({ ny, nx, 1 }); 
			}

		}
	}

	cout << -1;
	return 0;
}