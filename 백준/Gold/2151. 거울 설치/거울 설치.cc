#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

struct Node {
	int y, x, dir, cost;
	bool operator<(const Node& other) const
	{
		return cost > other.cost;
	}
};
int n, m;

vector<string> board;
int dist[51][51][4];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}

	for (int i = 0; i <= 50; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				dist[i][j][k] = INF;
			}
		}
	}

	pii start{ -1,-1 }, end;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '#')
			{

				if (start.first != -1)
				{
					end = { i,j };
				}
				else
				{

					start = { i,j };
				}
			}
		}
	}

	priority_queue<Node> pq;

	for (int i = 0; i < 4; i++)
	{
		Node node{ start.first,start.second,i,0 };
		pq.push(node);
	}

	while (!pq.empty())
	{
		auto [y, x, dir, cost] = pq.top();
		pq.pop();
		if (dist[y][x][dir] < cost) continue;
		if (y == end.first && x == end.second)
		{
			cout << dist[y][x][dir];
			return 0;
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny >= 0 && nx >= 0 && nx < n && ny < n && board[ny][nx] != '*')
		{
			if (dist[ny][nx][dir] > cost)
			{
				dist[ny][nx][dir] = cost;
				pq.push({ ny,nx,dir,cost });
			}

			if (board[ny][nx] == '!')
			{
				int l, r;

				if (dir == 0) // 상
				{
					l = 2, r = 3;
				}
				else if (dir == 1) // 하
				{
					r = 3, l = 2;
				}
				else if(dir == 2) // 좌
				{
					l = 1, r = 0;
				}
				else //우
				{
					l = 0, r = 1;
				}

				if (dist[ny][nx][l] > cost + 1)
				{
					dist[ny][nx][l] = cost + 1;
					pq.push({ ny,nx,l,cost + 1 });
				}

				if (dist[ny][nx][r] > cost + 1)
				{
					dist[ny][nx][r] = cost + 1;
					pq.push({ ny,nx,r,cost + 1 });
				}
			}
		}

	}

	return 0;
}
