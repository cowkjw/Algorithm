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
#include <sstream>
#include <cstring>

using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hx[] = { -1,1,-2,2,-1,1 };
const int hy[] = { -2,-2,0,0,2,2 };

int dist[201][201];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	pii s, e;
	cin >> s.first >> s.second;
	cin >> e.first >> e.second;
	fill(&dist[0][0], &dist[200][200], -1);
	queue<pii>q;
	q.push(s);
	dist[s.first][s.second] = 0;
	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		if (x == e.second && y == e.first)
		{
			break;
		}
		for (int dir = 0; dir < 6; dir++)
		{
			int ny = hy[dir] + y;
			int nx = hx[dir] + x;
			if (nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
			if (dist[ny][nx] == -1)
			{
				dist[ny][nx] = dist[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	cout << dist[e.first][e.second];

	return 0;
}