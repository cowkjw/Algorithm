#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n, k;
int board[201][201];
int vis[201][201];
int s, x, y;
vector<pair<int, int>> delta{ {1,0},{-1,0},{0,1},{0,-1} };
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	priority_queue<tuple<int,int, int>> pq;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j]) pq.push({-board[i][j], i,j}); // 바이러스 위치를 전부 큐에 삽입
		}
	}

	cin >> s >> x >> y;
	int t = 0;
	priority_queue<tuple<int, int, int>> tmp;
	while (!pq.empty()&& t<s)
	{
		tmp = pq;
		pq = priority_queue<tuple<int, int, int>>();
		while (!tmp.empty())
		{
			int virus, Y, X;
			tie(virus, Y, X) = tmp.top();
			virus *= -1;
			tmp.pop();

			for (const auto& dir : delta)
			{
				int ny = Y + dir.first;
				int nx = X + dir.second;

				if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
				if (board[ny][nx] == 0)
				{
					board[ny][nx] = virus;
					pq.push({ -virus,ny,nx });
				}
			}
		}
		t++;
	}


	cout << board[x-1][y-1];
	return 0;
}