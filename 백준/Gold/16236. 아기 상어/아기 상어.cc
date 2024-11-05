#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<cstring>
using namespace std;



const vector<pair<int, int>> delta{ {1,0},{0,-1} ,{-1,0},{0,1} };
int n;
int dist[21][21];
int board[21][21];
int main()
{

	// 처음 크기는 2부터 시작
	// 상어는 1초마다 상하좌우로 이동 배열을 3차원으로?
	// 자기보다 작은 경우만 먹을 수 있음
	// 같으면 먹을 순 없고 지나는 갈 수 있음

	// 먹을 수 없으면 엄마 상어, 먹을 수 있는 고기가 있으면 그 물고기를 먹으러 간다
	// 먹을 수 있는 고기가 많으면 거리가 가장 가까운 애를 찾는다
	// 거리가 가까운 물고기가 많으면 

	cin >> n;
	pair<int, int> sharkPos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				board[i][j] = 0;
				sharkPos = { i,j };
			}
		}
	}

	int size = 2, cnt = 0, ans = 0;

	vector<pair<int, int>> fishes;
	while (true)
	{
		memset(dist, 0, sizeof(dist));
		queue<pair<int, int>> q;
		q.push({ sharkPos });
		dist[sharkPos.first][sharkPos.second] = 0;// 상어
		while (!q.empty())
		{
			int y, x;
			tie(y, x) = q.front();

			q.pop();
			for (const auto& d : delta)
			{
				int ny = y + d.first;
				int nx = x + d.second;

				if (nx < 0 || ny < 0 || ny >= n || nx >= n || dist[ny][nx] != 0) continue;
				if (board[ny][nx] > size) continue; // 사이즈가 큰 경우
				dist[ny][nx] = dist[y][x] + 1;
				if (board[ny][nx] < size && board[ny][nx] != 0) // 먹을 수 있는 경우
				{
					fishes.push_back({ ny,nx });
				}
				q.push({ ny,nx });
			}
		}

		if (fishes.empty())
		{
			cout << ans;
			return 0;
		}
		sort(fishes.begin(), fishes.end(), [&](const pair<int, int>& a, const pair<int, int>& b)
			{
				if (dist[a.first][a.second] == dist[b.first][b.second])
				{
					if (a.first == b.first) return a.second < b.second;
					return a.first < b.first;
				}
				return dist[a.first][a.second] < dist[b.first][b.second];
			});
		cnt++;

		if (cnt == size)
		{
			cnt = 0;
			size++;
		}

		sharkPos = fishes.front();
		board[sharkPos.first][sharkPos.second] = 0;
		ans += dist[sharkPos.first][sharkPos.second];
		fishes.clear();
	}

	return 0;
}