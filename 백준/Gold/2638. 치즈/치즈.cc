#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int parent[1001];
struct Edge
{
	int u, v, cost;
	bool operator<(const Edge& other) const
	{
		return cost < other.cost;
	}
};

int Find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u != v)
		parent[u] = v;
}

int n,m;
int board[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	vector<pair<int, int>> cheese;

	for (int i = 0; i < n; i++) // 세로
	{	for (int j = 0; j < m; j++) // 가로
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				cheese.emplace_back( i,j );
			}
		}
	}
	int time = 0;
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 2) board[i][j] = 0; // 공기에서 빈칸
			}
		}
		queue<pair<int, int>>q;
		q.push({ 0,0 });
		board[0][0] = 2;
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == 0) // 빈칸
				{
					board[nx][ny] = 2; // 공기
					q.push({ nx,ny });
				}
			}
		}
		vector<pair<int, int>> melt;
		for (auto [x, y] : cheese)
		{
			if (board[x][y] != 1) continue; // 이미 녹은 치즈
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == 2) cnt++; // 공기와 접촉
			}
			if (cnt >= 2) melt.emplace_back(x, y);
		}
		if (melt.empty()) // 더 이상 녹을 치즈가 없음
		{
			cout << time;
			break;
		}
		for (auto [x, y] : melt)
		{
			board[x][y] = 0; // 치즈 녹음
		}
		time++;
	}


	return 0;
}
