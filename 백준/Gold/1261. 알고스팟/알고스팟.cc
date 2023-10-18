#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, m;
int board[101][101];
int dist[101][101];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };

void go()
{
	priority_queue<pair<int, pair<int, int>>> pq; // cost x,y

	pq.push({ 0,{0,0} });
	dist[0][0] = 0;

	while (!pq.empty())
	{
		auto cur = pq.top();
		int cost = -cur.first;
		int x = cur.second.first;
		int y = cur.second.second;
		pq.pop();

		if (dist[x][y] < cost) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			int nCost = cost + board[nx][ny];
			if (dist[nx][ny] > nCost)
			{
				dist[nx][ny] = nCost;
				pq.push({ -nCost,{nx,ny} });
			}
		}
	}
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &board[i][j]);
			dist[i][j] = INF;
		}
	}

	go();

	cout << dist[n - 1][m - 1];

	return 0;
}
