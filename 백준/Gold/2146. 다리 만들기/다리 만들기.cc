#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int board[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j]; // 1이 바다

		}
	}
	int groupID = 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] != 1) continue;
			queue<pii>q;
			q.push({ i,j });
			board[i][j] = groupID;
			while (!q.empty())
			{
				auto [curX, curY] = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = curX + dx[dir];
					int ny = curY + dy[dir];
					if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
					if (board[nx][ny] != 1) continue;
					board[nx][ny] = groupID;
					q.push({ nx,ny });
				}
			}
			groupID++;
		}
	}
	// 그룹화 했으니까 이제 그룹끼리 다리 놓아서 최소비용

	int ans = INF;
	for (int group = 2; group <= groupID; group++) // 각 섬 그룹에 대해
	{
		queue<pii> q;
		vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));

		// 현재 그룹의 모든 칸을 시작점으로 설정
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= n; j++) 
			{
				if (board[i][j] == group)
				{
					q.push({ i, j });
					dist[i][j] = 0;
				}
			}
		}

		// BFS
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

				// 다른 섬에 도달
				if (board[nx][ny] != 0 && board[nx][ny] != group)
				{
					ans = min(ans, dist[x][y]);
					break;
				}

				// 바다만 이동 가능
				if (board[nx][ny] == 0 && dist[nx][ny] == -1) 
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	cout << ans;


	return 0;
}