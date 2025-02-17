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
int tc, n, m, w;

struct Edge
{
	int u, v;
	int weight;
};
vector<Edge> edges;
int dist[501];
bool BellmanFord()
{
	dist[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <(int) edges.size(); j++)
		{
			int from = edges[j].u;
			int to = edges[j].v;
			int cost = edges[j].weight;

			// 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우 
			if (dist[to] > dist[from] + cost) 
			{
				dist[to] = dist[from] + cost; // 최단 거리 테이블 갱신 

				// n번째에도 최단 거리가 갱신된다면 음수 사이클 존재
				if (i == n) return true;
			}
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> tc;
	while (tc--)
	{
		edges.clear();
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}
		fill(dist, dist+501, INF);
		bool cycle = BellmanFord();

		cout << (cycle ? "YES" : "NO") << "\n";
	}
	return 0;
}