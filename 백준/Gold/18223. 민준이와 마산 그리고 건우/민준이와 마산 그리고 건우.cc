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

vector<pii> graph[5001];
int dist[5001];

int Dijkstra(int start,int end)
{
	
	dist[start] = 0;
	priority_queue<pii>pq;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < cost) continue;
		// 시작점으로 했을 때 서로 다르면 굿바이임
		if (node == end)
		{
			return dist[end];
		}

		for (auto next : graph[node])
		{
			int nCost = cost + next.second;
			int nNode = next.first;

			if (dist[nNode] > nCost)
			{
				dist[nNode] = nCost;
				pq.push({ -nCost,nNode });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int gun;
	cin >> n >> m >> gun;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	fill(dist, dist + 5001, INF);
	int a = Dijkstra(1, n); // 그냥 쭉 갔을 때
	fill(dist, dist + 5001, INF);
	int b = Dijkstra(1, gun);
	fill(dist, dist + 5001, INF);
	int c = Dijkstra(gun, n);

	cout << (a == (b+c) ? "SAVE HIM" : "GOOD BYE");

	return 0;
}
